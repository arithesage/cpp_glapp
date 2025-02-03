#include <GLApp.hpp>


class TestApp : public GLApp
{
    public:
        TestApp () : GLApp ()
        {
            log_i << "";
        }


        ~TestApp ()
        {
            log_i << "Terminated.\n";
        }
};


int main ()
{
    TestApp app;

    if (!app.Ready())
    {
        return 1;
    }

    return 0;
}
