#ifndef __POLYELEM
#define __POLYELEM

typedef struct PolyTerm PolyTerm;
typedef struct PolyTerm* PtrToTerm;

typedef struct PolyTerm* Poly;

struct PolyTerm {
    int expo;
    double coeff;
    PtrToTerm Next;
};

#endif