#include <stdio.h>
#include "Stack.h"
#include "StackUtils.h"

int main(void)
{
    FILE *fp = fopen("add_file_name_here","r"); // Modify appropriately
    int return_flag = -1;
    if(fp != NULL)
        return_flag = BalanceSymbolsInFile(fp);
    
    printf("--> Return flag = %d\n",return_flag);

    return 0;
}
