#include "sorts.h"

void swap_array_elems(ElemTypePtr A,int i,int j)
{
    ElementType tmp;

    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

// QUICKSORT  
void QuickSort(ElemTypePtr A, int nElems)
{
    QuickSortDriver(A,0,nElems-1);
}

void QuickSortDriver(ElemTypePtr A, int lower, int upper)
{
    int pivotIdx;
    if(lower < upper)
    {
        pivotIdx = QPartition(A,lower,upper);
	// After every partition, pivot is its correct sorted place
        QuickSortDriver(A,lower,pivotIdx-1);
        QuickSortDriver(A,pivotIdx+1,upper);
    }
}


int QPartition(ElemTypePtr A,int lower,int upper)
{

    int pivot_value;
    int left_end;
    int i;
    ElementType tmp;

    pivot_value = A[upper];
    // TODO: Pick pivot value using some good strategy (median of 3 randomly chosen elements etc.)

    left_end = lower;
    for( i = lower ; i < upper ; i++)
    {
        if ( A[i] < pivot_value ) 
        {
            swap_array_elems(A,i,left_end);           
            ++left_end;
        }
    }
    swap_array_elems(A,left_end,upper);

    return left_end;
}

// Find k-th smallest
ElementType QuickSelectKth(ElemTypePtr A,int lower,int upper, int k)
{
    int pivotIdx;
    int pivotDist = upper-lower+1;
    int nElems = upper+1; 

    while (lower <= upper)
    {        
        pivotIdx = QPartition(A,lower,upper);
	// After every partition, pivot is its correct sorted place
	pivotDist = pivotIdx - lower  + 1;
    	if(pivotDist == k)
		return A[pivotIdx];
	else if ( pivotDist > k )
		upper = pivotIdx - 1;
	else 
	{
		k = k - pivotDist;
	        lower = pivotIdx + 1;
	}        
    }    
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
		swap_array_elems(a,i,w);		
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
		swap_array_elems(a,0,n); 
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
