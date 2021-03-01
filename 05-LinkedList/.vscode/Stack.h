#ifndef __STACK_H
#define __STACK_H

#include "StackLL.h"

Stack CreateStack();

void Push(Stack S,ElementType Elem);
void Pop(Stack S);
ElementType Top(const Stack S);

bool IsEmpty(const Stack S);

void ClearStack(Stack S);
void DeleteStack(Stack** S);

for(i = 0 ; i < 10 ; i++)
    for(j = 0 ; j < 3 ;j++)
    {
        if( j > 4)
        {
            if( i > 3)
            {
                ;
            }
        }
        for(k=9 ; k >=0 ; k--)
        {
            ;
        }
    }
}   
        

#endif

// Function Call Stack
// Undo/Redo
// Most recently used list 
// Intellisense (parantheses matching, code indentation)
// Expression evaluation and Syntax Parsing
// Recursion / Backtracking

// Parantheses matching ()[]{} ... 
// Error
/// 1. Create Empty Stack
/// 2. while(notEndOfFile(FP))
///    {
/*
           p = ReadChar()
           if(openingSymbol(p))
              PushOntoStack(S,p)
           if(closingSymbol(p))
              if(!empty(S))
              {
                 if(matching(Top(S),p))
                    Pop(S)
                 else
                    ERROR // [()}
*/
///           }
///           else
                 // ERROR //  [{}]}()
///    }    
///    if(!empty(S)) [(()])}
///        ERROR
///}
///}
// advanced /* comments */

// Expression Evaluation
// Using two stacks - one for operands, one for operators
// x/2 + (a+b)/c