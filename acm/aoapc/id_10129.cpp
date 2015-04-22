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

#define MAXVEX 26              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
typedef struct {
    int color;
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
    int numExistVertexes;
    int numEdges;
    int start_vertex_index;
    int end_vertex_index;
} Graph;

// create graph method
void CreateGraph(Graph& G)
{
    // set vertex num as a - z
    G.numVertexes = MAXVEX;
    // init color flag and exist flag
    for (int index_i = 0; index_i < G.numVertexes; index_i++) {
        G.vertex[index_i].color = WHITE;
        G.vertex[index_i].exist = false;
    }
    // input edge num
    cin >> G.numEdges;
    // init edge informaition
    for (int index_i = 0; index_i < G.numVertexes; index_i++)
        for (int index_j = 0; index_j < G.numVertexes; index_j++)
            G.arc[index_i][index_j].weight = 0;
    // input edge information
    string word;
    for (int index = 0; index < G.numEdges; index++) {
        int i, j;
        cin >> word;
        i = word.front() - 'a';
        j = word.back() - 'a';
        G.arc[i][j].weight += 1;
        G.vertex[i].exist = true;
        G.vertex[j].exist = true;
    }
}
// display graph edge weight
void DisplayGraphWeight(Graph& G)
{
    cout << "display graph edge count: " << G.numEdges << endl;
    for (int i = 0; i < G.numVertexes; i++) {
        for (int j = 0; j < G.numVertexes; j++) {
            cout << G.arc[i][j].weight << " ";
        }
        cout << endl;
    }
}
// get vertex out-degree num
int GetOutEdgeNum(Graph& G, int index)
{
    int sum = 0;
    for (int j = 0; j < G.numVertexes; j++)
        sum += G.arc[index][j].weight;
    return sum;
}
// get vertex in-degree num
int GetInEdgeNum(Graph& G, int index)
{
    int sum = 0;
    for (int i = 0; i < G.numVertexes; i++)
        sum += G.arc[i][index].weight;
    return sum;
}
// detect if graph is euler path
bool IsGraphConnected(Graph &G, int start_index);
bool IsGraphEulerPath(Graph& G)
{
    // init start and end index
    G.start_vertex_index = INFINITY;
    G.end_vertex_index = INFINITY;
    int in_edge_num = 0, out_edge_num = 0;
    // check the in-degree value and out-degree value
    for (int i = 0; i < G.numVertexes; i++) {
        if (!G.vertex[i].exist) continue;
        in_edge_num = GetInEdgeNum(G, i);
        out_edge_num = GetOutEdgeNum(G, i);
        if (in_edge_num + 1 < out_edge_num || out_edge_num + 1 < in_edge_num) {
            // in edge and out edge count illegal
            return false;
        } else if (in_edge_num + 1 == out_edge_num) {
            // get start index and only have one
            if (G.start_vertex_index == INFINITY)
                G.start_vertex_index = i;
            else
                return false;
        } else if (out_edge_num + 1 == in_edge_num) {
            // get end index and only have one
            if (G.end_vertex_index == INFINITY)
                G.end_vertex_index = i;
            else
                return false;
        }
    }
    // start and end index should be a pair
    if ((G.start_vertex_index == INFINITY &&
                G.end_vertex_index != INFINITY) ||
            (G.start_vertex_index != INFINITY &&
             G.end_vertex_index == INFINITY))
        return false;
    // check if the graph is connected graph for all existed vertex
    if (G.start_vertex_index == INFINITY) {
        for (int i = 0; i < G.numVertexes; i++) {
            if (G.vertex[i].exist)
                return IsGraphConnected(G, i);
        }
    } else {
        return IsGraphConnected(G, G.start_vertex_index);
    }
    return true;
}
#if 1
// detect if graph is connected for all exist vertex by DFS
int stack_own[MAXVEX + 4];
int stack_top = 0;
bool IsGraphConnected(Graph &G, int start_index)
{
    // init visit
    int total_exist_vertexes = 0;
    for (int index = 0; index < G.numVertexes; index++)
        if (G.vertex[index].exist) {
            G.vertex[index].color = WHITE;
            total_exist_vertexes++;
        }
    int temp_exist_vertexes = 0;
    int top = 0;
    stack_own[0] = start_index;
    stack_top = 0;
    while (stack_top != -1) {
        top = stack_own[stack_top];
        stack_top--;
        if (G.vertex[top].color == BLACK) continue;
        G.vertex[top].color = BLACK;
        temp_exist_vertexes++;
        for (int index_j = 0; index_j < G.numVertexes; index_j++) {
            if (G.vertex[index_j].exist && G.arc[top][index_j].weight > 0 &&
                    G.vertex[index_j].color == WHITE) {
                stack_top++;
                stack_own[stack_top] = index_j;
            }
        }
        if (temp_exist_vertexes == total_exist_vertexes) break;
    }
    if (temp_exist_vertexes == total_exist_vertexes)
        return true;
    else
        return false;
}
#else
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
#endif
int main(void)
{
    Graph G;
    int num_case;
    cin >> num_case;
    while (num_case--) {
        // create graph
        CreateGraph(G);
        if(IsGraphEulerPath(G))
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;
#ifndef ONLINE_JUDGE
        cout << "start: " << G.start_vertex_index << endl;
        cout << "end: " << G.end_vertex_index << endl;
        DisplayGraphWeight(G);
#endif
    }
    return 0;
}
