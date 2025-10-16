#include "Input.hpp"
#include <iostream>

namespace Neonix
{
    bool Input::s_keys[MAX_KEYS] = { false };
    bool Input::s_mouseButtons[MAX_BUTTONS] = { false };
    double Input::s_mouseX = 0.0;
    double Input::s_mouseY = 0.0;

    void Input::Init(GLFWwindow* window)
    {
        glfwSetKeyCallback(window, KeyCallback);
        glfwSetMouseButtonCallback(window, MouseButtonCallback);
        glfwSetCursorPosCallback(window, CursorPositionCallback);
    }

    bool Input::IsKeyPressed(uint32_t keycode)
    {
        if (keycode >= MAX_KEYS)
            return false;
        return s_keys[keycode];
    }

    bool Input::IsMouseButtonPressed(uint32_t button)
    {
        if (button >= MAX_BUTTONS)
            return false;
        return s_mouseButtons[button];
    }

    void Input::GetMousePosition(double& x, double& y)
    {
        x = s_mouseX;
        y = s_mouseY;
    }

    void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key >= 0 && key < MAX_KEYS)
            s_keys[key] = (action != GLFW_RELEASE);

        if (action == GLFW_PRESS)
            std::cout << "Key Pressed: " << key << std::endl;
    }

    void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        if (button >= 0 && button < MAX_BUTTONS)
            s_mouseButtons[button] = (action != GLFW_RELEASE);
    }

    void Input::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
    {
        s_mouseX = xpos;
        s_mouseY = ypos;
    }
}
