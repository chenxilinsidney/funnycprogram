/**
 * @file graph_adjlist.c
 * @brief graph data structure by adjacent list
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-13
 */

#include <iostream>
using namespace std;

#define MAXVEX 10              // maximum vertex numbers in the graph
typedef int VertexType;        // vertex data type
typedef int EdgeType;          // edge weight type

// edge node to record the adjacent vertex node for a vertex node
typedef struct EdgeNode {
    int adjvex;                // the adjacent vertex node position in array
    EdgeType weight;           // edge weight
    struct EdgeNode* next;     // next edge node
}EdgeNode;

// vertex node to record the data for a vertex node
typedef struct VertexNode {
    VertexType data;           // vertex data
    EdgeNode *firstedge;       // first edge node pointer
}VertexNode; 

// graph
typedef struct {
    VertexNode adj[MAXVEX];
    int numVertexes;
    int numEdges;
}Graph;

Graph* CreateGraph()
{
    Graph* G = new Graph;
    cout << "input vertex num and edge num:" << endl;
    cin >> G->numVertexes >> G->numEdges;
    cout << "input vertex data one by one:" << endl;
    for (int index = 0; index < G->numVertexes; index++) {
        cin >> G->adj[index].data;
        G->adj[index].firstedge = NULL;
    }
    cout << "input edge each by two vertex index(begin from 0):" << endl;
    for (int index = 0; index < G->numEdges; index++) {
        int i, j;
        cin >> i >> j;
        EdgeNode* e = new EdgeNode;
        e->adjvex = j;
        e->next = G->adj[i].firstedge;
        G->adj[i].firstedge = e;
#define NODRECTIONGRAPH
#ifdef NODRECTIONGRAPH
        e= new EdgeNode;
        e->adjvex = i;
        e->next = G->adj[j].firstedge;
        G->adj[j].firstedge = e;
#endif
    }
}

int main(void)
{
    Graph* G = CreateGraph();
    return 0;
}

