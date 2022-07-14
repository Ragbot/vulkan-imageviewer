//
// Created by ragbot on 3/7/22.
//

#ifndef GL_APP_APP_H
#define GL_APP_APP_H

#include "AppWindow.h"
#include "AppDevice.h"
#include "AppPipeline.h"

namespace rag {
    class app {
    public:

        app() {}

        void run();

        static const int WIDTH = 800;
        static const int HEIGTH = 600;
    private:
        AppWindow window{WIDTH, HEIGTH, "Hello Vulkan!"};
        AppDevice device{window};
        AppPipeline pipeline{device, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv",
                             AppPipeline::defaultPipelineConfig(WIDTH, HEIGTH)};
    };
}


#endif //GL_APP_APP_H
