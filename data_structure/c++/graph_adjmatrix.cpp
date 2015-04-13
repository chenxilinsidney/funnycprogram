/**
 * @file graph_adjmatrix.c
 * @brief graph data structure by adjacent matrix
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-13
 */

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAXVEX 10              // maximum vertex numbers in the graph
typedef char VertexType;       // vertex data type
typedef int EdgeType;          // edge weight type
#define INFINITY 65535         // set as infinity value
bool visit[MAXVEX] = {0};

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
        cin.get();
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
    return G;
}

void BFS(Graph* G) {
    memset(visit, 0, sizeof(visit[0]) * MAXVEX);
    queue<int> q;
    for (int index = 0; index < G->numVertexes; index++) {
        if (!visit[index]) {
            visit[index] = true;
            q.push(index);
            while (!q.empty()) {
                int index_i = q.front();
                cout << " from vertex " << index_i << " data: " <<
                    G->vertex[index_i] << endl;
                for (int index_j = 0; index_j < G->numVertexes; index_j++) {
                    if (G->arc[index_i][index_j] != INFINITY &&
                            !visit[index_j]) {
                        visit[index_j] = true;
                        cout << "get weight: " << G->arc[index_i][index_j] <<
                            " to " << index_j << endl;
                        q.push(index_j);
                    }
                }
                q.pop();
            }
        }
    }
}

void DFS_VISIT(Graph* G, int index)
{
    visit[index] = true;
    cout << "vertex data: " << G->vertex[index] << endl;
    for (int index_j = 0; index_j < G->numVertexes; index_j++) {
        if (G->arc[index][index_j] != INFINITY && !visit[index_j])
            DFS_VISIT(G, index_j);
    }
}

void DFS(Graph* G)
{
    memset(visit, 0, sizeof(visit[0]) * MAXVEX);
    for (int index_i = 0; index_i < G->numVertexes; index_i++) {
        if (!visit[index_i])
            DFS_VISIT(G, index_i);
    }
}

int main(void)
{
    Graph* G = CreateGraph();
    cout << "BFS" << endl;
    BFS(G);
    cout << "DFS" << endl;
    DFS(G);
    return 0;
}

