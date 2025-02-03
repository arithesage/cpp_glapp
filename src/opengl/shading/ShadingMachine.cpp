#include <ShadingMachine.hpp>


ShadingMachine* ShadingMachine::__instance = nullptr;


ShadingMachine::ShadingMachine ()
{
    log_i << "ShadingMachine initialized.\n";
}


ShadingMachine::~ShadingMachine ()
{
    log_i << "ShadingMachine destroyed.\n";
}


ShadingMachine* ShadingMachine::Get ()
{
    if (__instance == nullptr)
    {
        __instance = new ShadingMachine ();
    }

    return __instance;
}


void ShadingMachine::Shutdown ()
{    
    delete __instance;
}

