#ifndef __SLL_H
#define __SLL_H
// Singly Linked List
// Header-node assumed

#include "IntElement.h"

typedef struct Node ListNode;
typedef struct Node* PtrToNode;

typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
    ElementType Element;
    Position Next;
};

// Creates a node and instantiates the element
// Returns pointer to created node
PtrToNode MakeNode(ElementType X);

List CreateEmptyList(); // Creates an empty list with header node
void CreateEmptyList1(List* PP); // Creates an empty list with header node
void CreateEmptyList2(List PP); // Does not work !

void InsertAtFront(List* LP,ElementType X);
void InsertAtRear(List* LP,ElementType X);

void DeleteNode(PtrToNode P);
void DeleteList(List* LP);
void EmptyList(List* LP);

void PrintList(List P);

#endif
