#include <GLFW/glfw3.h>  // Include GLFW
#include <OpenGL/gl.h>    // Include OpenGL

// A simple function to handle error messages
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;  // Initialization failed
    }

    // Immediate-mode rendering below requires a compatibility context.
    // macOS provides this through its legacy OpenGL 2.1 context.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL Example", NULL, NULL);
    if (!window) {
        glfwTerminate();  // Window creation failed
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Enable vertical sync (optional)
    glfwSwapInterval(1);

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Process input (optional)
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // Set clear color
        glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

        // Draw something simple (e.g., a triangle)
        // For simplicity, we won't use shaders or VBOs here.
        // But this would be the place to do it.
        
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-0.6f, -0.6f);
        
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex2f(0.6f, -0.6f);
        
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex2f(0.0f, 0.6f);
        glEnd();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
