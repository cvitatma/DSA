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
    
    if(L->Next == NULL)          
        L->Next = PNew;        
    else {
        PNew->Next = L->Next;
        L->Next = PNew;        
    }
}

void DeleteNode(PtrToNode P)
{    
    if(!P)
        free(P);    
}

// Delete first occurrence of X in list L
void FindAndDelete(List L,ElementType X)
{
    L = L->Next;
    while(L)
    {
        PtrToNode NextNode = L->Next;
        PtrToNode Tmp;
        if(NextNode && AreEqualElems(NextNode->Element,X)) // Found X !
        {
            Tmp = NextNode;
            L->Next = Tmp->Next;
            DeleteNode(Tmp);
            return;
        }
        else 
        {
            L = L->Next;
        }   
    }
}

void PrintList(List L)
{
    PtrToNode P = L->Next; // Skip header

    printf("\n");
    while ( P != NULL)
    {        
        printf("%p:%d --> ",P,P->Element);
        P = P->Next;
    }
    printf("[NULL]");
    printf("\n\n");
}

// Delete all nodes except header
void EmptyList(List* LP)
{
    List L = *LP;
    L = L->Next;    
    PtrToNode Curr;
    while( L != NULL )
    {
        Curr = L;
        L = L->Next;
        DeleteNode(Curr);
    }
    (*LP)->Next = NULL;
}

// Delete all nodes "including" header
void DeleteList(List* LP)
{
    EmptyList(LP);
    free(*LP);    
}
