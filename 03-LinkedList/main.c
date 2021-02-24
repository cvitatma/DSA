#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	List L=NULL;
	PtrToNode P;

	// This doesn't work as intended !
	//CreateEmptyList2(L);
	//assert(L != NULL);

	// Use one of the following 	
	CreateEmptyList1(&L);
	// or
	//L = CreateEmptyList();

	// Insert item at front of list	
	InsertAtFront(&L,10);
	InsertAtFront(&L,20);
	InsertAtFront(&L,30);

	PrintList(L);
	
	/*
	EmptyList(&L);
	if(L)
		free(L);
	*/

	//DeleteList(&L);
	
	return 0;
}
