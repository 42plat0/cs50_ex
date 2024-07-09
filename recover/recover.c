#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//SOI bytes 255, 216, 255
//EOI bytes 0xFF, 0xD9
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{


    if (argc != 2){
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    //open image
    FILE *forensicImage = fopen(argv[1], "r");
    if (forensicImage == NULL){
        printf("File couldn't be read\n");
        return 1;
    }

    uint8_t block[BLOCK_SIZE];
    FILE *img = NULL;
    int count = 0;

    while(fread(block, sizeof(uint8_t), BLOCK_SIZE, forensicImage) == BLOCK_SIZE){

        if (block[0] == 255 && block[1] == 216 && block[2] == 255 && (block[3] & 240) == 224){

            if (img != NULL){
                fclose(img);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL) {
                printf("Could not create output JPEG %s\n", filename);
                fclose(forensicImage);
                return 1;
            }
            count++;
        }

        if (img != NULL){
            fwrite(block, sizeof(uint8_t), BLOCK_SIZE, img);
        }
    }

    if (img != NULL){
        fclose(img);
    }
    fclose(forensicImage);

    return 0;
}
