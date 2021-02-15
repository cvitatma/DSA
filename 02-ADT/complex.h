// 2D Complex Number ADT
#ifndef __COMPLEX2_H__
#define __COMPLEX2_H__

typedef struct complex2_ complex2;

struct complex2_ {
    double a; // real
    double b; // imaginary
};

complex2 CxAdd2(complex2 c1,complex2 c2); // complex addition
complex2 CxMul2(complex2 c1,complex2 c2); // complex multiplication
complex2 CxInv2(complex2 cx); // complex reciprocal 
complex2 CxConj(complex2 cx); // complex conjugate

double CxArg2(complex2 cx); // theta
double CxMod2(complex2 cx); // |cx|

void CxPrint2(complex2 cx); // print the complex number

#endif
