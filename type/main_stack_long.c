#include <stdio.h>
#include <stdlib.h>
#include "type.h"
int TYPE_DEF = TYPE_LONG;
#include "list.h"
#include "stack.h"
#include "string.h"
#include "mm.h"

int main(int argc, char* argv[]) {
    stack stack = createstack();
    printf("size: %d\n", (int)stack.size);
    printf("Input (long): ");
    add_Snode_from_string(&stack);
    
    printf("================\n");
    printf("%s\n", (char*) "Show all:");
    show_all_stack(&stack);
    printf("================\n");
    printf("%s\n", (char*) "Start Pop:");
    while(stack.size){
        printf("%s\n", show_value(stack_pop(&stack)));
    }
}
