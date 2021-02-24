#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

PtrToNode MakeNode(ElementType X)
{
    PtrToNode P = (PtrToNode)malloc(sizeof(ListNode));
    assert(P != NULL);

    P->Element = X;
    P->Next = NULL;

    return P;
}

List CreateEmptyList()
{
    PtrToNode P = MakeNode(0);    
    return P;
}

void CreateEmptyList1(List* PP) 
{
    PtrToNode P = MakeNode(0);

    *PP = P;
}

void CreateEmptyList2(List PP)
{    
    PtrToNode P = (PtrToNode)malloc(sizeof(ListNode));
    assert(P != NULL);
    P->Next = NULL;

    PP = P;
}

void InsertAtFront(List* LP,ElementType X)
{    
    PtrToNode PNew = MakeNode(X);
    List L = *LP;
    
    PNew->Next = L->Next;
    L->Next = PNew;        

}

void DeleteNode(PtrToNode P)
{    
    if(!P)
        free(P);    
}
