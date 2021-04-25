#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>

typedef struct stNodeq  * Queue;  // Normal Queue implementation
typedef struct stNodepq * PQueue; // Priority Queue using Min Heaps  or Fibncaii heaps
typedef struct stNodeq  * Nodeq;  // Node in Queue
typedef struct stNodepq * Nodepq; // Node in Priority Queue

typedef int Element;
typedef float Key;



Queue   CreateEmptyQueue();
PQueue  CreateEmptyPriorityQueue();
Element DeQueue(Queue Q);
void    Enqueue(Queue Q, Element u);
void    Priority_Enqueue(PQueue Q, Element u, Key k);
int     IsQueueEmpty(Queue Q);
int     IsPQueueEmpty(PQueue Q);
Element ExtractMin(PQueue Q);
void    DecreaseKey(PQueue Q, Element u, Key new_decreased_key);

struct stNodeq{
    Element n;
    Nodeq pNext;
};

struct stNodepq{
    Element n;
    Key k;
    Nodepq pNext;
};

#endif
