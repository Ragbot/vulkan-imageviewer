//
// Created by ragbot on 3/7/22.
//

#ifndef GL_APP_APPPIPELINE_H
#define GL_APP_APPPIPELINE_H

#include "AppDevice.h"

#include <string>
#include <vector>

namespace rag {

    struct PipelineConfigInfo {
    };

    class AppPipeline {
    public:
        AppPipeline(AppDevice &appDevice, const std::string &vertFilePath, const std::string &fragFilePath,
                    const rag::PipelineConfigInfo &config_info);

        ~AppPipeline() {}

        AppPipeline(const AppPipeline &) = delete;

        void operator=(const AppPipeline &) = delete;

        static PipelineConfigInfo defaultPipelineConfig(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string &filePath);

        void createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath,
                                    const PipelineConfigInfo &config_info);

        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        AppDevice &appDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
} // rag

#endif //GL_APP_APPPIPELINE_H
