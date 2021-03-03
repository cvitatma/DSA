#ifndef __POLYELEM_H
#define __POLYELEM_H

typedef struct PolyTerm PTerm;
typedef struct PolyTerm* Poly;

struct PolyTerm {
    unsigned int expo;
    double coeff;
    struct PolyTerm* Next;

};

#endif