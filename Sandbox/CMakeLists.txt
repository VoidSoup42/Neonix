add_executable(Sandbox
    Main.cpp
    Sandbox.hpp
    Sandbox.cpp
)

target_include_directories(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/Engine)

target_link_libraries(Sandbox PRIVATE Neonix)