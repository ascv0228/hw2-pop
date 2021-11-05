#include <stdio.h>
#include <stdlib.h>
#include "type.h"
int TYPE_DEF = TYPE_INT;
#include "list.h"
#include "string.h"
#include "mm.h"

int main(int argc, char* argv[]) {
    list list = {0};
    printf("size: %d\n", (int)list.size);
    printf("Input : ");
    add_Lnode_from_string(&list_append, &list);
    
    printf("================\n");
    printf("%s\n", (char*) "Show all:");
    show_all(&list);
    printf("================\n");
    printf("%s\n", (char*) "Start Pop:");
    while(list.size){
        printf("%s\n", show_value(list_pop(&list)));
    }
}
