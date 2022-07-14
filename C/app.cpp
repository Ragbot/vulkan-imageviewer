//
// Created by ragbot on 3/7/22.
//

#include "app.h"

namespace rag {
    void app::run() {
        while (!window.shouldClose()) {
            glfwPollEvents();
        }
    }
}