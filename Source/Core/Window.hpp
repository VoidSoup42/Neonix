#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Input.hpp"

namespace Neonix
{
    class Window
    {
    public:
        Window(const char* title, uint32_t width, uint32_t height);
        ~Window();

        void ClearColor(glm::vec4 color);
        void Clear();
        void Update();
        bool ShouldClose();

        inline uint32_t GetWidth() const { return m_width; }
        inline uint32_t GetHeight() const { return m_height; }

    private:
        GLFWwindow* m_window;
        uint32_t m_width;
        uint32_t m_height;
        const char* m_title;

        static void WindowResizeCallBack(GLFWwindow* window, int width, int height);;
    };
}
