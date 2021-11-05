#include "mm.h"
#include "queue.h"
#include "list.h"
#include "type.h"
#include <stdio.h>

mytype deQueue(queue* queue)  //pop from head
{
    return list_pop_from_head(queue); 
}

bool enQueue(queue *queue, mytype data){ //append from tail
    return list_append(queue, data);
}

bool isEnpty(queue *queue){
    return !queue->size;
}

queue createQueue(){
    return createlist();
}

void add_Qnode_from_string(queue* queue)
{
    add_Lnode_from_string(&enQueue, queue);
}

void show_all_queue(queue *queue){
    show_all(queue);
}
