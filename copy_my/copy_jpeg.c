#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//SOI bytes 255, 216, 255
//EOI bytes 0xFF, 0xD9
#define BLOCK_SIZE 512
int main(int argc, char *argv[])
{


    if (argc != 2){
        printf("Usage: ./copy 1.text\n");
        return 1;
    }

    //open image
    FILE *original = fopen(argv[1], "rb");
    if (original == NULL){
        printf("File couldn't be read\n");
        return 1;
    }

    uint8_t block[BLOCK_SIZE];
    FILE *copy = NULL;

    while(fread(block, sizeof(uint8_t), BLOCK_SIZE, original) == BLOCK_SIZE){
        if (block[0] == 255 && block[1] == 216 && block[2] == 255 && (block[3] & 240) == 224){
            char filename[8];
            sprintf(filename, "%s.jpg", "copy");
            copy = fopen(filename, "w");
        }
        fwrite(block, sizeof(uint8_t), BLOCK_SIZE, copy);
    }




    fclose(copy);
    fclose(original);

    return 0;
}
