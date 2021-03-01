#ifndef __STACKARRAY_H
#define __STACKARRAY_H

typedef int ElementType;
const int STACK_MAX_ELEMS = 8000;
typedef struct StackInfo* Stack;

struct StackInfo {
    ElementType StackArr[STACK_MAX_ELEMS];
    int Top;
};

#endif