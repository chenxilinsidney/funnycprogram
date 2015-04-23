/**
 * @file id_10129.cpp
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

#define MAXVEX 200              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
typedef struct {
    bool exist;
} VertexType;                  // vertex data type
typedef struct {
    int weight;
} EdgeType;                    // edge weight type

// graph data structure
typedef struct {
    VertexType vertex[MAXVEX + 2];    // vertex list
    EdgeType arc[MAXVEX][MAXVEX + 2]; // adjacent matrix
    int numVertexes;
    int numEdges;
} Graph;

// create graph method
bool CreateGraph(Graph& G)
{
    // set vertex num
    if(!(cin >> G.numVertexes)) return false;
    // init exist flag
    for (int index_i = 0; index_i < G.numVertexes; index_i++) {
        G.vertex[index_i].exist = false;
    }
    // input edge num
    cin >> G.numEdges;
    // init edge informaition
    for (int index_i = 0; index_i < G.numVertexes; index_i++)
        for (int index_j = 0; index_j < G.numVertexes; index_j++)
            G.arc[index_i][index_j].weight = 0;
    // input edge information
    for (int index = 0; index < G.numEdges; index++) {
        int i, j;
        cin >> i >> j;
        G.arc[i][j].weight++;
        G.arc[j][i].weight++;
        G.vertex[i].exist = true;
        G.vertex[j].exist = true;
    }
    return true;
}
// display graph edge weight
void DisplayGraphWeight(Graph& G)
{
    cout << "display graph edge count: " << G.numEdges << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << G.arc[i][j].weight << " ";
        }
        cout << endl;
    }
}
// get vertex degree num
int GetEdgeNum(Graph& G, int index)
{
    int sum = 0;
    for (int j = 0; j < G.numVertexes; j++)
        sum += G.arc[index][j].weight;
    return sum;
}
// detect if graph is euler path
bool IsGraphConnected(Graph &G, int start_index);
bool IsGraphEulerCircult(Graph& G)
{
    int edge_num = 0;
    // check the in-degree value and out-degree value
    for (int i = 0; i < G.numVertexes; i++) {
        if (!G.vertex[i].exist) continue;
        edge_num = GetEdgeNum(G, i);
        if (edge_num & 1) {
            return false;
        }
    }
    // get a start vertex
    int start_index = 0;
    for (int i = 0; i < G.numVertexes; i++) {
        if (G.vertex[i].exist) {
            start_index = i;
            break;
        }
    }
    // check if the graph is connected graph for all existed vertex
    return IsGraphConnected(G, start_index);
}
// detect if graph is connected for all exist vertex by set
int set[MAXVEX + 2];
// find set index
int find_set(int index) {
    while (index != set[index]) index = set[index];
    return index;
}
// union two set
void union_set(int index_a, int index_b) {
    set[find_set(index_a)] = find_set(index_b);
}
// init set
void init_set(int set_length) {
    for (int i = 0; i < set_length; i++)
        set[i] = i;
}
bool IsGraphConnected(Graph &G, int start_index)
{
    // init set
    init_set(G.numVertexes);
    for (int i = 0; i < G.numVertexes; i++)
        for (int j = 0; j < G.numVertexes; j++)
            if (G.arc[i][j].weight > 0) union_set(i, j);
    for (int i = 0; i < G.numVertexes; i++)
            if (G.vertex[i].exist && find_set(start_index) != find_set(i))
                return false;
    return true;
}
int main(void)
{
    Graph G;
    while (CreateGraph(G)) {
        if(!IsGraphEulerCircult(G))
            cout << "Not Possible" << endl;
        else
            cout << "Possible" << endl;
    }
    return 0;
}
