#ifndef __GLAPP__
#define __GLAPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Common.hpp>
#include <ShadingMachine.hpp>


class GLApp
{
    private:
        ShadingMachine* shadingMachine = nullptr;

    protected:
        bool _ready = false;

    public:
        GLApp ();
        ~GLApp ();

        bool Ready ();
};

#endif
