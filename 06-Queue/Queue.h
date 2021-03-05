#ifndef __QUEUE_H
#define __QUEUE_H

#include "QueArr.h"

Que InitQue(size_t que_capacity);
void Enque(Que Q,const ElementType E);
ElementType Deque(Que Q);

int IsEmpty(const Que Q);
int IsFull(const Que Q);

void PrintQue(const Que Q);

void ClearQue(Que Q);
void DeleteQue(Que* Q);

#endif

// FIFO
// Applications
/// Fair access to a limited resource
//// Printer
//// CPU
//// Customer Care 
//
// "Priority Queue"
//
// Linked List Implementation


// Array, Linked List, Stack, Queue
//
// Insert
// Delete
// Find (return pointer/index to element)
