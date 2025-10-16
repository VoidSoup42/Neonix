cmake_minimum_required(VERSION 3.10.0)
project(Neonnix VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(
    ${OPENGL_INCLUDE_DIRS}
)

add_executable(Neonix
    Source/Main.cpp
    Source/Core/Window.cpp
    Source/Core/Window.hpp
    Source/Core/Input.cpp
    Source/Core/Input.hpp
    
    Source/Utils/FileUtils.cpp
    Source/Utils/FileUtils.hpp

    Source/Graphics/Renderable.cpp
    Source/Graphics/Renderable.hpp
    Source/Graphics/SimpleRenderer.hpp
    Source/Graphics/SimpleRenderer.cpp
    Source/Graphics/Renderer.hpp
    Source/Graphics/Renderer.cpp
    Source/Graphics/Shader.cpp
    Source/Graphics/Shader.hpp

)

target_link_libraries(Neonix PRIVATE glfw GLEW OpenGL::GL)
