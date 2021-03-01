#ifndef __STACKARR_H
#define __STACKARR_H

typedef double ElementType;

typedef struct StackInfo* Stack;

struct StackInfo {    
    long int MaxNumItems;
    long int TopId;
    ElementType *StackItem;
};

#endif