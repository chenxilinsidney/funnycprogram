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
            G.arc[i][j] = NOVALUE;
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

// BFS method
int BFS(Graph& G, int s_index, int t_index) {
    // init distance and color
    for (int index = 1; index <= G.numVertexes; index++) {
        G.vertex[index].color = WHITE;
        G.vertex[index].distance = NOVALUE;
    }
    // init start index
    G.vertex[s_index].color = GRAY;
    G.vertex[s_index].distance = 0; 
    queue<int> q;
    q.push(s_index);
    while(!q.empty()) {
        int top_index = q.front();
        q.pop();
#ifndef ONLINE_JUDGE
        cout << "pop: " << top_index << endl;
#endif
        if (t_index == top_index)
            return G.vertex[t_index].distance;
        for (int index = 1; index <= G.numVertexes; index++) {
            if (G.arc[top_index][index] != NOVALUE &&
                    G.vertex[index].color == WHITE) {
                G.vertex[index].color = GRAY;
                G.vertex[index].distance =
                    G.vertex[top_index].distance + 1;
#ifndef ONLINE_JUDGE
                cout << "new distance: " << index << ":" <<
                    G.vertex[index].distance << endl;
#endif
                q.push(index);
            }
        }
        G.vertex[top_index].color = BLACK;
    }
    return G.vertex[t_index].distance;
}
int main(void)
{
    Graph G;
    int index_cases = 1;
    while (CreateGraph(G)) {
        cout << "Test Set #" << index_cases++ << endl;
        int distance, num_distance, i_from, i_to;
        cin >> num_distance;
        while (num_distance--) {
            cin >> i_from >> i_to;
            // get bfs
            distance = BFS(G, i_from, i_to);
            cout << setw(2) << i_from << " to " <<
                setw(2) << i_to << ": " << distance << endl;

        }
        cout << endl;
    }
}
