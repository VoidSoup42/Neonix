#include "Window.hpp"
#include "Input.hpp"
#include <iostream>

namespace Neonix
{
    Window::Window(const char *title, uint32_t width, uint32_t height) : m_title(title), m_width(width), m_height(height)
    {
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
        if (!m_window)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(0);

        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowSizeCallback(m_window, WindowResizeCallBack);
        Input::Init(m_window);

        glewInit();

        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

        glViewport(0, 0, m_width, m_height);
        glEnable(GL_DEPTH_TEST);
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Window::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::Update()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    bool Window::ShouldClose()
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::WindowResizeCallBack(GLFWwindow* window, int width, int height)
    {
        Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
        glViewport(0, 0, width, height);
        win->m_width = (uint32_t)width;
        win->m_height = (uint32_t)height;
    }
}
