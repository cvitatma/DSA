#include "Stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

Stack InitStack(unsigned long int max_items)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct StackInfo));    
    assert(S != NULL);

    S->MaxNumItems = max_items;
    S->StackItem = (ElementType*)malloc(S->MaxNumItems*sizeof(ElementType));
    assert(S->StackItem != NULL);

    S->TopId = -1;

    return S;
}

void Push(Stack S,ElementType E)
{
    if(S->TopId < S->MaxNumItems)
    {
        ++S->TopId;
        S->StackItem[S->TopId] = E; // CopyItem(S,TopId,E)
    }
}

void Pop(Stack S)
{
    if(!IsEmpty(S))
        --S->TopId;
}

ElementType Top(const Stack S)
{
    if(!IsEmpty(S))
        return S->StackItem[S->TopId];
       
}


int IsEmpty(const Stack S)
{
    return (S->TopId == -1);
}

void ClearStack(Stack S)
{
    S->TopId = -1;
}

void DeleteStack(Stack* SP)
{ 
    if(*SP)
    {
        free((*SP)->StackItem);
        free(*SP);   
        *SP = NULL;
    }
}