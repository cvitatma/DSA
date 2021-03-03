#ifndef __STACKUTILS_H
#define __STACKUTILS_H

#include "Stack.h"
#include <stdio.h>

int BalanceSymbolsInFile(FILE *fp);

int IsLeftOp(const char ch);
int IsRightOp(const char ch);

#endif
