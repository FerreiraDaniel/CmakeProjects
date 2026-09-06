cmake_minimum_required(VERSION 3.16)

# Set project name and version
project(MinimalOpenGLProject VERSION 1.0 LANGUAGES CXX)

# Find the OpenGL package
find_package(OpenGL REQUIRED)

# Find GLFW
find_package(glfw3 CONFIG REQUIRED)

# Find GLEW
find_package(GLEW REQUIRED)

# Copy shader files to the build directory
file(COPY src/shader.vs src/shader.fs DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Add source files
add_executable(hello_triangle src/main.cpp)

target_compile_definitions(hello_triangle
    PRIVATE
    SHADER_DIR="${CMAKE_CURRENT_BINARY_DIR}"
)

# Link libraries
target_link_libraries(hello_triangle
    PRIVATE
    OpenGL::GL
    GLEW::GLEW
    glfw
)

# Add custom target for cleaning shader files
add_custom_target(clean_shaders
    COMMAND ${CMAKE_COMMAND} -E remove
        ${CMAKE_CURRENT_BINARY_DIR}/shader.vs
        ${CMAKE_CURRENT_BINARY_DIR}/shader.fs
    COMMENT "Removing shader files"
)
