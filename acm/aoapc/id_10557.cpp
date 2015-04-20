/**
 * @file id_10557.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-20
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
#define MAXVEX 100              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE

typedef struct {
    int key;
    int color;
    int min_path_distance;
    int min_path_parent_index;
} VertexType;                  // vertex data type

// edge node to record the adjacent vertex node for a vertex node
typedef struct EdgeNode {
    int adjvex_index;          // the adjacent vertex node position in array
    struct EdgeNode* next;     // next edge node
} EdgeNode;

// vertex node to record the data for a vertex node
typedef struct VertexNode {
    VertexType data;           // vertex data
    EdgeNode *firstedge;       // first edge node pointer
}VertexNode; 

// graph data structure
typedef struct {
    VertexNode adj[MAXVEX + 2];
    int numVertexes;
} Graph;

// create graph method
bool CreateGraph(Graph& G)
{
    // input graph numVertexes
    cin >> G.numVertexes;
    // unavaliable graph
    if (G.numVertexes <= 0) return false;
    // get graph data from input
    for (int index = 0; index < G.numVertexes; index++) {
        // get key and set negative
        cin >> G.adj[index].data.key;
        G.adj[index].data.key *= -1;
        // initialize edge information
        G.adj[index].firstedge = NULL;
        // get edge information
        int num_edge;
        cin >> num_edge;
        while (num_edge--) {
            int i;
            cin >> i;
            EdgeNode* e = new EdgeNode;
            e->next = G.adj[index].firstedge;
            e->adjvex_index = i - 1;
            G.adj[index].firstedge = e;
        }
    }
    return true;
}
// display graph key and edge
void DisplayGraphKeyEdge(Graph& G)
{
    for (int index = 0; index < G.numVertexes; index++) {
        cout << "index: " << index
            << ",key: " << G.adj[index].data.key << endl;
        EdgeNode* temp = G.adj[index].firstedge;
        while (temp) {
            cout << "  have edge with: " << temp->adjvex_index << endl;
            temp = temp->next;
        }
    }
}
// DFS method
bool DFS_SOURCE_TARGET(Graph& G, int s_index, int t_index)
{
#ifndef ONLINE_JUDGE
    cout << "DFS visit : " << s_index << endl;
#endif
    // DFS to target vertex
    if (s_index == t_index) return true;
    bool r = false;
    // set temp vertex as visit
    G.adj[s_index].data.color = BLACK;
    // get next vertex by edge
    EdgeNode* temp = G.adj[s_index].firstedge;
    while (temp) {
        if (G.adj[temp->adjvex_index].data.color == WHITE)
            r |= DFS_SOURCE_TARGET(G, temp->adjvex_index, t_index);
        temp = temp->next;
    }
    return r;
}
// Bellman-Ford method
// minimum path initialization
void min_path_init(Graph &G, int s_index)
{
    for (int index = 0; index < G.numVertexes; index++) {
        G.adj[s_index].data.color = WHITE;
        G.adj[index].data.min_path_distance = INFINITY;
        G.adj[index].data.min_path_parent_index = -1;
    }
    G.adj[s_index].data.min_path_distance = 0;
}
// minimum path relaxation
void min_path_relax(Graph &G, int u_index, int v_index, int uv_weight)
{
    if (G.adj[u_index].data.min_path_distance == INFINITY) {
        return;
    } else if (G.adj[u_index].data.min_path_distance >= 100) {
        return;
    } else if (G.adj[v_index].data.min_path_distance >
            G.adj[u_index].data.min_path_distance + uv_weight) {
        G.adj[v_index].data.min_path_distance =
            G.adj[u_index].data.min_path_distance + uv_weight;
        G.adj[v_index].data.min_path_parent_index = u_index;
#ifndef ONLINE_JUDGE
        cout << "relax: u_index: " << u_index << ", v_index: " <<
            v_index << endl;
        cout << "after relax: u_distance: " <<
            G.adj[u_index].data.min_path_distance << ", v_distance: " <<
            G.adj[v_index].data.min_path_distance << endl;
#endif
    }
}
// minimum path check
bool min_path_check(Graph &G, int u_index, int v_index, int uv_weight)
{
    if (G.adj[u_index].data.min_path_distance == INFINITY) {
        return false;
    } else if (G.adj[u_index].data.min_path_distance >= 100) {
        return false;
    } else if (G.adj[v_index].data.min_path_distance >
            G.adj[u_index].data.min_path_distance + uv_weight) {
#ifndef ONLINE_JUDGE
        cout << "relax check: u_index: " << u_index << ", v_index: " <<
            v_index << endl;
        cout << "relax check: u_distance: " <<
            G.adj[u_index].data.min_path_distance << ", v_distance: " <<
            G.adj[v_index].data.min_path_distance << endl;
#endif
        return true;
    }
    return false;
}
// bellman ford
bool bellman_ford(Graph& G, int s_index)
{
    // init
    min_path_init(G, s_index);
    // relax
    EdgeNode* temp;
    int i_time = 0;
    while (i_time++ < G.numVertexes - 1) {
        // trace edge
        for (int i = 0; i < G.numVertexes; i++) {
            temp = G.adj[i].firstedge;
            while (temp) {
                // relax for each edge
                min_path_relax(G, i, temp->adjvex_index,
                        G.adj[temp->adjvex_index].data.key);
                temp = temp->next;
            }
        }
    }
    // check if negative weight path exist
    for (int i = 0; i < G.numVertexes; i++) {
        temp = G.adj[i].firstedge;
        while (temp) {
            // check for each edge
            if (min_path_check(G, i, temp->adjvex_index,
                        G.adj[temp->adjvex_index].data.key)) {
                // init for DFS
                for (int index = 0; index < G.numVertexes; index++)
                    G.adj[index].data.color = WHITE;
                // check if can go to target index
                if (DFS_SOURCE_TARGET(G, i, G.numVertexes - 1))
                    return true;
            }
            temp = temp->next;
        }
    }
    if (G.adj[G.numVertexes - 1].data.min_path_distance < 100)
        return true;
    else
        return false;
}
void DisplayMinPath(Graph& G, int s_index, int v_index)
{
    if (s_index == v_index) {
        cout << G.adj[s_index].data.key << " ";
    } else if (G.adj[v_index].data.min_path_parent_index == -1) {
        cout << "no path from " << G.adj[s_index].data.key <<
            " to " << G.adj[v_index].data.key << endl;
    } else {
        DisplayMinPath(G, s_index, G.adj[v_index].data.min_path_parent_index);
        cout << G.adj[v_index].data.min_path_distance << " ";
    }
}

void DisplayMinDist(Graph& G)
{
    for (int index = 0; index < G.numVertexes; index++) {
        // if (G.adj[index].data.min_path_distance == INFINITY &&
        //         G.adj[index].data.min_path_parent_index == -1)
        //     continue;
        cout << "path index: " << index << endl;
        cout << "path key: " << G.adj[index].data.key << endl;
        cout << "distance: " << G.adj[index].data.min_path_distance << endl;
        if (G.adj[index].data.min_path_parent_index == -1) {
            cout << " parent key: -1" << endl;
        } else {
            cout << " parent key: " <<
                G.adj[G.adj[index].data.min_path_parent_index].data.key
                << endl;
            cout << " parent index: " << index << endl;
        }
    }
}
int main(void)
{
    Graph G;
    while (CreateGraph(G)) {
        // DisplayGraphKeyEdge(G);
        if (bellman_ford(G, 0))
            cout << "winnable" << endl;
        else
            cout << "hopeless" << endl;
        // DisplayMinPath(G, 0, G.numVertexes - 1);
        // DisplayMinDist(G);
    }
    return 0;
}

