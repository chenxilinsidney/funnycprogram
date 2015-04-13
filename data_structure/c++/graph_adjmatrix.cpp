/**
 * @file graph_adjmatrix.c
 * @brief graph data structure by adjacent matrix
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-13
 */

#include <iostream>
using namespace std;

#define MAXVEX 10              // maximum vertex numbers in the graph
typedef int VertexType;        // vertex data type
typedef int EdgeType;          // edge weight type
#define INFINITY 65535         // set as infinity value

// graph
typedef struct {
    VertexType vertex[MAXVEX];    // vertex list
    EdgeType arc[MAXVEX][MAXVEX]; // adjacent matrix
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
        cin >> G->vertex[index];
    }
    // initial adjacent matrix
    for (int index_i = 0; index_i < G->numVertexes; index_i++)
        for (int index_j = 0; index_j < G->numVertexes; index_j++)
            G->arc[index_i][index_j] = INFINITY;
    cout << "input edge each by two vertex index and weight:" << endl;
    for (int index = 0; index < G->numEdges; index++) {
        int i, j, w;
        cin >> i >> j >> w;
        G->arc[i][j] = w;
#define NODRECTIONGRAPH
#ifdef NODRECTIONGRAPH
        G->arc[j][i] = w;
#endif
    }
}

int main(void)
{
    Graph* G = CreateGraph();
    return 0;
}

