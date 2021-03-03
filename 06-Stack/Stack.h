#ifndef __STACK_H
#define __STACK_H

#include "StackArr.h"

Stack InitStack(unsigned long int max_items);

void Push(Stack S,ElementType E);
void Pop(Stack S);
ElementType Top(const Stack S);

int IsEmpty(const Stack S);
void ClearStack(Stack S);
void DeleteStack(Stack* S);

#endif