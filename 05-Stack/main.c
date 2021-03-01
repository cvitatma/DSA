#include <stdio.h>
#include "Stack.h"

int main(void)
{
    Stack S;
    
    int max_elems = 10000;
    S = InitStack(max_elems);

    Push(S,10);
    Push(S,20);
    Push(S,30);
    Push(S,40);

    Pop(S);
    Pop(S);
    Pop(S);

    DeleteStack(&S);

    return 0;
}