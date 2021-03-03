#ifndef __POLY_H
#define __POLY_H

#include "PolyElem.h"

Poly InitPoly();

void AddTerm(Poly P,unsigned int expo,double coeff);
void DeleteTerm(Poly P,unsigned int expo);

Poly PolyAdd(const Poly P1,const Poly P2);
Poly PolySubtract(const Poly P1,const Poly P2);

void DeleteAllTerms(Poly P);
void DeletePoly(Poly* P);

#endif