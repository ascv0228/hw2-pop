#ifndef STACK_H
#define STACK_H 1
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "type.h"
typedef struct list stack;


mytype stack_pop(stack* stack);
bool stack_push(stack* stack, mytype data);
void show_all_stack(stack *stack);
stack createstack();
void add_Snode_from_string(stack *stack);
#endif

