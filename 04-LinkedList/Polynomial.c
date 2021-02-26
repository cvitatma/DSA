#include "Polynomial.h"
#include <assert.h>
#include <stdlib.h>

Poly InitPoly()
{
    Poly P = (Poly)malloc(sizeof(PTerm));
    assert(P!=NULL);

    P->Next = NULL;

    return P;
}

void AddTerm(Poly P,unsigned long int exponent,double coefficient)
{
    Poly T;
    while( (P->Next != NULL) && (P->Next->expo < exponent) )
        P  = P->Next;

    if( (P->Next == NULL) || (P->Next->expo > exponent) ) 
    {
        T = InitPoly(); // Create node
        T->coeff = coefficient;
        T->expo = exponent;
        //T->Next = NULL;
        T->Next = P->Next;
        P->Next = T;
    }
    else // P->Next->expo = exponent
    {
        //UpdateTerm(P,coefficient,exponent);
        P->Next->coeff = coefficient;
    }
}