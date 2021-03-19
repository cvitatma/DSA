#ifndef __SORTS_H
#define __SORTS_H
#include <sys/types.h>

typedef int ElementType;
typedef ElementType* ElemTypePtr;

void PrintArray(ElemTypePtr A,int nElems);
void InsertionSort(ElemTypePtr A,int numElems);
void InsertionSort_2(ElemTypePtr A,int numElems,int comp(const ElementType a, const ElementType b));
int inc_order(const ElementType a, const ElementType b);
int dec_order(const ElementType a, const ElementType b);

#endif
