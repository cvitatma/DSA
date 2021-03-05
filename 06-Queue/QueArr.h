#ifndef __QUEARR_H
#define __QUEARR_H
#include <stdlib.h>

typedef int ElementType;
typedef struct Queue* Que;

struct Queue {
    size_t NumItems;
    size_t Capacity;
    size_t Front;
    size_t Rear;
    ElementType* QArr;
};

#endif