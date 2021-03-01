#ifndef __DLL_H
#define __DLL_H

typedef struct Node* NodePtr;
typedef int ElementType;

struct Node {
    ElementType Elem;
    NodePtr Next;
    NodePtr Prev;
};

#endif

/*
void DeleteNode(NodePtr P)
{
    P->Prev->Next = P->Next;
    P->Next->Prev = P->Prev;
    free(P);
}
*/
