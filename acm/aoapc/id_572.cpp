/**
 * @file id_572.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-17
 */

#include <iostream>
#include <stack>

using namespace std;

#define MAXGRID 100              // maximum grid numbers in the graph

// single grid data type
typedef struct {
    char key;
    bool visit;
} GridType;                  // grid data type
// graph data structure
typedef struct {
    GridType grid[MAXGRID + 2][MAXGRID + 2];  // grid matrix with extra bound
    int num_rows;                             // matrix row numbers
    int num_columns;                          // matrix column numbers
} Graph;
// create graph method
bool CreateGraph(Graph& G)
{
    // input graph row and column numbers
    cin >> G.num_rows >> G.num_columns;
    // unavaliable graph
    if (G.num_rows <= 0 || G.num_columns <= 0) return false;
    // get grid data from input
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            cin >> G.grid[i][j].key;
            // set flag for dfs
            G.grid[i][j].visit = false;
        }
    }
    // set boundary
    for (int j = 0; j < G.num_columns + 2; j++) {
        G.grid[0][j].visit = true;
        G.grid[G.num_rows + 1][j].visit = true;
    }
    for (int i = 0; i < G.num_rows + 2; i++) {
        G.grid[i][0].visit = true;
        G.grid[i][G.num_columns + 1].visit = true;
    }
#ifndef ONLINE_JUDGE
    // display graph
    cout << "display graph: " << endl;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            cout << G.grid[i][j].key << " ";
        }
        cout << endl;
    }
#endif
    return true;
}

#if 0
// DFS method
void DFS_VISIT(Graph& G, int i, int j)
{
    if (G.grid[i][j].visit || G.grid[i][j].key != '@')
        return;
    G.grid[i][j].visit = true;
    DFS_VISIT(G, i + 1, j);
    DFS_VISIT(G, i - 1, j);
    DFS_VISIT(G, i, j + 1);
    DFS_VISIT(G, i, j - 1);
    DFS_VISIT(G, i + 1, j + 1);
    DFS_VISIT(G, i + 1, j - 1);
    DFS_VISIT(G, i - 1, j + 1);
    DFS_VISIT(G, i - 1, j - 1);
}
int DFS(Graph& G) {
    int num = 0;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            if (!G.grid[i][j].visit && G.grid[i][j].key == '@') {
                DFS_VISIT(G, i, j);
                num++;
            }
        }
    }
    return num;
}
#else
// struct for stack
typedef struct {
    int x;
    int y;
} Point;
// DFS by stack
int DFS(Graph& G) {
    stack<Point> s;
    Point temp, top;
    int num = 0;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            if (!G.grid[i][j].visit && G.grid[i][j].key == '@') {
                temp.x = i; temp.y = j;
                s.push(temp);
                while (!s.empty()) {
                    top = s.top();
                    s.pop();
                    if (G.grid[top.x][top.y].visit ||
                            G.grid[top.x][top.y].key != '@')
                        continue;
                    G.grid[top.x][top.y].visit = true;
                    temp.x = top.x + 1; temp.y = top.y; s.push(temp);
                    temp.x = top.x - 1; temp.y = top.y; s.push(temp);
                    temp.x = top.x; temp.y = top.y + 1; s.push(temp);
                    temp.x = top.x; temp.y = top.y - 1; s.push(temp);
                    temp.x = top.x + 1; temp.y = top.y + 1; s.push(temp);
                    temp.x = top.x + 1; temp.y = top.y - 1; s.push(temp);
                    temp.x = top.x - 1; temp.y = top.y + 1; s.push(temp);
                    temp.x = top.x - 1; temp.y = top.y - 1; s.push(temp);
                }
                num++;
            }
        }
    }
    return num;
}
#endif

int main(void)
{
    Graph G;
    while (CreateGraph(G)) {
        cout << DFS(G) << endl;
    }
    return 0;
}
