#include <stdio.h>
#include <stdlib.h>
#include "type.h"
int TYPE_DEF = TYPE_DOUBLE;
#include "list.h"
#include "queue.h"
#include "string.h"
#include "mm.h"

int main(int argc, char* argv[]) {
    queue queue = {0};
    printf("size: %d\n", (int)queue.size);
    printf("Input (double): ");
    add_Qnode_from_string(&queue);
    
    printf("================\n");
    printf("%s\n", (char*) "Show all:");
    show_all_queue(&queue);
    printf("================\n");
    printf("%s\n", (char*) "Start Pop:");
    while(queue.size){
        printf("%s\n", show_value(deQueue(&queue)));
    }
}
