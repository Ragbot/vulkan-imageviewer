//
// Created by ragbot on 3/7/22.
//

#include "AppPipeline.h"

#include <fstream>
#include <stdexcept>

namespace rag {

    AppPipeline::AppPipeline(AppDevice &appDevice, const std::string &vertFilePath, const std::string &fragFilePath,
                             const rag::PipelineConfigInfo &config_info) : appDevice(appDevice) {
        createGraphicsPipeline(vertFilePath, fragFilePath, config_info);
    }

    std::vector<char> AppPipeline::readFile(const std::string &filePath) {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};

        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);
        file.seekg(0);
        file.read(buffer.data(), fileSize);
        file.close();

        return buffer;
    }

    void AppPipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath,
                                             const rag::PipelineConfigInfo &config_info) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        printf("Vert file size: %zu\n", vertCode.size());
        printf("Frag file size: %zu\n", fragCode.size());
    }

    void AppPipeline::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule) {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t *> (code.data());

        if (vkCreateShaderModule(appDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create shaderModule");
        }
    }

    PipelineConfigInfo AppPipeline::defaultPipelineConfig(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};

        return configInfo;
    }
} // rag