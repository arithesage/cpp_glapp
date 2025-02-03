#ifndef __SHADING_MACHINE__
#define __SHADING_MACHINE__

#include <Common.hpp>


class ShadingMachine
{
    private:
        static ShadingMachine* __instance;

        ShadingMachine ();
        ~ShadingMachine ();

    public:
        static ShadingMachine* Get ();
        static void Shutdown ();
};


#endif
