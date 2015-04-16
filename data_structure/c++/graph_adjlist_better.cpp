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

#define MAXVEX 30              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
// topologically sort information by dfs
int topologically_sort_index;
int topologically_sort[MAXVEX];
typedef struct {
    char key;
    int color;
    int distance;
    int time_d;
    int time_f;
    int parent_index;
    int prim_min_weight;
    bool prim_processed;
    int prim_parent_index;
    int min_path_distance;
    int min_path_parent_index;
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
        cin >> G.adj[index].data.key;
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
    // for topologically sort
    topologically_sort[topologically_sort_index++] = index;
}

void DFS(Graph& G) {
    for (int index = 0; index < G.numVertexes; index++) {
        G.adj[index].data.color = WHITE;
        G.adj[index].data.parent_index = -1;
    }
    // for topologically sort
    topologically_sort_index = 0;
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

// Prim method
void display_prim_info(Graph& G)
{
    for (int i = 0; i < G.numVertexes; i++) {
        cout << "vertex key: " << G.adj[i].data.key << endl;
        cout << "weight: " << G.adj[i].data.prim_min_weight << endl;
        cout << "flag: " << G.adj[i].data.prim_processed << endl;
        cout << "parent: " << G.adj[i].data.prim_parent_index << endl;
    }

}
void Prim(Graph& G, int s_index)
{
    // initialization
    for (int i = 0; i < G.numVertexes; i++) {
        G.adj[i].data.prim_min_weight = INFINITY;
        G.adj[i].data.prim_processed = false;
        G.adj[i].data.prim_parent_index = -1;
    }
    G.adj[s_index].data.prim_min_weight = 0;
    int num_edge = 0;
    int min_key;
    int min_index;
    EdgeNode* temp;
    while (num_edge++ < G.numVertexes) {
        // get minimum key vertex in un-processed vertex
        min_key = INFINITY;
        for (int i = 0; i < G.numVertexes; i++) {
            if (G.adj[i].data.prim_min_weight < min_key &&
                    !G.adj[i].data.prim_processed) {
                min_key = G.adj[i].data.prim_min_weight;
                min_index = i;
            }
        }
        // set process flag
        G.adj[min_index].data.prim_processed = true;
        // new vertex and weight for A
        cout << "get prim key: " <<
            G.adj[min_index].data.key << endl;
        if (G.adj[min_index].data.prim_parent_index != -1)
            cout << " parent key: " <<
                G.adj[G.adj[min_index].data.prim_parent_index].data.key << endl;
        else
            cout << " parent key: -1" << endl;
        cout << " weight: " << G.adj[min_index].data.prim_min_weight << endl;
        // trace edge
        temp = G.adj[min_index].firstedge;
        while (temp) {
            if (!G.adj[temp->adjvex_index].data.prim_processed &&
                    temp->weight <
                    G.adj[temp->adjvex_index].data.prim_min_weight) {
                G.adj[temp->adjvex_index].data.prim_min_weight = temp->weight;
                G.adj[temp->adjvex_index].data.prim_parent_index = min_index;
            }
            temp = temp->next;
        }
    }
}

// Bellman-Ford method
// minimum path initialization
void min_path_init(Graph &G, int s_index)
{
    for (int index = 0; index < G.numVertexes; index++) {
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
    } else if (G.adj[v_index].data.min_path_distance >
            G.adj[u_index].data.min_path_distance + uv_weight) {
        G.adj[v_index].data.min_path_distance =
            G.adj[u_index].data.min_path_distance + uv_weight;
        G.adj[v_index].data.min_path_parent_index = u_index;
    }
}

// minimum path check
bool min_path_check(Graph &G, int u_index, int v_index, int uv_weight)
{
    if (G.adj[u_index].data.min_path_distance == INFINITY) {
        return true;
    } else if (G.adj[v_index].data.min_path_distance >
            G.adj[u_index].data.min_path_distance + uv_weight) {
        return false;
    }
    return true;
}

bool bellman_ford(Graph& G, int s_index)
{
    // init
    min_path_init(G, s_index);
    // relax
    EdgeNode* temp;
    for (int i_time = 0; i_time < G.numVertexes - 1; i_time++) {
        // trace edge
        for (int i = 0; i < G.numVertexes; i++) {
            temp = G.adj[i].firstedge;
            while (temp) {
                // relax for each edge
                min_path_relax(G, i, temp->adjvex_index, temp->weight);
                temp = temp->next;
            }
        }
    }
    // check if negative weight path exist
    for (int i = 0; i < G.numVertexes; i++) {
        temp = G.adj[i].firstedge;
        while (temp) {
            // check for each edge
            if (!min_path_check(G, i, temp->adjvex_index, temp->weight))
                return false;
            temp = temp->next;
        }
    }
    return true;
}

void display_min_path(Graph& G, int s_index, int v_index)
{
    if (s_index == v_index) {
        cout << G.adj[s_index].data.key << " ";
    } else if (G.adj[v_index].data.min_path_parent_index == -1) {
        cout << "no path from " << G.adj[s_index].data.key <<
            " to " << G.adj[v_index].data.key << endl;
    } else {
        display_min_path(G, s_index, G.adj[v_index].data.min_path_parent_index);
        cout << G.adj[v_index].data.key << " ";
    }
}

void display_min_distance(Graph& G)
{
    for (int index = 0; index < G.numVertexes; index++) {
        if (G.adj[index].data.min_path_distance == INFINITY &&
                G.adj[index].data.min_path_parent_index == -1)
            continue;
        cout << "path key: " << G.adj[index].data.key << endl;
        cout << " distance: " << G.adj[index].data.min_path_distance << endl;
        if (G.adj[index].data.min_path_parent_index == -1)
            cout << " parent key: -1" << endl;
        else
            cout << " parent key: " <<
                G.adj[G.adj[index].data.min_path_parent_index].data.key << endl;
    }
}

// DAG-SHORTEST-PATHS
void dag_min_path(Graph& G, int s_index)
{
    // topologically sort
    DFS(G);
    // init
    min_path_init(G, s_index);
    // relax by topologically sort result
    EdgeNode* temp;
    cout << "topologically size: " << topologically_sort_index << endl;
    for (int i = topologically_sort_index - 1; i >= 0; i--) {
        cout << "topologically: " << G.adj[topologically_sort[i]].data.key
            << endl;
        temp = G.adj[topologically_sort[i]].firstedge;
        while (temp) {
            // relax for each edge
            min_path_relax(G, topologically_sort[i],
                    temp->adjvex_index, temp->weight);
            temp = temp->next;
        }
    }
}

int main(void)
{
    // build structure
    Graph G;
    CreateGraph(G);
    cout << "BFS" << endl;
    // BFS(G, 2);
    // display_bfs_path(G, 2, 3);
    // cout << endl;
    // display_bfs_distance(G);
    // cout << endl;
    cout << "DFS" << endl;
    // DFS(G);
    // display_dfs_time(G);
    // cout << endl;
    cout << "Prim" << endl;
    // Prim(G, 0);
    // cout << endl;
    cout << "Bellman-Ford" << endl;
    bool flag_exist = bellman_ford(G, 1);
    cout << flag_exist << endl;
    display_min_path(G, 1, 5);
    cout << endl;
    display_min_distance(G);
    cout << endl;
    cout << "dag_min_path" << endl;
    dag_min_path(G, 1);
    display_min_path(G, 1, 5);
    cout << endl;
    display_min_distance(G);
    cout << endl;
    return 0;
}

