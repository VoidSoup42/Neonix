add_library(Neonix SHARED
    Core/Application.cpp
    Core/Application.hpp
    Core/Window.cpp
    Core/Window.hpp
    Core/Input.cpp
    Core/Input.hpp    

    Utils/FileUtils.hpp
    # Utils/ModelLoader.hpp
    # Utils/ModelLoader.cpp

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

    ${CMAKE_SOURCE_DIR}/Vendor/stb/stb_image_loader.cpp    # stb
)

include_directories(
    ${CMAKE_SOURCE_DIR}/Vendor/stb/
    ${CMAKE_SOURCE_DIR}/Vendor/OBJ-Loader/
)

target_link_libraries(Neonix PUBLIC glfw GLEW OpenGL)