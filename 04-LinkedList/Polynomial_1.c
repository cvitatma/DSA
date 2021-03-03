#include "Polynomial_1.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Poly InitPoly()
{
    PtrToTerm P = (PtrToTerm)malloc(sizeof(PolyTerm));   
    assert(P!=NULL);

    P->coeff = -1;
    P->Next = NULL;

    return P;
}

void AddTerm(Poly P,unsigned int expo,double coeff)
{
    
    PtrToTerm T;

    while(P->Next && P->Next->expo < expo)
    {
        //T = P->Next;
        P = P->Next;
    }
    if(P->Next == NULL || P->Next->expo > expo)
    {
        T = InitPoly();
        T->expo = expo;
        T->coeff = coeff;
        T->Next = P->Next;
        P->Next = T;        
    }
    else
    {
        P->Next->coeff = coeff;
    }    
}

void DeleteTerm(Poly P,unsigned int expo)
{
    PtrToTerm Prev=P;
   
    while(P->Next && P->Next->expo < expo)
    {
        Prev = P->Next;
        P = P->Next;
    }

    if(P->Next == NULL || P->Next->expo > expo)
    {
       printf("ERROR: No polynomial term with exponent %d to delete\n",expo);     
    }
    else
    {
        Prev = P->Next;
        P->Next = P->Next->Next;
        free(Prev);
    }

}