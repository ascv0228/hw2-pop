#include <stdio.h>
#include <string.h>
#include "list.h"
#include "queue.h"
#include "mm.h"
#include "type.h"
int main(int argc, char* argv[]) {
    queue queue = {0};

    printf("size: %d\n", (int)queue.size);
    add_Qnode_from_string(&queue);
    
    printf("size: %d\n", (int)queue.size);
    printf("================\n");
    printf("%s\n", (char*) "Show all:");
    show_all_queue(&queue);
    printf("================\n");
    printf("%s\n", (char*) "Start DeQueue:");
    while(queue.size){
        printf("%s\n", deQueue(&queue));
    }
    
}
