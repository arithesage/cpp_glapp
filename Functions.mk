# ${1}: Source file
# ${2}: Object file to generate
# ${3}: Extra flags

define C_COMPILE
${2}: ${1}
	$(shell mkdir -p $(dir ${2}))
	${C} -c ${1} -o ${2} ${CFLAGS} ${3}
endef


define CXX_COMPILE
${2}: ${1}
	$(shell mkdir -p $(dir ${2}))
	${CXX} -c ${1} -o ${2} ${CXXFLAGS} ${3}
endef


# ${1}: Source file
define SRC2OBJ
$(subst .c,.o,$(subst .cpp,.o,$(subst src,${OBJ_PATH},${1})))
endef
