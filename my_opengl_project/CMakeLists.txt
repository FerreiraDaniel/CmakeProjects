cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(MinimalOpenGLProject VERSION 1.0)

# Find the OpenGL package
find_package(OpenGL REQUIRED)

# Find GLFW
find_package(GLFW3 REQUIRED)

# Find GLEW
find_package(GLEW REQUIRED)

# Copy shader files to the build directory
file(COPY src/shader.vs src/shader.fs DESTINATION ${CMAKE_BINARY_DIR})

# Add source files
add_executable(main src/main.cpp)

# Link libraries
target_link_libraries(main OpenGL::GL GLEW::GLEW glfw)

# Add custom target for cleaning shader files
add_custom_target(clean_shaders
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/shader.vs ${CMAKE_BINARY_DIR}/shader.fs
    COMMENT "Removing shader files"
)
