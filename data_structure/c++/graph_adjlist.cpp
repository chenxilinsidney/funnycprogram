/**
 * @file graph_adjlist.c
 * @brief graph data structure by adjacent list
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
bool visit[MAXVEX] = {0};

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
        cin.get();
        G->adj[index].firstedge = NULL;
    }
    cout << "input edge each by two vertex index(begin from 0):" << endl;
    for (int index = 0; index < G->numEdges; index++) {
        int i, j, w;
        cin >> i >> j >> w;
        cout << i << j << w << endl;
        EdgeNode* e = new EdgeNode;
        e->adjvex = j;
        e->weight = w;
        e->next = G->adj[i].firstedge;
        G->adj[i].firstedge = e;
#define NODRECTIONGRAPH
#ifdef NODRECTIONGRAPH
        e= new EdgeNode;
        e->adjvex = i;
        e->weight = w;
        e->next = G->adj[j].firstedge;
        G->adj[j].firstedge = e;
#endif
    }
    return G;
}

void BFS(Graph* G) {
    memset(visit, 0, sizeof(visit[0]) * MAXVEX);
    queue<EdgeNode*> q;
    EdgeNode* temp;
    for (int index = 0; index < G->numVertexes; index++) {
        if (!visit[index]) {
            visit[index] = true;
            q.push(G->adj[index].firstedge);
            cout << " from vertex data: " <<
                G->adj[index].data << endl;
            while (!q.empty()) {
                temp = q.front();
                if (temp && !visit[temp->adjvex]) {
                    cout << "get weight: " << temp->weight <<
                        " to " << temp->adjvex << endl;
                    visit[temp->adjvex] = true;
                    q.push(temp->next);
                }
                q.pop();
            }
        }
    }
}

void DFS_VISIT(Graph* G, int index)
{
    visit[index] = true;
    cout << "vertex data: " << G->adj[index].data << endl;
    EdgeNode* temp = G->adj[index].firstedge;
    while (temp) {
        if (!visit[temp->adjvex])
            DFS_VISIT(G, temp->adjvex);
        temp = temp->next;
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

