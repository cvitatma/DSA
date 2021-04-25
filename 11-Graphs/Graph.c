#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "queue.h"

/////////////////////////////////////////////
/////////////////// Grpah.c ////////////
// This file containts implemnetaion of HashTable
/////////////////////////////////////////////



/////////////////////////////////////////////
// Function CreateEmptyGraph
// Inputs   number of vertex
// Outputs  Pointer to the the graph
/////////////////////////////////////////////
Graph   CreateGraph(int iNumber_of_vertices)
{
    int i=0;
    Graph G;

    // First allocate memory 
    G = malloc(sizeof(struct stGraph));
    if( G == NULL)
    {
        printf("Memory Full!!\n");
        exit(0);
    }
    G->iN       = iNumber_of_vertices;
    G->pVertex  = malloc(iNumber_of_vertices*sizeof(struct stNode));
    if( G->pVertex == NULL)
    {
        printf("Memory Full!!\n");
        exit(0);
    }

    // Create Empty Graph
    for (i=0;i<iNumber_of_vertices;i++)
    {
        G->pVertex[i]->iVertexID    = i;
        G->pVertex[i]->pNext        = NULL;
    }
    return G;
}

////////////////////////////////////////////////////
//// Insert  Edge (u,v) in Grpah                  //
//   Inputs: Graph, vertex u, vertex v            //
//   Note that, one can also store edge cost in each
//   node along with the vertex id. In current 
//   implementation, it is assumed that cost function
//   will be provided seperately.                 //
////////////////////////////////////////////////////
void InsertEdge(Graph G, Vertex u, Vertex v)
{
    int i,found=0;
    Node temp;
    Vertex w;

    // First check if the edge already exists.
    temp    = G->pVertex[u];
    while(temp->pNext != NULL)
    {
        w = temp->pNext->iVertexID;
        if(w==v)
            found=1;
        temp = temp->pNext;
    }

    // If is is not already there.
    if(!found)
    {
        temp                    = (Node) malloc(sizeof(struct stNode));
        temp->iVertexID         = v;
        temp->pNext             = G->pVertex[u]->pNext;
        G->pVertex[u]->pNext    = temp;

    }
    return;
}

//////////////// BFS(G,s) /////////////////
//// Given a graph G and node s, this routine
//// vists all the nodes in the graph reachable 
//// in breadth first manner.
//////////////////////////////////////////
void    BFS(Graph G, Vertex s)
{
    int     i,N;
    int     *pColour;
    Vertex  u,v;
    Queue   Q;
    Node    temp;

    N       = G->iN;
    pColour = (int *)malloc(N*sizeof(int));
    if( pColour == NULL)
    {
        printf("Memory Full!!\n");
        exit(0);
    }

    // Initialize all nodes to white/not visited
    for(i=0;i<G->iN;i++)
    {
        u           = G->pVertex[i]->iVertexID;
        pColour[u]  = WHITE;
    }

    pColour[s] = GRAY; // Gray nodes are added to the queue
    Q = CreateEmptyQueue();
    Enqueue(Q,s);

    while(IsQueueEmpty)
    {
        u       = Dequeue(Q);
        temp    = G->pVertex[u];
        while(temp->pNext != NULL)
        {
            v           = temp->pNext->iVertexID;
            if (pColour[v] == WHITE)
            {
                pColour[v]  = GRAY; // Gray nodes are added to the queue
                Enqueue(Q,v);   
            }
            temp = temp->pNext;
        }
        pColour[u]      = BLACK;

    }
    return;
}

//////////////// DFS(G,s) /////////////////
//// Given a graph G and node s, this routine
//// vists all the nodes in the graph reachable 
//// in depth first manner.
//////////////////////////////////////////

void DFS(Graph G, Vertex s)
{
    int i, N;
    Vertex v;
    char *pVisited;
    Node temp;

    // num vertices
    N = G->iN;
    // mark all vertices unvisited
    pVisited = (char *) malloc(sizeof(char)*N);
    for(i=0;i<N;i++)
    {
        v = G->pVertex[i]->iVertexID;
        pVisited[v] = 0;
    }

    temp = G->pVertex[s];
    while(temp->pNext != NULL)
    {
        v= temp->pNext->iVertexID;
        if(pVisited[v] == 0)
            DFS_visit(G,v,pVisited);
        temp = temp->pNext;
    }
        pVisited[s] = 1;

    return;
}

