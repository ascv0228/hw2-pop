#include "mm.h"
#include "stack.h"
#include "list.h"
#include "type.h"
#include <stdio.h>

mytype stack_pop(stack* stack)
{
    return list_pop_from_head(stack);
}
bool stack_push(stack* stack, mytype data)
{
    return list_append_from_head(stack, data);
}
stack createstack()
{
    return createlist();
}
void add_Snode_from_string(stack *stack)
{
    add_Lnode_from_string(&stack_push, stack);
}

void show_all_stack(stack *stack)
{
    show_all(stack);
}
