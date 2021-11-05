#ifndef TYPE_H
#define TYPE_H 1
extern int TYPE_DEF;
typedef enum{
    TYPE_CHAR,
    TYPE_SHORT,   //-32768~32767, 2bytes
    TYPE_INT,     //-2147483648~2147483647, 4bytes 
    TYPE_LONG,    //-9223372036854775808~9223372036854775807, 8bytes
    TYPE_FLOAT,   //6-digit precise-value
    TYPE_DOUBLE   //15-digit precise-values
} TYPE;


#endif

