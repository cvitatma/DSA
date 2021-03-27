
#ifndef _HASTABLE_H_

#define _HASTABLE_H

typedef struct stHT * HashTable;
typedef struct stNode * Node;
typedef int Element;
typedef int Key;
#define  _invalid -5555;

HashTable   CreateHashTable(int iTableSize);
void        InsertElement(Element n, HashTable myHt);
int         GetNoElements(Element iKey, HashTable myHt);
void        DeleteElement(Element iKey, HashTable myHt);
void        DeleteHashTable(HashTable myHt);
void        EmptyTable(HashTable myHt);
Node        FindInTable(Element n, HashTable myHt);
Key         getHash(Element n,HashTable myHt);
HashTable   ReHash(HashTable myHt);

struct stHT{
    int iTableSize;
    Node *pStart;
};

struct stNode{
    Element iElement;
    int iArryofNoUse[1000000];
    Node pNext;
};

#endif