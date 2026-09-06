cmake_minimum_required(VERSION 3.16)

project(OpenGLExample VERSION 1.0 LANGUAGES C)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(opengl_legacy_profile main.c)

target_link_libraries(opengl_legacy_profile
    PRIVATE
    OpenGL::GL
    glfw
)
