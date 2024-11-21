#include <stdio.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char **argv) {
    if (argc < 2 || argc > 4) {
        printf("Usage: ./mascii <path_to_image> [<target_width} [target_height]]\n");
        return 1;
    }

    char *imgpath = argv[1];

    int w_src, h_src, channels;
    uint8_t *img = stbi_load(imgpath, &w_src, &h_src, &channels, 1);

    int w_dst, h_dst;
    if (argc == 3) {
        w_dst = atoi(argv[2]);
        h_dst = (h_src*w_dst)/w_src;
    } else if (argc == 4) {
        w_dst = atoi(argv[2]);
        h_dst = atoi(argv[3]);
    } else {
        w_dst = w_src;
        h_dst = h_src;
    }

    if (img == NULL) {
        printf("Failed to load image: %s\n", imgpath);
        return 1;
    }
    // printf("Loaded image: %s (%dx%d)\n", imgpath, w_src, h_src);

    #define N_SHADES 8
    char shades[N_SHADES] = "$#@%*+: ";

    for (int y_dst = 0; y_dst < h_dst; ++y_dst) {
        for (int x_dst = 0; x_dst < w_dst; ++x_dst) {
            int x_src = x_dst*w_src/w_dst;
            int y_src = y_dst*h_src/h_dst;
            uint8_t value = img[y_src*w_src + x_src];
            printf("%c", shades[value*(N_SHADES-1)/255]);
        }
        printf("\n");
    }

    return 0;
}
