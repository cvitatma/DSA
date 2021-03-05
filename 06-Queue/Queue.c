#include "Queue.h"
#include <stdio.h>
#include <assert.h>

Que InitQue(size_t que_capacity)
{
    Que Q = (Que)malloc(sizeof(struct Queue));
    assert(Q != NULL);

    assert(que_capacity > 0);
    Q->Capacity = que_capacity;

    Q->QArr = (ElementType*)malloc(Q->Capacity * sizeof(ElementType));
    assert (Q->QArr != NULL);

    Q->NumItems = 0;
    Q->Rear = Q->Capacity-1; // or -1
    Q->Front = 0;    
}

void Enque(Que Q,const ElementType E)
{
    assert(!IsFull(Q));

    Q->Rear = (Q->Rear + 1)%(Q->Capacity);
    Q->QArr[Q->Rear] = E;
    ++(Q->NumItems);
}

ElementType Deque(Que Q)
{
    assert(!IsEmpty(Q));

    ElementType E = Q->QArr[Q->Front];
    Q->Front = (Q->Front +1) % Q->Capacity;
    --(Q->NumItems);

    return E;
}

int IsEmpty(const Que Q)
{
    return (Q->NumItems == 0);
}

int IsFull(const Que Q)
{
    return (Q->NumItems == Q->Capacity);
}

void ClearQueue(Que Q)
{
    Q->NumItems = 0;
    Q->Rear = Q->Capacity-1;
    Q->Front = 0;    
}

void DeleteQue(Que* QP)
{
    Que Q = NULL;
    if(*QP)
    {
        Q = *QP;
        free(Q->QArr);
        free(Q);
        *QP = NULL;
    }
}

void PrintQue(const Que Q)
{
    assert(Q->NumItems > 0);

    // Print from front to rear
    long unsigned int idx = Q->Front;
    while(1)
    {
        printf("[%d] ",Q->QArr[idx]);
        if(idx == Q->Rear)
            break;
        else
            idx = (idx +1)% Q->Capacity;
    }
     
    printf("\n");

}
