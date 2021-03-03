#include "StackUtils.h"
#include <assert.h>

int IsLeftOp(const char ch)
{
	// Implement
}

int IsRightOp(const char ch)
{
	// Implement
}

int BalanceSymbolsInFile(FILE *fp)
{    
    ElementType ch;
    ElementType stk_top;
    int fileSize;
    int left_idx,right_idx;
    Stack S;

    // Find file size
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    // Initialize stack depth to file size
    S = InitStack(fileSize);

    while(!feof(fp))
    {
        ch = fgetc(fp);        
        if( IsLeftOp(ch) )        
            Push(S,ch);
        else 
        {
            right_idx = IsRightOp(ch);
            if ( right_idx )        
            {
                if(IsEmpty(S))
                    assert(0); // ERROR
                else 
                {
                    stk_top = Top(S);
                    left_idx = IsLeftOp(stk_top);                
                    if(left_idx != right_idx)
                        assert(0); // ERROR
                    else // left and right symbols match
                        Pop(S);       
                }               
            }
        }
    } 
    fclose(fp);

    if(!IsEmpty(S))
        assert(0); // ERROR

    DeleteStack(&S);

    return 0;
}    
