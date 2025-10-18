add_library(Neonix SHARED
    Core/Application.cpp
    Core/Application.hpp
    Core/Window.cpp
    Core/Window.hpp
    Core/Input.cpp
    Core/Input.hpp    

    Utils/FileUtils.cpp
    Utils/FileUtils.hpp
    
    Graphics/Renderable.cpp
    Graphics/Renderable.hpp
    Graphics/Renderer.hpp
    Graphics/Renderer.cpp
    Graphics/Shapes.hpp
    Graphics/Layer.hpp
    Graphics/Shader.cpp
    Graphics/Shader.hpp
    Graphics/Camera.cpp
    Graphics/Camera.hpp
)

target_link_libraries(Neonix PUBLIC glfw GLEW OpenGL)