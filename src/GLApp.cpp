#include <GLApp.hpp>


GLApp::GLApp ()
{
    if (!glfwInit ())
    {
        log_e << "OpenGL app failed initializing.\n\n";
    }
    else
    {
        log_i << "OpenGL app initialized.\n";

        shadingMachine = ShadingMachine::Get ();

        _ready = true;
    }
}


GLApp::~GLApp ()
{
    if (shadingMachine != nullptr) {
        ShadingMachine::Shutdown ();
    }

    glfwTerminate();
}


bool GLApp::Ready ()
{
    return _ready;
}
