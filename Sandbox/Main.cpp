#include "Core/Application.hpp"
#include "Sandbox.hpp"

int main()
{
    Neonix::ApplicationProps appProps;
    appProps.title = "My App";
    appProps.windowSizeX = 1600;
    appProps.windowSizeY = 900;
    appProps.vSync = true;

    Neonix::Application app(appProps);
    app.PushLayer<Sandbox>();
    app.Run();

    return 0;
}