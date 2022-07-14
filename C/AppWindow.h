//
// Created by ragbot on 3/7/22.
//

#ifndef GL_APP_APPWINDOW_H
#define GL_APP_APPWINDOW_H

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <string>

namespace rag {

    class AppWindow {
    public:
        AppWindow(int w, int h, std::string name);

        ~AppWindow();

        AppWindow(const AppWindow &) = delete;

        AppWindow &operator=(const AppWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

        static void defaultKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        void initWindow();

        GLFWwindow *window{};
        std::string windowName;
        const int width, height;
    };

} // rag

#endif //GL_APP_APPWINDOW_H
