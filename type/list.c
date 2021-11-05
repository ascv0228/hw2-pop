#include "type.h"
#include "list.h"
#include "mm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t* node_init(mytype data){
    node_t *tmp_node = (node_t*)mycalloc(1,sizeof(node_t));
    tmp_node->data = data;
    tmp_node->next = NULL;
    tmp_node->prev = NULL;
    return tmp_node;
}

bool list_append(list *list, mytype data)  //return successful, or not.
{
    bool flag = false;
    if(list->head == NULL){
        node_t *add_node = node_init(data);
        list->head = add_node;
        list->tail = add_node;
        ++list->size;
        flag = true;
        return flag;
    }
    node_t *add_node = node_init(data);
    list->tail->next = add_node;
    list->tail->next->prev = list->tail;
    list->tail = add_node;
    ++list->size;
    flag = true;
    return flag;
}
bool list_append_from_head(list *list, mytype data)  //return successful, or not.
{
    bool flag = false;
    if(list->head == NULL){
        node_t *add_node = node_init(data);
        list->head = add_node;
        list->tail = add_node;
        ++list->size;
        flag = true;
        return flag;
    }
    node_t *add_node = node_init(data);
    add_node->next = list->head;
    add_node->next->prev = add_node;
    list->head = add_node;
    ++list->size;
    flag = true;
    return flag;
}
mytype list_pop(list *list)  //return the delete value, if succeed, or return -1
{
    mytype data = 0;
    if(list->head == NULL){
        list->size = 0;
        return -1;
    }
    if(list->head->next == NULL){
        data = list->head->data;
        myfree(list->head);
        list->head = NULL; 
        list->tail = NULL; 
        list->size = 0;
    }
    else{
        node_t *tmp_node = list->tail->prev;
        data = list->tail->data;
        myfree(list->tail);
        list->tail = tmp_node;
        tmp_node->next = NULL;
        --list->size;  
    }
    return data;
}
mytype list_pop_from_head(list *list)  //return the delete value, if succeed, or return -1
{
    mytype data = 0;
    if(list->head == NULL){
        list->size = 0;
        return -1;
    }
    if(list->head->next == NULL){
        data = list->head->data;
        myfree(list->head);
        list->head = NULL; 
        list->tail = NULL; 
        list->size = 0;
    }
    else{
        node_t *tmp_node = list->head;
        data = list->head->data;
        list->head = list->head->next;
        myfree(tmp_node);
        list->head->prev = NULL;
        --list->size;
    }
    return data;
}
/*
int list_get(list *list, int position) //the first element is located on [0], remainder of position is real position
{
    int len = list->size;
    if(len == 0)
        return -1;
    if(len == 1)
        return list->head->data;
    node_t *tmp_node = list->head;
    int p = position % len;
    for (int i = 0; i < p; ++i){
        tmp_node = tmp_node->next;
    }
    return tmp_node->data;
}*/
int list_len(list *list)
{
    return list->size;
}
char *show_data(node_t *node)
{
    return show_value(node->data);
}

mytype get_value(char *s)
{
    mytype res;
    switch(TYPE_DEF)
    {
        case TYPE_CHAR:
            res = s[0];
            break;
        case TYPE_SHORT:
            res = (mytype) atoi(s);
            break;
        case TYPE_INT:
            res = (mytype) atoi(s);
            break;
        case TYPE_LONG:
            res = (mytype) atol(s);
            break;
        case TYPE_FLOAT:
            res = (mytype) atof(s);
            break;
        case TYPE_DOUBLE:
            res = (mytype) atof(s);
    }
    return res;
}
char* show_value(mytype data){
    char* s1 = (char*)mycalloc(100,sizeof(char));
    char* format_s = (char*)mycalloc(5,sizeof(char));
    switch(TYPE_DEF)
    {
        case TYPE_CHAR:
            strcpy(format_s, (char *)"%c");
            break;
        case TYPE_SHORT:
            strcpy(format_s, (char *)"%hd");
            break;
        case TYPE_INT:
            strcpy(format_s, (char *)"%d");
            break;
        case TYPE_LONG:
            strcpy(format_s, (char *)"%Ld");
            break;
        case TYPE_FLOAT:
            strcpy(format_s, (char *)"%f");
            break;
        case TYPE_DOUBLE:
            strcpy(format_s, (char *)"%f");
    }
    sprintf(s1, format_s, data);
    return s1;
}
void show_all_from_tail(list *list)
{
    node_t *tmp_node = list->tail;
    printf("[");
    while(tmp_node){
        printf("%s, ",show_data(tmp_node));
        tmp_node = tmp_node->prev;
    }
    printf("]\n");
}
void show_all(list *list)
{
    node_t *tmp_node = list->head;
    printf("[");
    while(tmp_node){
        printf("%s, ",show_data(tmp_node));
        tmp_node = tmp_node->next;
    }
    printf("]\n");
}
list createlist()
{
    list lst = {0};
    return lst;
}
void add_Lnode_from_string(bool (*add_func)(list*, mytype), list *list){
    if(!add_func)
        add_func = &list_append;
    char *rstr = (char *)mycalloc(10000, sizeof(char));
    fgets(rstr, 10000, stdin);
    char *pch;
    pch = strtok (rstr," \n");
    
    while (pch != NULL)
    {
        add_func(list, get_value(pch));
        pch = strtok (NULL, " \n");
    }
}
