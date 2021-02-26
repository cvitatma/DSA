#ifndef __POLYTERM_H
#define __POLYTERM_H

typedef struct PolyTerm PTerm;
typedef struct PolyTerm* Poly;

struct PolyTerm {
    unsigned long int expo;
    double coeff;
    struct PolyTerm* Next;
};

#endif
