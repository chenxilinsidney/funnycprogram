/**
 * @file id_658.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-25
 */

#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <queue>

using namespace std;

#define MAXVEX 1048600              // maximum vertex numbers in the graph
#define INF   numeric_limits<int>::max()  // NO VALUE
typedef struct {
    int distance;
} VertexType;                  // vertex data type
typedef struct {
    int in_mask;
    int in_value;
    int out_mask;
    int out_value;
    int weight;
} PathType;
// graph data structure
typedef struct {
    VertexType vertex[MAXVEX + 2];    // vertex list
    int numBugBit;
    int numVertexes;
    int numPatches;
    // patch
    PathType patch[MAXVEX + 2];
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
// create graph method
bool CreateGraph(Graph& G)
{
    // set graph vertexes numbers
    cin >> G.numBugBit >> G.numPatches;
    if (G.numBugBit == 0) return false;
    G.numVertexes = pow(2, G.numBugBit);
    // set patch
    string in, out;
    for (int k = 0; k < G.numPatches; k++) {
        cin >> G.patch[k].weight >> in >> out;
        SparsePatch(in, &(G.patch[k].in_mask), &(G.patch[k].in_value));
        SparsePatch(out, &(G.patch[k].out_mask), &(G.patch[k].out_value));
    }
    return true;
}
// Dijkstra priority queue method
typedef pair<int, int> ppi;
priority_queue< ppi, vector<ppi>, greater<ppi> > q;
int Dijkstra(Graph& G, int s_index)
{
    // init
    for (int i = 0; i < G.numVertexes; i++) {
        G.vertex[i].distance = INF;
    }
    // start index
    G.vertex[s_index].distance = 0;
    // relax
    q.push(make_pair(G.vertex[s_index].distance, s_index));
    while (!q.empty()) {
        ppi top = q.top();
        int x = top.second;
        q.pop();
        // been calculated by other vertex should ignore and wait
        if (top.first != G.vertex[x].distance) continue;
        for (int k = 0; k < G.numPatches; k++) {
            if ((x & G.patch[k].in_mask) == G.patch[k].in_value) {
                int j = (x & ~G.patch[k].out_mask) + G.patch[k].out_value;
                if (G.vertex[x].distance != INF &&
                        G.vertex[x].distance + G.patch[k].weight <
                        G.vertex[j].distance) {
                    G.vertex[j].distance =
                        G.vertex[x].distance + G.patch[k].weight;
                    q.push(make_pair(G.vertex[j].distance, j));
                }
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
        int distance = Dijkstra(G, G.numVertexes - 1);
        cout << "Product " << num_case++ << endl;
        if (distance == INF)
            cout << "Bugs cannot be fixed." << endl << endl;
        else
            cout << "Fastest sequence takes " << distance <<
                " seconds." << endl << endl;
    }
    return 0;
}
