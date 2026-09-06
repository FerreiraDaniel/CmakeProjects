# CMake Projects

This repository contains small CMake and OpenGL learning projects written in C
and C++.

## Requirements

These commands assume macOS with Homebrew:

```sh
brew install cmake glfw glew
```

The projects use the system OpenGL framework supplied by macOS. Select the
current macOS SDK when configuring:

```sh
export CMAKE_OSX_SYSROOT="$(xcrun --sdk macosx --show-sdk-path)"
export CMAKE_PREFIX_PATH="$(brew --prefix glfw);$(brew --prefix glew)"
```

Build directories contain generated files and can be removed and recreated
when the Xcode or macOS SDK changes.

## Projects

### `tutorial01`

A minimal CMake/OpenGL project. It currently builds an executable whose
`main()` returns immediately; it does not open a window yet.

```sh
cmake -S tutorial01 -B tutorial01/build \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="$CMAKE_PREFIX_PATH" \
  -DCMAKE_OSX_SYSROOT="$CMAKE_OSX_SYSROOT"
cmake --build tutorial01/build --parallel
./tutorial01/build/hello_window
```

### `tutorial02`

A CMake configuration exercise demonstrating cache variables and options.

```sh
cmake -S tutorial02 -B tutorial02/build \
  -DCMAKE_BUILD_TYPE=Debug
cmake --build tutorial02/build --parallel
```

### `opengl_legacy_profile`

A GLFW application that renders a colored triangle with legacy OpenGL
immediate-mode calls (`glBegin`, `glColor3f`, and `glVertex2f`). It uses an
OpenGL 2.1 context for compatibility with those APIs.

```sh
cmake -S opengl_legacy_profile -B opengl_legacy_profile/build \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="$(brew --prefix glfw)" \
  -DCMAKE_OSX_SYSROOT="$(xcrun --sdk macosx --show-sdk-path)"
cmake --build opengl_legacy_profile/build --parallel
./opengl_legacy_profile/build/opengl_legacy_profile
```

Press `Escape` to close the window.

### `opengl_hello_triangle`

A modern OpenGL triangle example using GLFW, GLEW, vertex and fragment
shaders. The shader files are copied into the build directory and located
independently of the directory from which the executable is launched.

```sh
cmake -S opengl_hello_triangle -B opengl_hello_triangle/build \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="$CMAKE_PREFIX_PATH" \
  -DCMAKE_OSX_SYSROOT="$CMAKE_OSX_SYSROOT"
cmake --build opengl_hello_triangle/build --parallel
./opengl_hello_triangle/build/hello_triangle
```
