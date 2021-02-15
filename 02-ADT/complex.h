// 2D Complex Number ADT
#ifndef __COMPLEX2_H__
#define __COMPLEX2_H__

typedef struct complex2_ complex2;

struct complex2_ {
    double a; // real
    double b; // imaginary
};

complex2 Cx2Create(double real,double imag);
double Cx2Arg(const complex2 cx); // theta
double Cx2Mod(const complex2 cx); // |cx|
void Cx2Print(const complex2 cx); // print the complex number

complex2 Cx2Add(const complex2 c1,const complex2 c2); // complex addition
complex2 Cx2Mul(const complex2 c1,const complex2 c2); // complex multiplication
complex2 Cx2Inv(const complex2 cx); // complex reciprocal 
complex2 Cx2Conj(const complex2 cx); // complex conjugate

#endif
