#include "sorts.h"

void swap(ElemTypePtr a,ElemTypePtr b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

// HEAP-SORT
void DownHeap(ElemTypePtr a,int i,int n)
{
	// Establish heap property first at a[i]
	int w = i*2 + 1; // First descendant of i (0-based indexing)
	while( w < n ) {
		if ( w+1 < n )
			if ( a[w+1] > a[w] ) w++;
		if ( a[i] >= a[w] ) return;
		swap(&a[i],&a[w]);		
		i = w; // we swapped with this node ; subtree below it may need fixing
		w =i*2+1; // Get first descendant of 'i' and repeat loop procedure
	}
}

void HeapSort(ElemTypePtr a,int n)
{
	int i;

	// perform heap adjustment for non-leaf elements
        // starting from leaf parents and going up level
        // by level towards root
	for(i = n/2-1 ; i >= 0 ; i--)
		DownHeap(a,i,n);	

	while( n > 1 ) {		
		n--;
		swap(&a[0],&a[n]); 
		DownHeap(a,0,n);
	}
}

void CountSort(ElemTypePtr A,int n,int k)
{
    int i;
    unsigned long int count[k+1]; // [0..k]    
    ElementType B[n];

    for(i=0;i<k+1;i++)
        count[i] = 0;

    for(i=0;i<n;i++)
        ++count[A[i]];
    
    for(i=1;i<k+1;i++)
        count[i] = count[i] + count[i-1];
    
    for(i=0; i< n ; i++)
    {
        --count[A[i]];
        B[count[A[i]]] = A[i];
    }

    for(i=0;i< n ;i++)
        A[i] = B[i]; 
}

void RadixCountSort(ElemTypePtr A,int n,int pwr_ten)
{
    int i;
    unsigned long int count[10]; // [0..9]    
    ElementType B[n];

    for(i=0;i<10;i++)
        count[i] = 0;

    for(i=0;i<n;i++) {
        ++count[ (A[i]/pwr_ten) % 10];
        B[i] = 0;
    }
    
    for(i=1;i<10;i++)
        count[i] = count[i] + count[i-1];
    
    for(i= n -1; i >= 0 ; i--)
    {
        --count[(A[i]/pwr_ten) % 10];
        B[count[(A[i]/pwr_ten) % 10]] = A[i];
        PrintArray(B,n);
    }

    for(i=0;i< n ;i++)
        A[i] = B[i]; 
}

void RadixSort(ElemTypePtr A,int n)
{
    int pwr_ten;
    ElementType max_elem = A[0];    
    for(int i = 0 ; i < n ; i++)
        if (A[i] > max_elem)
            max_elem = A[i];
    
    // Loop as many times as the digits in the maximum element
    pwr_ten = 1;
    while( max_elem / pwr_ten > 0)
    {
        RadixCountSort(A,n,pwr_ten);
        pwr_ten *= 10;
    }
        
}
