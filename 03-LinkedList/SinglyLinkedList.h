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
void CreateEmptyList2(List PP); // Does not work as intended !

void InsertAtFront(List* LP,ElementType X);
<<<<<<< HEAD
void InsertAtFront_v2(List L,ElementType X); //TODO: Simpler - can have this version if we use header-based linked lists
void InsertAtRear(List* LP,ElementType X); // TODO
=======
void InsertAtFront_v2(List L,ElementType X);
void InsertAtFront_v2(List L,ElementType X);
void InsertAtRear(List* LP,ElementType X);
>>>>>>> full-dev

void DeleteNode(PtrToNode P);
void DeleteList(List* LP); // TODO
void EmptyList(List* LP); // TODO

void PrintList(List P); // TODO

#endif
