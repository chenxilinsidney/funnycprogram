/**
 * @file graph_adjmatrix.c
 * @brief graph data structure by adjacent matrix
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-13
 */

#include <iostream>
#include <queue>
#include <limits>

using namespace std;

enum {
    WHITE,
    GRAY,
    BLACK
};

#define MAXVEX 10              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
typedef struct {
    int key;
    int color;
    int distance;
    int time_d;
    int time_f;
    int parent_index;
} VertexType;                  // vertex data type
typedef int EdgeType;          // edge weight type

// graph data structure
typedef struct {
    VertexType vertex[MAXVEX];    // vertex list
    EdgeType arc[MAXVEX][MAXVEX]; // adjacent matrix
    int numVertexes;
    int numEdges;
    int have_direction;
}Graph;

// create graph method
void CreateGraph(Graph& G)
{
    cout << "input vertex num and edge num and direction flag:" << endl;
    cin >> G.numVertexes >> G.numEdges >> G.have_direction;
    cout << "input vertex data one by one:" << endl;
    for (int index = 0; index < G.numVertexes; index++) {
        int temp;
        cin >> temp;
        G.vertex[index].key = temp;
    }
    for (int index_i = 0; index_i < G.numVertexes; index_i++)
        for (int index_j = 0; index_j < G.numVertexes; index_j++)
            G.arc[index_i][index_j] = INFINITY;
    cout << "input edge each by two vertex index(0) and their weight:" << endl;
    for (int index = 0; index < G.numEdges; index++) {
        int i, j, w;
        cin >> i >> j >> w;
        cout << i << j << w << endl;
        G.arc[i][j] = w;
        if (!G.have_direction && i != j) {
            G.arc[j][i] = w;
        }
    }
}

// BFS method
void BFS(Graph& G, int s_index) {
    for (int index = 0; index < G.numVertexes; index++) {
        G.vertex[index].color = WHITE;
        G.vertex[index].distance = INFINITY;
        G.vertex[index].parent_index = -1;
    }
    G.vertex[s_index].color = GRAY;
    G.vertex[s_index].distance = 0; 
    G.vertex[s_index].parent_index = -1;
    queue<int> q;
    q.push(s_index);
    while(!q.empty()) {
        int top_index = q.front();
        q.pop();
        cout << "pop: " << G.vertex[top_index].key << endl;
        for (int index = 0; index < G.numVertexes; index++) {
            if (G.arc[top_index][index] != INFINITY &&
                    G.vertex[index].color == WHITE) {
                G.vertex[index].color = GRAY;
                G.vertex[index].distance =
                    G.vertex[top_index].distance + 1;
                G.vertex[index].parent_index = top_index;
                q.push(index);
            }
        }
        G.vertex[top_index].color = BLACK;
    }
}

void display_bfs_path(Graph& G, int s_index, int v_index)
{
    if (s_index == v_index) {
        cout << G.vertex[s_index].key << " ";
    } else if (G.vertex[v_index].parent_index == -1) {
        cout << "no path from " << G.vertex[s_index].key <<
            " to " << G.vertex[v_index].key << endl;
    } else {
        display_bfs_path(G, s_index, G.vertex[v_index].parent_index);
        cout << G.vertex[v_index].key << " ";
    }
}

void display_bfs_distance(Graph& G)
{
    for (int index = 0; index < G.numVertexes; index++) {
        if (G.vertex[index].distance == INFINITY &&
                G.vertex[index].parent_index == -1)
            continue;
        cout << "key: " << G.vertex[index].key << endl;
        cout << " distance: " << G.vertex[index].distance << endl;
        if (G.vertex[index].parent_index == -1)
            cout << " parent key: -1" << endl;
        else
            cout << " parent key: " <<
                G.vertex[G.vertex[index].parent_index].key << endl;
    }
}

// DFS method
static int time_note = 0;

void DFS_VISIT(Graph& G, int index)
{
    G.vertex[index].time_d = ++time_note;
    G.vertex[index].color = GRAY;
    cout << "visit: " << G.vertex[index].key << endl;
    for (int index_j = 0; index_j < G.numVertexes; index_j++) {
        if (G.arc[index][index_j] != INFINITY &&
                G.vertex[index_j].color == WHITE)
            DFS_VISIT(G, index_j);
    }
    G.vertex[index].color = BLACK;
    G.vertex[index].time_f = ++time_note;
}

void DFS(Graph& G) {
    for (int index = 0; index < G.numVertexes; index++) {
        G.vertex[index].color = WHITE;
        G.vertex[index].parent_index = -1;
    }
    time_note = 0;
    for (int index = 0; index < G.numVertexes; index++) {
        if (G.vertex[index].color == WHITE)
            DFS_VISIT(G, index);
    }
}

void display_dfs_time(Graph& G)
{
    for (int index = 0; index < G.numVertexes; index++) {
        cout << "key: " << G.vertex[index].key << endl;
        cout << " time: " << G.vertex[index].time_d << " / " <<
            G.vertex[index].time_f << endl;
        if (G.vertex[index].parent_index == -1)
            cout << " parent key: -1" << endl;
        else
            cout << " parent key: " <<
                G.vertex[G.vertex[index].parent_index].key << endl;
    }
}

int main(void)
{
    // build structure
    Graph G;
    CreateGraph(G);
    cout << "BFS" << endl;
    BFS(G, 2);
    display_bfs_path(G, 2, 3);
    cout << endl;
    display_bfs_distance(G);
    cout << endl;
    cout << "DFS" << endl;
    DFS(G);
    display_dfs_time(G);
    cout << endl;
    return 0;
}

