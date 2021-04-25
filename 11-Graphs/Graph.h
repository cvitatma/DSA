
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<stdio.h>

typedef struct stGraph * Graph;
typedef struct stNode * Node;
typedef struct stSPTable * SPTable;
typedef int Vertex;
typedef int Key;

#define WHITE  1
#define GRAY   0
#define BLACK -1
#define INFTY  10000
#define UNKNOWN -1
#define NOTVERTEX -1

Graph   CreteateGraph(int iNumber_of_vertices);
void    InsertEdge(Graph G, Vertex u, Vertex v);
void    BFS(Graph G, Vertex s);
void    DFS(Graph G, Vertex s);
SPTable Dijstra(Graph G, float **c);
SPTable BellmanFord(Graph G, float **c);
SPTable Prim(Graph G, float **c);

struct stGraph{
    int iN;
    Node *pVertex;
};

struct stNode{
    Vertex iVertexID;
    Node pNext;
};

struct stSPTable
{
    int *pKnown;
    float *pdistance_to_source;
    Vertex *pPrevious_vertex;
};

#endif
