#include "Polynomial.h"
#include <stdlib.h>
#include <limits.h> 

Poly InitPoly()
{
    Poly P = (Poly)malloc(sizeof(PTerm));
    assert(P!=NULL);

    P->expo = INT_MAX;
    P->Next = NULL;

    return P;
}

void AddTerm(Poly P,unsigned int exponent,double coeff)
{
    Poly T;
    while ( (P->Next != NULL) && P->Next->expo < exponent)
    {
        P = P->Next;
    }

    if( (P->Next == NULL) || (P->Next->expo > exponent) )
    {
        T = InitPoly();
        T->expo = exponent;
        T->coeff = coeff;
        T->Next = P->Next;
        P->Next = T;
    }
    else // P->Next->expo == exponent
    {
        P->Next->coeff = coeff; 
    }

}