#ifndef QUEUE_H
#define QUEUE_H 1
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "type.h"
typedef struct list queue;

mytype deQueue(queue* queue);
bool enQueue(queue *queue, mytype data);
bool isEnpty(queue *queue);
void show_all_queue(queue *queue);
queue createQueue();
void add_Qnode_from_string(queue *queue);
#endif

