/**
 * @file id_10397.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-25
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define MAXVEX 751              // maximum vertex numbers in the graph
typedef struct {
    double x;
    double y;
} VertexType;                  // vertex data type
typedef struct {
    int u;
    int v;
    double weight;
} EdgeType;          // edge weight type
// graph data structure
typedef struct {
    VertexType vertex[MAXVEX + 2];    // vertex list
    EdgeType arc[MAXVEX * (MAXVEX - 1) / 2 + 2];
    int numVertexes;
    int numEdges;
} Graph;

// Union-Find Set
int set[MAXVEX * (MAXVEX - 1) / 2 + 2];
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
int compare_edge(const void* a, const void* b) {
    return ((EdgeType*)a)->weight > ((EdgeType*)b)->weight;
}
// Kruskal method
double Kruskal(Graph &G)
{
    // set vertexes data
    for (int i = 0; i < G.numVertexes; i++)
        cin >> G.vertex[i].x >> G.vertex[i].y;
    // init set
    init_set(G.numVertexes);
    // union by given edges
    int num_edges, ii, jj;
    cin >> num_edges;
    while (num_edges--) {
        cin >> ii >> jj;
        union_set(ii - 1, jj - 1);
    }
    // set edges
    int index_edge = 0;
    for (int i = 0; i < G.numVertexes - 1; i++) {
        for (int j = i + 1; j < G.numVertexes; j++) {
            if (find_set(i) != find_set(j)) {
                G.arc[index_edge].weight = sqrt(
                        (G.vertex[i].x - G.vertex[j].x) *
                        (G.vertex[i].x - G.vertex[j].x) +
                        (G.vertex[i].y - G.vertex[j].y) *
                        (G.vertex[i].y - G.vertex[j].y));
                G.arc[index_edge].u = i;
                G.arc[index_edge].v = j;
                index_edge++;
            }
        }
    }
    G.numEdges = index_edge;
    // sort weight
    qsort(G.arc, G.numEdges, sizeof(G.arc[0]), compare_edge);
    // sum weight
    double weight = 0.0;
    for (int i = 0; i < G.numEdges; i++) {
        if (find_set(G.arc[i].u) != find_set(G.arc[i].v)) {
            weight += G.arc[i].weight;
            union_set(G.arc[i].u, G.arc[i].v);
        }
    }
    return weight;
}

Graph G;
int main(void)
{
    while (cin >> G.numVertexes) {
        double distance = Kruskal(G);
        cout.precision(2);
        cout.setf(std::ios::fixed, std::ios::floatfield);
        cout << distance << endl;
    }
    return 0;
}
