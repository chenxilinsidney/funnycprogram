/**
 * @file id_10305.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-22
 */

#include <iostream>
#include <limits>

using namespace std;

enum {
    WHITE,
    GRAY,
    BLACK,
};

#define MAXVEX 100              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
// topologically sort information by dfs
int topologically_sort_index;
int topologically_sort[MAXVEX];
typedef struct {
    int color;
    int time_d;
    int time_f;
} VertexType;                  // vertex data type
typedef int EdgeType;          // edge weight type
// edge node to record the adjacent vertex node for a vertex node
typedef struct EdgeNode {
    int adjvex_index;          // the adjacent vertex node position in array
    EdgeType weight;           // edge weight
    struct EdgeNode* next;     // next edge node
} EdgeNode;

// vertex node to record the data for a vertex node
typedef struct VertexNode {
    VertexType data;           // vertex data
    EdgeNode *firstedge;       // first edge node pointer
} VertexNode; 

// graph data structure
typedef struct {
    VertexNode adj[MAXVEX];
    int numVertexes;
    int numEdges;
} Graph;
// create graph method
bool CreateGraph(Graph& G)
{
    // input vertex num and edge num
    cin >> G.numVertexes >> G.numEdges;
    if (G.numVertexes == 0 && G.numEdges == 0) return false;
    // init color flag and edge info
    for (int i = 0; i < G.numVertexes; i++) {
        G.adj[i].data.color = WHITE;
        G.adj[i].firstedge = NULL;
    }
    // input edge information
    for (int index = 0; index < G.numEdges; index++) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        EdgeNode* e = new EdgeNode;
        e->adjvex_index = j;
        e->next = G.adj[i].firstedge;
        G.adj[i].firstedge = e;
    }
    return true;
}
// DFS method
static int time_note = 0;
void DFS_VISIT(Graph& G, int index)
{
    G.adj[index].data.time_d = ++time_note;
    G.adj[index].data.color = GRAY;
    EdgeNode* temp = G.adj[index].firstedge;
    while (temp) {
        if (G.adj[temp->adjvex_index].data.color == WHITE) {
            DFS_VISIT(G, temp->adjvex_index);
        }
        temp = temp->next;
    }
    G.adj[index].data.color = BLACK;
    G.adj[index].data.time_f = ++time_note;
    // for topologically sort
    topologically_sort[topologically_sort_index++] = index;
}
void DFS(Graph& G) {
    for (int index = 0; index < G.numVertexes; index++)
        G.adj[index].data.color = WHITE;
    // for topologically sort
    topologically_sort_index = 0;
    // for DFS
    time_note = 0;
    for (int index = 0; index < G.numVertexes; index++)
        if (G.adj[index].data.color == WHITE)
            DFS_VISIT(G, index);
}
void DisplayTopoSort(Graph& G)
{
    // topologically sort
    DFS(G);
    for (int i = topologically_sort_index - 1; i >= 1; i--)
        cout << topologically_sort[i] + 1 << " ";
    cout << topologically_sort[0] + 1 << endl;
}
int main(void)
{
    Graph G;
    while (CreateGraph(G)) {
        DisplayTopoSort(G);
    }
    return 0;
}
