#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int number;
    struct node *next;
}node;

int main(int argc, char* argv[]){
    node *list = NULL;

    if (argc != 4){
        printf("Wrong input! Should be 3 integers!\n");
        return 1;
    }

    for (int i = 1; i < argc; i++){
        node *n = malloc(sizeof(node));
 
        n->number = atoi(argv[i]);
        n->next = list;

        list = n;
    }
    node *ptr = list;
    while(ptr != NULL){
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

}
