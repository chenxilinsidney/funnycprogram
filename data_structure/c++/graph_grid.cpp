/**
 * @file graph_adjmatrix.c
 * @brief graph data structure by adjacent matrix
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-13
 */

#include <iostream>
#include <queue>
#include <limits>
#include <cstdlib>

using namespace std;

#define MAXGRIDROW 35              // maximum grid rows in the graph
#define MAXGRIDCOL 85              // maximum grid columns in the graph

// single grid data type
typedef struct {
    char key;
    bool visit;
} GridType;                  // grid data type
// graph data structure
typedef struct {
    GridType grid[MAXGRIDROW + 2][MAXGRIDCOL + 2];  // matrix with extra bound
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
    return true;
}
// display graph
void DisplayGraph(Graph& G)
{
    cout << "display graph : " << endl;
    for (int i = 2; i <= G.num_rows; i++) {
        for (int j = 2; j <= G.num_columns; j++) {
            cout << G.grid[i][j].key;
        }
        cout << endl;
    }
}
// display graph visit
void DisplayGraphVisit(Graph& G)
{
    cout << "display graph visit: " << endl;
    for (int i = 2; i <= G.num_rows; i++) {
        for (int j = 2; j <= G.num_columns; j++) {
            cout << G.grid[i][j].visit;
        }
        cout << endl;
    }
}
#if 0
// DFS method by function recursion
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
#endif
#if 0
// struct for stack
typedef struct {
    int x;
    int y;
} Point;
// DFS by own stack array
Point stack_own[2500];
int stack_top = 0;
void DFS_by_ownstack(Graph& G) {
    Point temp, top;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.columns[i]; j++) {
            if (G.key[i][j] == '*') {
                temp.x = i; temp.y = j;
                stack_own[0] = temp;
                stack_top = 0;
                while (stack_top != -1) {
                    top = stack_own[stack_top];
                    stack_top--;
                    if (G.visit[top.x][top.y] ||
                            (G.key[top.x][top.y] != ' ' &&
                            G.key[top.x][top.y] != '*'))
                        continue;
                    G.visit[top.x][top.y] = true;
                    G.key[top.x][top.y] = '#';
                    temp.x = top.x + 1; temp.y = top.y; stack_top++;
                    stack_own[stack_top] = temp;
                    temp.x = top.x - 1; temp.y = top.y; stack_top++;
                    stack_own[stack_top] = temp;
                    temp.x = top.x; temp.y = top.y + 1; stack_top++;
                    stack_own[stack_top] = temp;
                    temp.x = top.x; temp.y = top.y - 1; stack_top++;
                    stack_own[stack_top] = temp;
                }
                return;
            }
        }
    }
}
#endif
#if 0
// DFS by stl stack
void DFS_by_stlstack(Graph& G) {
    stack<Point> s;
    Point temp, top;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.columns[i]; j++) {
            if (G.key[i][j] == '*') {
                temp.x = i; temp.y = j;
                s.push(temp);
                while (!s.empty()) {
                    top = s.top();
                    s.pop();
                    if (G.visit[top.x][top.y] ||
                            (G.key[top.x][top.y] != ' ' &&
                            G.key[top.x][top.y] != '*'))
                        continue;
                    G.visit[top.x][top.y] = true;
                    G.key[top.x][top.y] = '#';
                    temp.x = top.x + 1; temp.y = top.y; s.push(temp);
                    temp.x = top.x - 1; temp.y = top.y; s.push(temp);
                    temp.x = top.x; temp.y = top.y + 1; s.push(temp);
                    temp.x = top.x; temp.y = top.y - 1; s.push(temp);
                }
                return;
            }
        }
    }
}
#endif

#if 0
// BFS method
// move direction:first level, second row, third column
int move[6][3] = {
    {0, -1, 0},
    {0, 1, 0},
    {0, 0, -1},
    {0, 0, 1},
    {-1, 0, 0},
    {1, 0, 0}};
int BFS(Graph& G)
{
#ifndef ONLINE_JUDGE
    cout << "start at: " << G.start.k << "," << G.start.x << "," <<
        G.start.y << endl;
    cout << "end at: " << G.end.k << ","  << G.end.x << "," <<
        G.end.y << endl;
#endif
    // init src destination
    G.grid[G.start.k][G.start.x][G.start.y].distance = 0; 
    G.grid[G.start.k][G.start.x][G.start.y].visit = GRAY; 
    // add to queue
    Point temp, top;
    queue<Point> q;
    q.push(G.start);
    while(!q.empty()) {
        top = q.front();
        q.pop();
        for (int move_index = 0; move_index < 6; move_index++) {
            temp.k = top.k + move[move_index][0];
            temp.x = top.x + move[move_index][1];
            temp.y = top.y + move[move_index][2];
            if (G.grid[temp.k][temp.x][temp.y].key != '#' &&
                    G.grid[temp.k][temp.x][temp.y].visit == WHITE) {
                G.grid[temp.k][temp.x][temp.y].visit = GRAY;
                G.grid[temp.k][temp.x][temp.y].distance =
                    G.grid[top.k][top.x][top.y].distance + 1;
                q.push(temp);
            }
        }
        G.grid[top.k][top.x][top.y].visit = BLACK;
        if (top.k == G.end.k && top.x == G.end.x && top.y == G.end.y)
            return G.grid[top.k][top.x][top.y].distance;
    }
    return 0;
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
