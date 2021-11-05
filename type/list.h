#ifndef LIST_H
#define LIST_H 1
    #if TYPE_DEF == TYPE_CHAR
        #define mytype char
    #elif TYPE_DEF == TYPE_SHORT
        #define mytype short
    #elif TYPE_DEF == TYPE_INT 
        #define mytype int
    #elif TYPE_DEF == TYPE_LONG 
        #define mytype long
    #elif TYPE_DEF == TYPE_FLOAT
        #define mytype float
    #elif TYPE_DEF == TYPE_DOUBLE 
        #define mytype DOUBLE
    #endif
    #include <stddef.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include "mm.h"
    typedef struct node_t{
        mytype data;
        struct node_t *next, *prev;
    } node_t;

    typedef struct list{
        size_t size;
        struct node_t *head, *tail;
    }list;

    node_t* node_init(mytype data);
    bool list_append(list *list, mytype data);
    bool list_append_from_head(list *list, mytype data);
    mytype list_pop(list *list);
    mytype list_pop_from_head(list *list);
    int list_get(list *list, int position);
    int list_len(list *list);
    char* show_data(node_t *node);
    mytype get_value(char *s);
    char* show_value(mytype data);
    void show_all(list *list);
    void show_all_from_tail(list *list);
    list createlist();

    void add_Lnode_from_string(bool (*add_func)(list*, mytype), list* list);
#endif

