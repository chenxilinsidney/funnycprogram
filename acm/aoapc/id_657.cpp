/**
 * @file id_657.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-17
 */

#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

#define MAXGRID 50              // maximum grid numbers in the graph
int dot_sequence[MAXGRID * MAXGRID];
int compare(const void* a, const void* b) {
    return (*((int*)a)) - (*((int*)b));
}

// single grid data type
typedef struct {
    char key;
    bool connected_visit;
    bool dot_visit;
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
    cin >> G.num_columns >> G.num_rows;
    // unavaliable graph
    if (G.num_rows <= 0 || G.num_columns <= 0) return false;
    // get grid data from input
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            cin >> G.grid[i][j].key;
            // set flag for dfs
            G.grid[i][j].connected_visit = false;
            G.grid[i][j].dot_visit = false;
        }
    }
    // set boundary
    for (int j = 0; j < G.num_columns + 2; j++) {
        G.grid[0][j].connected_visit = true;
        G.grid[G.num_rows + 1][j].connected_visit = true;
        G.grid[0][j].dot_visit = true;
        G.grid[G.num_rows + 1][j].dot_visit = true;
    }
    for (int i = 0; i < G.num_rows + 2; i++) {
        G.grid[i][0].connected_visit = true;
        G.grid[i][G.num_columns + 1].connected_visit = true;
        G.grid[i][0].dot_visit = true;
        G.grid[i][G.num_columns + 1].dot_visit = true;
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

// struct for stack
typedef struct {
    int x;
    int y;
} Point;
// DFS by stack
int DFS(Graph& G) {
    stack<Point> s;
    stack<Point> s_dot;
    Point temp, top;
    Point temp_dot, top_dot;
    int num_maximum_connected = 0;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            // maximum connected
            if (!G.grid[i][j].connected_visit && G.grid[i][j].key != '.') {
                temp.x = i; temp.y = j;
                s.push(temp);
                int num_dots = 0;
                while (!s.empty()) {
                    top = s.top();
                    s.pop();
                    if (G.grid[top.x][top.y].connected_visit ||
                            G.grid[top.x][top.y].key == '.')
                        continue;
                    // num dots
                    if (G.grid[top.x][top.y].key == 'X' &&
                            !G.grid[top.x][top.y].dot_visit) {
                        temp_dot.x = top.x; temp_dot.y = top.y;
#ifndef ONLINE_JUDGE
                        cout << "temp dot: " << temp_dot.x << ", "
                            << temp_dot.y << endl;
#endif
                        s_dot.push(temp_dot);
                        while (!s_dot.empty()) {
                            top_dot = s_dot.top();
                            s_dot.pop();
                            if (G.grid[top_dot.x][top_dot.y].dot_visit ||
                                    G.grid[top_dot.x][top_dot.y].key != 'X')
                                continue;
                            G.grid[top_dot.x][top_dot.y].dot_visit = true;
                            temp_dot.x = top_dot.x + 1; temp_dot.y = top_dot.y;
                            s_dot.push(temp_dot);
                            temp_dot.x = top_dot.x - 1; temp_dot.y = top_dot.y;
                            s_dot.push(temp_dot);
                            temp_dot.x = top_dot.x; temp_dot.y = top_dot.y + 1;
                            s_dot.push(temp_dot);
                            temp_dot.x = top_dot.x; temp_dot.y = top_dot.y - 1;
                            s_dot.push(temp_dot);
                        }
                        num_dots++;
                    }
                    G.grid[top.x][top.y].connected_visit = true;
                    temp.x = top.x + 1; temp.y = top.y; s.push(temp);
                    temp.x = top.x - 1; temp.y = top.y; s.push(temp);
                    temp.x = top.x; temp.y = top.y + 1; s.push(temp);
                    temp.x = top.x; temp.y = top.y - 1; s.push(temp);
                }
                dot_sequence[num_maximum_connected] = num_dots;
#ifndef ONLINE_JUDGE
                cout << "num_dots: " << num_dots << endl;
#endif
                num_maximum_connected++;
            }
        }
    }
    return num_maximum_connected;
}

int main(void)
{
    Graph G;
    int num_case = 1;
    while (CreateGraph(G)) {
        int num_maximum_connected = DFS(G);
        qsort(dot_sequence, num_maximum_connected, sizeof(dot_sequence[0]),
                    compare);
        // print result
        cout << "Throw " << num_case++ << endl;
        for (int i = 0; i < num_maximum_connected - 1; i++)
            cout << dot_sequence[i] << " ";
        cout << dot_sequence[num_maximum_connected - 1] << endl << endl;
    }
    return 0;
}
