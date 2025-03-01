include Project.mk


EXEC							:= ${PROJECT_NAME}

ifneq (${WINDIR},)
	SYSTEM						:= windows
	EXEC						:= ${EXEC}.exe
else
	UNAME						:= $(shell uname)

	ifeq (${UNAME},Darwin)
		SYSTEM					:= macos
	else ifeq (${UNAME},Linux)
		SYSTEM					:= linux
	else
		SYSTEM					:= other
	endif
endif

SRC								:= src
BUILD							:= build
OBJ								:= obj

OBJ_PATH						:= ${OBJ}/${SYSTEM}
BUILD_PATH						:= ${BUILD}/${SYSTEM}

EXEC							:= ${BUILD}/${SYSTEM}/${EXEC}


include Functions.mk

C_MAIN							:= $(shell find ${SRC}/** -type f -name "main.c")
CPP_MAIN						:= $(shell find ${SRC}/** -type f -name "main.cpp")

ifneq (${C_MAIN},)
	MAIN						:= ${C_MAIN}
else
	MAIN						:= ${CPP_MAIN}
endif

MAIN_FILE						:= $(notdir ${MAIN})
MAIN_OBJ						:= ${OBJ_PATH}/$(call SRC2OBJ,${MAIN_FILE})

C_SRCS							:= $(shell find ${SRC}/** -type f -name "*.c" -not -name "main.c")
CPP_SRCS						:= $(shell find ${SRC}/** -type f -name "*.cpp" -not -name "main.cpp")

C_HEADERS						:= $(shell find ${SRC}/** -type f -name "*.h")
CPP_HEADERS						:= $(shell find ${SRC}/** -type f -name "*.hpp")

SRCS							:= $(strip ${C_SRCS} ${CPP_SRCS})
HEADERS							:= $(strip $(C_HEADERS) ${CPP_HEADERS})
OBJS							:= $(foreach src,${SRCS},$(call SRC2OBJ,${src}))

INCLUDE_PATHS					:= $(sort $(foreach file,${HEADERS},$(dir ${file})))

INCLUDE							:= $(strip $(foreach inc,${INCLUDE_PATHS},-I ${inc}))
LIBS							:= $(foreach lib,${LIBS},-l${lib})

ifeq (${C},)
	C							:= clang
endif

ifeq (${CXX},)
	CXX							:= clang++
endif




.PHONY: all clean info run


all: ${OBJ_PATH} ${BUILD_PATH} ${EXEC}


clean:
	rm -r ${OBJ}
	rm -r ${BUILD}
	rm ${EXEC}


${BUILD_PATH}:
	mkdir -p ${BUILD_PATH}


${OBJ_PATH}:
	mkdir -p ${OBJ_PATH}


# Builds the executable
${EXEC}: ${OBJS} ${MAIN_OBJ}
ifeq (${MAIN_FILE},main.c)
	${C} ${LIBS} ${OBJS} ${MAIN_OBJ} -o ${EXEC}
else
	${CXX} ${LIBS} ${OBJS} ${MAIN_OBJ} -o ${EXEC}
endif


# Builds the main object
${MAIN_OBJ}: ${MAIN}
ifeq (${MAIN_FILE},main.c)
	${C} -c ${MAIN} -o ${MAIN_OBJ} ${INCLUDE} ${CFLAGS}
else
	${CXX} -c ${MAIN} -o ${MAIN_OBJ} ${INCLUDE} ${CXXFLAGS}
endif


# Builds all C files mirroring their folder tree
${OBJ_PATH}/%.o: ${SRC}/%.c
	$(shell mkdir -p $(dir $@))
	${C} -c $< -o $@ ${INCLUDE} ${CFLAGS}


# Builds all CPP files mirroring their folder tree
${OBJ_PATH}/%.o: ${SRC}/%.cpp
	$(shell mkdir -p $(dir $@))
	${CXX} -c $< -o $@ ${INCLUDE} ${CXXFLAGS}


# Old recipes for creating custom recipes for every file.
# They didn't work as expected though they should have done.
#$(foreach src,${C_SRCS},$(call C_COMPILE,${src},$(call SRC2OBJ,${src})))


#$(foreach src,${CPP_SRCS},$(call CXX_COMPILE,${src},$(call SRC2OBJ,${src})))


info:
	$(info PROJECT_NAME: ${PROJECT_NAME})
	$(info EXEC: ${EXEC})
	$(info SYSTEM: ${SYSTEM})
	$(info MAIN: ${MAIN})
	$(info MAIN_FILE: ${MAIN_FILE})
	$(info MAIN_OBJ: ${MAIN_OBJ})
	$(info C_SRCS: ${C_SRCS})
	$(info CPP_SRCS: ${CPP_SRCS})
	$(info C_HEADERS: ${C_HEADERS})
	$(info CPP_HEADERS: ${CPP_HEADERS})
	$(info SRCS: ${SRCS})
	$(info OBJS: ${OBJS})
	$(info INCLUDED_PATHS: ${INCLUDE})
	$(info LIBS: ${LIBS})


run:
ifeq (${SYSTEM},windows)
	${EXEC}
else
	./${EXEC}
endif
