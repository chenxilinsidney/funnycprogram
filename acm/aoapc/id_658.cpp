/**
 * @file id_10658.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-25
 */

#include <iostream>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

#define MAXVEX 1048577              // maximum vertex numbers in the graph
#define INF   numeric_limits<int>::max()  // NO VALUE
typedef struct {
    int distance;
    // vertex first edge index
    int first;
} VertexType;                  // vertex data type
// graph data structure
typedef struct {
    VertexType vertex[MAXVEX + 2];    // vertex list
    int numBugBit;
    int numVertexes;
    int numPatches;
    int numEdges;
    // edge u and v and weight and next edge for same vertex
    int u[MAXVEX + 2];
    int v[MAXVEX + 2];
    int weight[MAXVEX + 2];
    int next[MAXVEX + 2];
} Graph;
void SparsePatch(string& in, int* in_mask, int* in_value)
{
    unsigned int mask = 0;
    unsigned int value = 0;
    for (size_t i = 0; i < in.size(); i++) {
        if (in[i] == '0') {
            mask <<= 1;
            value <<= 1;
        } else if (in[i] == '+') {
            mask = (mask << 1) + 1;
            value = (value << 1) + 1;
        } else {
            mask = (mask << 1) + 1;
            value <<= 1;
        }
    }
    *in_mask = mask;
    *in_value = value;
}
    // if ((vertex & mask) == value)
    // return (vertex & ~mask) + (value & mask);
// create graph method
bool CreateGraph(Graph& G)
{
    // set graph vertexes numbers
    cin >> G.numBugBit >> G.numPatches;
    if (G.numBugBit == 0) return false;
    G.numVertexes = pow(2, G.numBugBit);
    // init vertex
    for (int i = 0; i < G.numVertexes; i++) G.vertex[i].first = -1;
    // set edges
    int weight, in_mask, in_value, out_mask, out_value;
    string in, out;
    int num_edge = 0;
    for (int k = 0; k < G.numPatches; k++) {
        cin >> weight >> in >> out;
        SparsePatch(in, &in_mask, &in_value);
        SparsePatch(out, &out_mask, &out_value);
        for (int i = 0; i < G.numVertexes; i++) {
            if ((i & in_mask) == in_value) {
                int j = (i & ~out_mask) + (out_value & out_mask);
#ifndef ONLINE_JUDGE
                cout << "edge: " << i << "," << j << endl;
#endif
                G.u[num_edge] = i;
                G.v[num_edge] = j;
                G.weight[num_edge] = weight;
                G.next[num_edge] = G.vertex[i].first;
                G.vertex[i].first = num_edge;
                num_edge++;
            }
        }
    }
    G.numEdges = num_edge;
    return true;
}
// Bellman-Ford method
int BellmanFord(Graph& G, int s_index)
{
    // init
    for (int i = 0; i < G.numVertexes; i++) {
        G.vertex[i].distance = INF;
    }
    // start index
    G.vertex[s_index].distance = 0;
    // relax
    for (int k = 0; k < G.numEdges; k++) {
        for (int i = 0; i < G.numVertexes; i++) {
            int index_edge = G.vertex[i].first;
            while (index_edge != -1) {
                if (G.vertex[G.u[index_edge]].distance != INF &&
                        G.vertex[G.u[index_edge]].distance +
                        G.weight[index_edge] <
                        G.vertex[G.v[index_edge]].distance) {
                    G.vertex[G.v[index_edge]].distance =
                        G.vertex[G.u[index_edge]].distance +
                        G.weight[index_edge];
                }
                index_edge = G.next[index_edge];
            }
        }
    }
    // check if exit
    return G.vertex[0].distance;
}

Graph G;
int main(void)
{
    int num_case = 1;
    while (CreateGraph(G)) {
        int distance = BellmanFord(G, G.numVertexes - 1);
        cout << "Product " << num_case++ << endl;
        if (distance == INF)
            cout << "Bugs cannot be fixed." << endl;
        else
            cout << "Fastest sequence takes " << distance <<
                " seconds." << endl;
    }
    return 0;
}
