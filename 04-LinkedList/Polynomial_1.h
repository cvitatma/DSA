#ifndef __POLYNOMIAL_1
#define __POLYNOMIAL_1

#include "PolyElem_1.h"

Poly InitPoly();

void AddTerm(Poly P,unsigned int expo,double coeff);
void DeleteTerm(Poly P,unsigned int expo);

Poly PolyAdd(const Poly P1,const Poly P2); 
Poly PolySub(const Poly P1,const Poly P2); 

void DeleteAllTerms(Poly P);
void DeletePoly(Poly* P);

#endif