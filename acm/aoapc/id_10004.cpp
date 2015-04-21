/**
 * @file id_10004.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-21
 */

#include <iostream>
#include <limits>

using namespace std;

enum {
    WHITE,
    BLACK,
    COLOR_A,
    COLOR_B
};

#define MAXVEX 200              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
typedef struct {
    int visit;
    int color;
} VertexType;                  // vertex data type
typedef int EdgeType;          // edge weight type

// edge node to record the adjacent vertex node for a vertex node
typedef struct EdgeNode {
    int adjvex_index;          // the adjacent vertex node position in array
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
    bool have_direction;
} Graph;

// create graph method
bool CreateGraph(Graph& G)
{
    // input vertex num and edge num and set direction flag
    cin >> G.numVertexes;
    if (G.numVertexes == 0) return false;
    cin >> G.numEdges;
    G.have_direction = false;
    // init edge
    for (int index = 0; index < G.numVertexes; index++) {
        G.adj[index].firstedge = NULL;
    }
    for (int index = 0; index < G.numEdges; index++) {
        int i, j;
        cin >> i >> j;
        EdgeNode* e = new EdgeNode;
        e->adjvex_index = j;
        e->next = G.adj[i].firstedge;
        G.adj[i].firstedge = e;
        if (!G.have_direction && i != j) {
            e = new EdgeNode;
            e->adjvex_index = i;
            e->next = G.adj[j].firstedge;
            G.adj[j].firstedge = e;
        }
    }
    return true;
}

// release graph of the edge node
void RelaseGraph(Graph& G)
{
    EdgeNode* temp;
    EdgeNode* temp_next;
    for (int index = 0; index < G.numVertexes; index++) {
        temp = G.adj[index].firstedge;
        while (temp) {
            temp_next = temp->next;
            delete temp;
            temp = temp_next;
        }
    }
}

// DFS method
bool DFS_VISIT(Graph& G, int index, int color)
{
    G.adj[index].data.visit = BLACK;
    G.adj[index].data.color = color;
    EdgeNode* temp = G.adj[index].firstedge;
    int color_next = color == COLOR_A ? COLOR_B : COLOR_A;
    bool flag_return = false;
    while (temp) {
        if (G.adj[temp->adjvex_index].data.visit == WHITE)
            flag_return |= DFS_VISIT(G, temp->adjvex_index, color_next);
        else if (G.adj[temp->adjvex_index].data.color == color) 
            return true;
        temp = temp->next;
    }
    return flag_return;
}

bool DFS(Graph& G)
{
    // init visit
    for (int index = 0; index < G.numVertexes; index++)
        G.adj[index].data.visit = WHITE;
    return DFS_VISIT(G, 0, COLOR_A);
}
// struct for stack
// DFS by own stack array
int stack_own[MAXVEX + 2];
int stack_top = 0;
bool DFS_by_ownstack(Graph& G) {
    // init visit
    for (int index = 0; index < G.numVertexes; index++)
        G.adj[index].data.visit = WHITE;
    EdgeNode* temp;
    int top = 0;
    G.adj[0].data.color = COLOR_A;
    G.adj[0].data.visit = BLACK;
    stack_own[0] = 0;
    stack_top = 0;
    while (stack_top != -1) {
        top = stack_own[stack_top];
        stack_top--;
        temp = G.adj[top].firstedge;
        while (temp) {
            if (G.adj[temp->adjvex_index].data.visit == WHITE) {
                G.adj[temp->adjvex_index].data.visit = BLACK;
                G.adj[temp->adjvex_index].data.color =
                    G.adj[top].data.color == COLOR_A ? COLOR_B : COLOR_A;
                stack_top++;
                stack_own[stack_top] = temp->adjvex_index;
            } else if (G.adj[temp->adjvex_index].data.color ==
                    G.adj[top].data.color) {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}

// display graph visit and color
void DisplayGraphVisit(Graph& G)
{
    cout << "display graph visit: " << endl;
    for (int index = 0; index < G.numVertexes; index++)
        cout << G.adj[index].data.visit << endl;
    cout << "display graph color: " << endl;
    for (int index = 0; index < G.numVertexes; index++)
        cout << G.adj[index].data.color << endl;
}

int main(void)
{
    Graph G;
    while (CreateGraph(G)) {
        if (DFS(G))
        // if (DFS_by_ownstack(G))
            cout << "NOT BICOLORABLE." << endl;
        else
            cout << "BICOLORABLE." << endl;
#ifndef ONLINE_JUDGE
        DisplayGraphVisit(G);
#endif
        RelaseGraph(G);
    }
    return 0;
}
