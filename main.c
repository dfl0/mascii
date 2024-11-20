#include <stdio.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./mascii <path_to_image>\n");
        return 1;
    }

    char *imgpath = argv[1];

    int w, h, channels;
    uint8_t *img = stbi_load(imgpath, &w, &h, &channels, 1);

    if (img == NULL) {
        printf("Failed to load image: %s\n", imgpath);
        return 1;
    }

    printf("Loaded image: %s (%dx%d)\n", imgpath, w, h);
    return 0;
}
