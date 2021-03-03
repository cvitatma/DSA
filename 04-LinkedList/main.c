#include "Polynomial_1.h"
#include <stdlib.h>

int main()
{
    Poly P = NULL;
    P = InitPoly();
    
    AddTerm(P,1,10);
    AddTerm(P,2,22);
    AddTerm(P,5,13);
    AddTerm(P,4,30);
    AddTerm(P,6,13);
    AddTerm(P,5,23);

    DeleteTerm(P,2);
    DeleteTerm(P,1);

    return 0;
}