#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Usage: ./copy 1.text\n");
        return 1;
    }

    //open image
    FILE *original = fopen(argv[1], "r");
    if (original == NULL){
        printf("File couldn't be read\n");
        return 1;
    }
    //get name of input file to append copy to it
    char *inputFileName = argv[1];
    char *nameBeforePeriod = strtok(inputFileName, ".");
    int inputNameLenght = strlen(nameBeforePeriod);

    //create new file
    char filename[inputNameLenght + 9];
    sprintf(filename, "%s copy.txt", nameBeforePeriod);
    FILE *copy = fopen(filename, "w");

    //copy and paste to new file
    int c;
    while(1){
        c = fgetc(original);
        if (feof(original)){
            break;
        }
        fputc(c, copy);
    }

    fclose(copy);
    fclose(original);

    return 0;
}
