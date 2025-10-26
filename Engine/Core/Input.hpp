#pragma once
#include <GLFW/glfw3.h>
#include <cstdint>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace Neonix
{
    class Input
    {
    public:
        static void Init(GLFWwindow* window);

        static bool IsKeyPressed(uint32_t keycode);
        static bool IsMouseButtonPressed(uint32_t button);
        static void GetMousePosition(double& x, double& y);
        static void SetCursorMode(bool enabled);

        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

    private:
        static bool s_keys[MAX_KEYS];
        static bool s_mouseButtons[MAX_BUTTONS];
        static double s_mouseX;
        static double s_mouseY;
        static GLFWwindow* s_window;
    };
}