void DFS_visit(Graph G, Vertex s, char* pVisited)
{
    Node temp;
    Vertex v;

    temp = G->pVertex[s];
    while(temp->pNext != NULL)
    {
        v= temp->pNext->iVertexID;
        if(pVisited[v] == 0)
            DFS_visit(G,v,pVisited);
        temp = temp->pNext;
    }
    pVisited[s] = 1;            
    return;
}

/////////////////////// Dijstra Algorithm for SPP 
//// SPTable Dijstra(Graph G, float **c)
//   Inputs: Graph G and cost function c
//   Output: Table containing information
//           about SP from Vertex 0. Function also prints 
//           SP for all nodes. can be commented if not required
//   Assumptions c[][] >=0
//////////////////////////////////////
SPTable Dijstra(Graph G, float **c)
{
    SPTable myTable;
    int i,j,N;
    PQueue Q;
    Vertex u,v;
    Node temp;

    // Allocate the memory to hold the Dijsktra table
    N= G->iN;
    myTable = (SPTable)malloc(sizeof(struct stSPTable));
    if(myTable == NULL)
    {
        exit(0);
    }
    myTable->pKnown                 = (int *)malloc(N*sizeof(int));
    myTable->pdistance_to_source    = (float *)malloc(N*sizeof(float));
    myTable->pPrevious_vertex       = (Vertex *)malloc(N*sizeof(Vertex));

    ////
    // Initialize the table
    for(i=0;i<N;i++)
    {
        myTable->pKnown[i]                = 0;
        myTable->pdistance_to_source[i]   = c[i][0];
        myTable->pPrevious_vertex[i]      = UNKNOWN;              
    }

    // Create Priority Queue and Put all the element 
    Q = CreateEmptyPriorityQueue();
    for(i=0;i<N;i++)
        Priority_Enqueue(Q,(Element)i,(Key)myTable->pdistance_to_source[i]); // Some implementation of queuues with extract min support

    // Whlie there is a node for which shortest path is not known
    while(!IsPQueueEmpty(Q))
    {
        // u will be next node for which we now know the shortest path.
        u = (Vertex)ExtractMin(Q);

        myTable->pKnown[u] = 1;
        temp    = G->pVertex[u];
        // for all neighbours of u for whom SP is not known, 
        // check if shorter path is available through u.
        while(temp->pNext != NULL)
        {
            v           = temp->pNext->iVertexID;
            if( (!myTable->pKnown[v]) && (myTable->pdistance_to_source[u]+c[u][v] < myTable->pdistance_to_source[v] ) )
            {
                // RELAX operation from pseudo code.
                myTable->pdistance_to_source[v] = myTable->pdistance_to_source[u]+c[u][v]; // Update dv
                myTable->pPrevious_vertex[v]    = u; // pv
                DecreaseKey(Q,(Element)v, (Key)myTable->pdistance_to_source[v]);
            }
            temp = temp->pNext;
        }
    }

    // Print SP for all the nodes
    for(i=1;i<N;i++)
    {
        printf("Shortest Path from Vertex 0 to %d \n",i);
        PrintPath_Dijsktra(myTable, i);
    }
    return myTable;
}

// Recussion to get shortest path to Vertex v
void PrintPath_Dijsktra(SPTable myTable, Vertex v)
{
    if(myTable->pPrevious_vertex[v] != NOTVERTEX)
    {
       PrintPath_Dijsktra(myTable,myTable->pPrevious_vertex[v]);
       printf(" -> ");
    }
    printf("%d",v);
    return;
}

