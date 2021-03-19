#include "sorts.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void PrintArray(ElemTypePtr A,int nElems)
{
    int i;
    for(i = 0 ; i < nElems ; i++)
        printf("%d ",A[i]);
    printf("\n");    
}

void InsertionSort_2(ElemTypePtr A,int numElems,int comp(const ElementType a, const ElementType b))
{
    int i,j;
    ElementType curr;

    assert(numElems > 1);
    
    for(i = 1 ; i < numElems ; i++)
    {
        curr = A[i];
        j = i-1;
        // Find a place for A[i] in the sorted sub-array A[0..(i-1)]
        while( j >=0 && comp(curr,A[j]) )
        {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = curr;
    }
}

// 1
void InsertionSort(ElemTypePtr A, int numElems)
{
    int i,j;
    int p;
    ElementType curr;

    assert(numElems > 1);
    
    // Ascending
    for(i = 1 ; i < numElems ; i++)
    {
        curr = A[i];
        j = i-1;
        // Find a place for A[i] in the sorted sub-array A[0..(i-1)]
        while( j >=0 && curr < A[j] )
        {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = curr;
    }

    /*
    // Descending 
    for(i = 1 ; i < numElems ; i++)
    {        
        curr = A[i];
        j = i-1;        
        while( j >=0 && curr > A[j] )
        {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = curr;
    }
    */
}

int inc_order(const ElementType a, const ElementType b)
{
    return (a < b);
}

int dec_order(const ElementType a, const ElementType b)
{
    return (b < a);
}
