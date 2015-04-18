/**
 * @file id_784.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-17
 */

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAXGRIDROW 35              // maximum grid rows in the graph
#define MAXGRIDCOL 85              // maximum grid columns in the graph

// graph data structure
typedef struct {
    char key[MAXGRIDROW + 2][MAXGRIDCOL + 2];   // matrix with extra bound
    bool visit[MAXGRIDROW + 2][MAXGRIDCOL + 2]; // matrix with extra bound
    int num_rows;                               // matrix row numbers
    int columns[MAXGRIDROW + 2];                // matrix column numbers
} Graph;
// create graph method
bool CreateGraph(Graph& G)
{
    // input graph by row
    G.num_rows = 1;
    while (cin.getline(G.key[G.num_rows] + 1, MAXGRIDCOL) &&
            G.key[G.num_rows][1] != '_') {
        G.columns[G.num_rows] = strlen(G.key[G.num_rows] + 1);
        for (int i = 1; i <= G.columns[G.num_rows]; i++)
            G.visit[G.num_rows][i] = false;
        G.num_rows++;
    }
    G.num_rows--;
    // unavaliable graph
    if (G.num_rows <= 0) return false;
    // set boundary
    for (int i = 0; i < G.columns[1] + 2; i++)
        G.visit[0][i] = true;
    for (int i = 0; i < G.columns[G.num_rows] + 2; i++)
        G.visit[G.num_rows + 1][i] = true;
    for (int i = 1; i <= G.num_rows; i++) {
        G.visit[i][0] = true;
        G.visit[i][G.columns[i] + 1] = true;
    }
    return true;
}
// display graph
void DisplayGraph(Graph& G)
{
    // cout << "display graph key: " << endl;
    for (int i = 1; i <= G.num_rows + 1; i++)
        cout << G.key[i] + 1 << endl;
}
// display graph visit
void DisplayGraphVisit(Graph& G)
{
    cout << "display graph visit: " << endl;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.columns[i]; j++) {
            cout << G.visit[i][j] << " ";
        }
        cout << endl;
    }
}
// DFS method
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

int main(void)
{
    Graph G;
    int num_case;
    cin >> num_case;
    cin.get();
    while (num_case--) {
        CreateGraph(G);
        DFS_by_stlstack(G);
        DisplayGraph(G);
    }
    return 0;
}
