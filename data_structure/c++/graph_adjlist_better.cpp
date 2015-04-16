/**
 * @file graph_adjlist.c
 * @brief graph data structure by adjacent list
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

// edge node to record the adjacent vertex node for a vertex node
typedef struct EdgeNode {
    int adjvex_index;          // the adjacent vertex node position in array
    EdgeType weight;           // edge weight
    struct EdgeNode* next;     // next edge node
}EdgeNode;

// vertex node to record the data for a vertex node
typedef struct VertexNode {
    VertexType data;           // vertex data
    EdgeNode *firstedge;       // first edge node pointer
}VertexNode; 

// graph data structure
typedef struct {
    VertexNode adj[MAXVEX];
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
        G.adj[index].data.key = temp;
        G.adj[index].firstedge = NULL;
    }
    cout << "input edge each by two vertex index(0) and their weight:" << endl;
    for (int index = 0; index < G.numEdges; index++) {
        int i, j, w;
        cin >> i >> j >> w;
        cout << i << j << w << endl;
        EdgeNode* e = new EdgeNode;
        e->adjvex_index = j;
        e->weight = w;
        e->next = G.adj[i].firstedge;
        G.adj[i].firstedge = e;
        if (!G.have_direction && i != j) {
            e = new EdgeNode;
            e->adjvex_index = i;
            e->weight = w;
            e->next = G.adj[j].firstedge;
            G.adj[j].firstedge = e;
        }
    }
}

// BFS method
void BFS(Graph& G, int s_index) {
    for (int index = 0; index < G.numVertexes; index++) {
        G.adj[index].data.color = WHITE;
        G.adj[index].data.distance = INFINITY;
        G.adj[index].data.parent_index = -1;
    }
    G.adj[s_index].data.color = GRAY;
    G.adj[s_index].data.distance = 0; 
    G.adj[s_index].data.parent_index = -1;
    queue<int> q;
    q.push(s_index);
    EdgeNode* temp;
    while(!q.empty()) {
        int top_index = q.front();
        q.pop();
        temp = G.adj[top_index].firstedge;
        cout << "pop: " << G.adj[top_index].data.key << endl;
        while (temp) {
            if (G.adj[temp->adjvex_index].data.color == WHITE) {
                G.adj[temp->adjvex_index].data.color = GRAY;
                G.adj[temp->adjvex_index].data.distance =
                    G.adj[top_index].data.distance + 1;
                G.adj[temp->adjvex_index].data.parent_index = top_index;
                q.push(temp->adjvex_index);
            }
            temp = temp->next;
        }
        G.adj[top_index].data.color = BLACK;
    }
}

void display_bfs_path(Graph& G, int s_index, int v_index)
{
    if (s_index == v_index) {
        cout << G.adj[s_index].data.key << " ";
    } else if (G.adj[v_index].data.parent_index == -1) {
        cout << "no path from " << G.adj[s_index].data.key <<
            " to " << G.adj[v_index].data.key << endl;
    } else {
        display_bfs_path(G, s_index, G.adj[v_index].data.parent_index);
        cout << G.adj[v_index].data.key << " ";
    }
}

void display_bfs_distance(Graph& G)
{
    for (int index = 0; index < G.numVertexes; index++) {
        if (G.adj[index].data.distance == INFINITY &&
                G.adj[index].data.parent_index == -1)
            continue;
        cout << "key: " << G.adj[index].data.key << endl;
        cout << " distance: " << G.adj[index].data.distance << endl;
        if (G.adj[index].data.parent_index == -1)
            cout << " parent key: -1" << endl;
        else
            cout << " parent key: " <<
                G.adj[G.adj[index].data.parent_index].data.key << endl;
    }
}

// DFS method
static int time_note = 0;

void DFS_VISIT(Graph& G, int index)
{
    G.adj[index].data.time_d = ++time_note;
    G.adj[index].data.color = GRAY;
    EdgeNode* temp = G.adj[index].firstedge;
    cout << "visit: " << G.adj[index].data.key << endl;
    while (temp) {
        if (G.adj[temp->adjvex_index].data.color == WHITE) {
            G.adj[temp->adjvex_index].data.parent_index = index;
            DFS_VISIT(G, temp->adjvex_index);
        }
        temp = temp->next;
    }
    G.adj[index].data.color = BLACK;
    G.adj[index].data.time_f = ++time_note;
}

void DFS(Graph& G) {
    for (int index = 0; index < G.numVertexes; index++) {
        G.adj[index].data.color = WHITE;
        G.adj[index].data.parent_index = -1;
    }
    time_note = 0;
    for (int index = 0; index < G.numVertexes; index++) {
        if (G.adj[index].data.color == WHITE)
            DFS_VISIT(G, index);
    }
}

void display_dfs_time(Graph& G)
{
    for (int index = 0; index < G.numVertexes; index++) {
        cout << "key: " << G.adj[index].data.key << endl;
        cout << " time: " << G.adj[index].data.time_d << " / " <<
            G.adj[index].data.time_f << endl;
        if (G.adj[index].data.parent_index == -1)
            cout << " parent key: -1" << endl;
        else
            cout << " parent key: " <<
                G.adj[G.adj[index].data.parent_index].data.key << endl;
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

