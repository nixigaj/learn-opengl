#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

bool isFullscreen = false; // Tracks the fullscreen state
GLFWwindow* window = nullptr;
GLFWmonitor* monitor = nullptr; // Pointer to the primary monitor
int windowedWidth = SCR_WIDTH, windowedHeight = SCR_HEIGHT;
int windowedPosX = 100, windowedPosY = 100; // To store window position before fullscreen

int main() {
    if (std::getenv("GTK_THEME") == nullptr) {
        setenv("GTK_THEME", "Adwaita-dark", 1);
    }

    // glfw: initialize and configure
    // ------------------------------
    if (glfwPlatformSupported(GLFW_PLATFORM_WAYLAND))
        glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowSizeLimits(window, 30, 10, GLFW_DONT_CARE, GLFW_DONT_CARE);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Get the primary monitor
    monitor = glfwGetPrimaryMonitor();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(.1f, .1f, .1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        // Add any rendering here
        glEnd();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    static bool f11Pressed = false;
    if (glfwGetKey(window, GLFW_KEY_F11) == GLFW_PRESS) {
        if (!f11Pressed) {
            f11Pressed = true; // Prevent repeated toggling while key is held
            if (isFullscreen) {
                // Switch to windowed mode
                glfwSetWindowMonitor(window, nullptr, windowedPosX, windowedPosY, windowedWidth, windowedHeight, 0);
                isFullscreen = false;
            } else {
                // Save windowed position and size
                glfwGetWindowPos(window, &windowedPosX, &windowedPosY);
                glfwGetWindowSize(window, &windowedWidth, &windowedHeight);

                // Get monitor resolution
                const GLFWvidmode* mode = glfwGetVideoMode(monitor);

                // Switch to fullscreen mode
                glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
                isFullscreen = true;
            }
        }
    } else if (glfwGetKey(window, GLFW_KEY_F11) == GLFW_RELEASE) {
        f11Pressed = false; // Allow toggling again when key is released
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
