/**
 * @file id_10048.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-25
 */

#include <iostream>
#include <queue>
#include <limits>
#include <iomanip>

using namespace std;

#define MAXVEX 101              // maximum vertex numbers in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
typedef int EdgeType;          // edge weight type
// graph data structure
typedef struct {
    EdgeType arc[MAXVEX + 2][MAXVEX + 2]; // adjacent matrix
    int numVertexes;
    int numEdges;
    int numTest;
} Graph;

// create graph method
bool CreateGraph(Graph& G)
{
    if (G.numVertexes == 0) return false;
    // init edges
    for (int i = 1; i <= G.numVertexes; i++)
        for (int j = 1; j <= G.numVertexes; j++)
            G.arc[i][j] = i == j ? 0 : INFINITY;
    // set edges
    for (int index = 1; index <= G.numEdges; index++) {
        int i, j, w;
        cin >> i >> j >> w;
        G.arc[i][j] = w;
        G.arc[j][i] = w;
    }
    return true;
}
// display graph
void DisplayGraph(Graph& G)
{
    cout << "graph: " << endl;
    for (int i = 1; i <= G.numVertexes; i++) {
        for (int j = 1; j <= G.numVertexes; j++) {
            if (G.arc[i][j] == INFINITY)
                cout << setw(3) << 0 << " ";
            else
                cout << setw(3) << G.arc[i][j] << " ";
        }
        cout << endl;
    }
}
// Floyd-Warshall method
void floyd(Graph &G)
{
    for (int k = 1; k <= G.numVertexes; k++) {
        for (int i = 1; i <= G.numVertexes; i++) {
            for (int j = 1; j <= G.numVertexes; j++) {
                if (G.arc[i][k] != INFINITY && G.arc[k][j] != INFINITY)
                    G.arc[i][j] = min(G.arc[i][j],
                            max(G.arc[i][k], G.arc[k][j]));
            }
        }
#ifndef ONLINE_JUDGE
        DisplayGraph(G);
#endif
    }
}

Graph G;
int main(void)
{
    int index_cases = 1;
    cin >> G.numVertexes >> G.numEdges >> G.numTest;
    while (G.numVertexes != 0) {
        cout << "Case #" << index_cases++ << endl;
        CreateGraph(G);
        // floyd
        floyd(G);
        int distance, i_from, i_to;
        while (G.numTest--) {
            cin >> i_from >> i_to;
            distance = G.arc[i_from][i_to];
            if (distance == INFINITY)
                cout << "no path" << endl;
            else
                cout << distance << endl;
        }
        cin >> G.numVertexes >> G.numEdges >> G.numTest;
        if (G.numVertexes) cout << endl;
    }
}
