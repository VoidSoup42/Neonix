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
    Engine/Main.cpp
    Engine/TestLayer.hpp

    Engine/Core/Application.cpp
    Engine/Core/Application.hpp
    Engine/Core/Window.cpp
    Engine/Core/Window.hpp
    Engine/Core/Input.cpp
    Engine/Core/Input.hpp    

    Engine/Utils/FileUtils.cpp
    Engine/Utils/FileUtils.hpp
    
    Engine/Graphics/Renderable.cpp
    Engine/Graphics/Renderable.hpp
    Engine/Graphics/Renderer.hpp
    Engine/Graphics/Renderer.cpp
    Engine/Graphics/Shapes.hpp
    Engine/Graphics/Layer.hpp
    Engine/Graphics/Shader.cpp
    Engine/Graphics/Shader.hpp

)

target_link_libraries(Neonix PRIVATE glfw GLEW OpenGL::GL)
