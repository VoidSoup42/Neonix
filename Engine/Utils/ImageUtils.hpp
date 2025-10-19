#pragma once

#include <stb_image.h>
#include <iostream>

namespace Neonix
{
    struct ImageData
    {
        unsigned char* imageBytes;
        int width;
        int height;
        int channels;
    };
    
    inline static ImageData load_image(const char* path)
    {
        stbi_set_flip_vertically_on_load(true);
        int width, height, channels;
        unsigned char* imageBytes = stbi_load(path, &width, &height, &channels, 0);

        if (!imageBytes)
        {
            std::cout << "Failed to load image: " << path << std::endl;
            return ImageData{nullptr, 0, 0, 0};
        }

        std::cout << "Image Loaded : " << path << std::endl;
        return ImageData{imageBytes, width, height, channels};

        stbi_image_free(imageBytes);
    }
}