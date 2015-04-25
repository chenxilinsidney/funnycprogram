/**
 * @file id_567.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-24
 */

#include <iostream>
#include <queue>
#include <limits>
#include <iomanip>

using namespace std;

enum {
    WHITE,
    GRAY,
    BLACK
};

#define MAXVEX 21              // maximum vertex numbers in the graph
#define NOVALUE   numeric_limits<int>::max()  // NO VALUE
typedef struct {
    int color;
    int distance;
} VertexType;                  // vertex data type
typedef int EdgeType;          // edge weight type
// graph data structure
typedef struct {
    VertexType vertex[MAXVEX + 2];    // vertex list
    EdgeType arc[MAXVEX + 2][MAXVEX + 2]; // adjacent matrix
    int numVertexes;
} Graph;

// create graph method
bool CreateGraph(Graph& G)
{
    // set graph vertexes numbers
    G.numVertexes = 20;
    // init edges
    for (int i = 1; i <= G.numVertexes; i++)
        for (int j = 1; j <= G.numVertexes; j++)
            G.arc[i][j] = i == j ? 0 : NOVALUE;
    // set edges
    int line_index = 0;
    int edge_numbers, edge_next;
    if (!(cin >> edge_numbers)) return false;
    while (line_index++ < G.numVertexes) {
        while (edge_numbers--) {
            cin >> edge_next;
            G.arc[line_index][edge_next] = 1;
            G.arc[edge_next][line_index] = 1;
        }
        if (line_index == 19) break;
        cin >> edge_numbers;
    }
    return true;
}
// Floyd-Warshall method
void floyd(Graph &G)
{
    for (int k = 1; k <= G.numVertexes; k++)
        for (int i = 1; i <= G.numVertexes; i++)
            for (int j = 1; j <= G.numVertexes; j++)
                if (G.arc[i][k] != NOVALUE && G.arc[k][j] != NOVALUE)
                    G.arc[i][j] = min(G.arc[i][j], G.arc[i][k] + G.arc[k][j]);
}

int main(void)
{
    Graph G;
    int index_cases = 1;
    while (CreateGraph(G)) {
        cout << "Test Set #" << index_cases++ << endl;
        // floyd
        floyd(G);
        int distance, num_distance, i_from, i_to;
        cin >> num_distance;
        while (num_distance--) {
            cin >> i_from >> i_to;
            distance = G.arc[i_from][i_to];
            cout << setw(2) << i_from << " to " <<
                setw(2) << i_to << ": " << distance << endl;

        }
        cout << endl;
    }
}