/////////////////////// Bellman Ford Algorithm for SPP 
//// SPTable Bellman_Ford(Graph G, float **c)
//   Outputs Shortest Path Table for SP from Vertex 0 to
//   all the vertices. 
//   Assumptions: costs could be -ve but no -ve cost cycle. 
//////////////////////////////////////
SPTable Bellman_Ford(Graph G, float **c)
{
    SPTable myTable;
    int i,j,N;
    PQueue Q;
    Vertex v,w;
    Node temp;

    // Allocate the memory to hold the Dijsktra table
    N= G->iN;
    myTable = (SPTable )malloc(sizeof(struct stSPTable)*N);
    if(myTable == NULL)
    {
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        myTable->pdistance_to_source    = (float *) malloc(N*sizeof(float));
        myTable->pPrevious_vertex       = (Vertex *)malloc(N*sizeof(Vertex));
    }
    ////
    // Initialize the table
    for (i=1;j<N;j++)
    {
        myTable->pdistance_to_source[j]   = INFTY;  // D_j
        myTable->pPrevious_vertex[j]      = UNKNOWN;// p_j
    }
    myTable->pdistance_to_source[0]       = 0;
    myTable->pPrevious_vertex[0]          = NOTVERTEX; 

    // ith iteration cost of SP using i edges. However, need not 
    // be exactly true as we are not maintaining 2-d array.
    for(i=1;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            temp    = G->pVertex[j];
            while(temp->pNext != NULL)
            {
                w           = temp->pNext->iVertexID;
                // D_w^i = min {D_j^{i-1} + c[j][w]}  forall w \in Adj[j]
                if( myTable->pdistance_to_source[j]+c[j][w] < myTable->pdistance_to_source[w] )
                {
                    myTable->pdistance_to_source[w] = myTable->pdistance_to_source[j]+c[j][w]; // Update d_w
                    myTable->pPrevious_vertex[w]    = j;
                }
                temp = temp->pNext;
            }
        }
        // One could keep two array for dv, current round and previous round
        // If d_curr - d_prev = 0, we can stop iterating over i

        }

    /*Ideally there should be code here to check if there is any
    -ve edge weight cycle. Right now, we are assuming no such 
    cycle exists. */        

    for(i=1;i<N;i++)
    {
        printf("Shortest Path from Vertex 0 to %d \n",i);
        PrintPath_Dijsktra(myTable, i);
    }
    return myTable;
}



/////////////////////// Prim's Algorithm for MST 
//// SPTable Prim(Graph G, float **c)
//   This is similar to Dijktra
//   Assumes: G is connected as well as undirected.
//   Outputs Table to MST. 
//   Except start node (here 0), the (v,pv) are the edges 
//   in the returned MST and dv is the cost of that edge (v,pv).
//////////////////////////////////////
SPTable Prim(Graph G, float **c)
{
    SPTable myTable;
    int i,j,N;
    PQueue Q;
    Vertex u,v;
    Node temp;

    // Allocate the memory to hold the Dijsktra table
    N= G->iN;
    myTable = (SPTable)malloc(sizeof(struct stSPTable));
    if(myTable == NULL)
    {
        exit(0);
    }
    myTable->pKnown                 = (int *)   malloc(N*sizeof(int));
    myTable->pdistance_to_source    = (float *) malloc(N*sizeof(float));
    myTable->pPrevious_vertex       = (Vertex *)malloc(N*sizeof(Vertex));
    ////
    // Initialize the table
    for(i=0;i<N;i++)
    {
        myTable->pKnown[i]                = 0;
        myTable->pdistance_to_source[i]   = c[i][0];
        myTable->pPrevious_vertex[i]      = UNKNOWN;              
    }

    // Create Priority Queue and Put all the element 
    Q = CreateEmptyPriorityQueue();
    for(i=0;i<N;i++)
        Priority_Enqueue(Q,(Element)i,(Key)myTable->pdistance_to_source[i]); // Some implementation of queuues with extract min support

    while(!IsPQueueEmpty(Q))
    {
        u = (Vertex)ExtractMin(Q);

        myTable->pKnown[u] = 1;
        temp    = G->pVertex[u];
        while(temp->pNext != NULL)
        {
            v           = temp->pNext->iVertexID;
            // Note the difference with Dijkstra is the way we maintain dv
            // Here dv is not the distance to source, but the shortest distance to v
            // from the tree that is already constructed
            if( (!myTable->pKnown[v]) && (myTable->pdistance_to_source[v]  < c[u][v] ) )
            {
                myTable->pdistance_to_source[v] = c[u][v];
                myTable->pPrevious_vertex[v]    = u;
                DecreaseKey(Q,(Element)v, (Key)myTable->pdistance_to_source[v]);
            }
            temp = temp->pNext;
        }
    }

    return myTable;
}
