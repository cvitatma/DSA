#include "Queue.h"

int main(void)
{
    Que Q = InitQue(100);

    Enque(Q,10);
    PrintQue(Q);
    Enque(Q,20);
    PrintQue(Q);
    Enque(Q,30);
    PrintQue(Q);
    Enque(Q,40);
    PrintQue(Q);
    Deque(Q);
    PrintQue(Q);
    Deque(Q);
    PrintQue(Q);

    DeleteQue(&Q);

    return 0;
}