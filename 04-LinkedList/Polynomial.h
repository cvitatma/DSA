#ifndef __POLY_H
#define __POLY_H

#include "PolyTerm.h" // Linked List

// #include "PolyArray.h" // Array

Poly InitPoly();

void AddTerm(Poly P,double coefficient,unsigned long int exponent);
void DeleteTerm(Poly P,unsigned long int exponent);
void UpdateTerm(Poly P,double new_coefficient,unsigned long int exponent);

Poly PolyAdd(const Poly P1,const Poly P2);
Poly PolySubtract(const Poly P1,const Poly P2);

void DeleteAllTerms(Poly P); // retains header node
void DeletePoly(Poly* P); // deletes header node also

#endif