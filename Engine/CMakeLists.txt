add_library(Neonix SHARED
    Core/Application.cpp
    Core/Application.hpp
    Core/Window.cpp
    Core/Window.hpp
    Core/Input.cpp
    Core/Input.hpp    

    Utils/FileUtils.hpp

        Graphics/Mesh.cpp
        Graphics/Mesh.hpp
    Graphics/Renderer.hpp
    Graphics/Renderer.cpp
    Graphics/Shapes.hpp
    Graphics/Layer.hpp
    Graphics/Shader.cpp
    Graphics/Shader.hpp
    Graphics/Material.hpp
    Graphics/Material.cpp
    Graphics/Texture.hpp
    Graphics/Texture.cpp
    Graphics/Camera.cpp
    Graphics/Camera.hpp

    # stb
    ${CMAKE_SOURCE_DIR}/Vendor/stb/stb_image_loader.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/Vendor/stb
)

target_link_libraries(Neonix PUBLIC glfw GLEW OpenGL)