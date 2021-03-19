#include "sorts.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

    ElementType A[] = {5,1,3,6,8,9,4};   
    size_t numElems = sizeof(A)/sizeof(ElementType);
    InsertionSort_2(A,numElems,dec_order);
    //InsertionSort_m(A,numElems);
    PrintArray(A,numElems);
}
