/**
 * @file id_705.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-17
 */

#include <iostream>
#include <cstring>

using namespace std;

#define MAXGRIDROW 225              // maximum grid rows in the graph
#define MAXGRIDCOL 225              // maximum grid columns in the graph

// graph data structure
typedef struct {
    char key[MAXGRIDROW + 2][MAXGRIDCOL + 2];   // matrix with extra bound
    int visit[MAXGRIDROW + 2][MAXGRIDCOL + 2]; // matrix with extra bound
    int num_rows;                             // matrix row numbers
    int num_columns;                          // matrix column numbers
} Graph;
// create graph method
void DisplayGraph(Graph& G);
void DisplayGraphVisit(Graph& G);
bool CreateGraph(Graph& G)
{
    // input graph row and column numbers
    cin >> G.num_columns >> G.num_rows;
    G.num_columns *= 3;
    G.num_rows *= 3;
    // unavaliable graph
    if (G.num_rows <= 0 || G.num_columns <= 0) return false;
    // get grid data from input
    for (int i = 1; i <=  G.num_rows; i += 3) {
        for (int j = 1; j <= G.num_columns; j += 3) {
            char temp;
            cin >> temp;
            if (temp == '\\') {
                G.key[i][j] = 'X';
                G.key[i + 1][j + 1] = 'X';
                G.key[i + 2][j + 2] = 'X';
                G.key[i][j + 1] = ' ';
                G.key[i][j + 2] = ' ';
                G.key[i + 1][j] = ' ';
                G.key[i + 1][j + 2] = ' ';
                G.key[i + 2][j] = ' ';
                G.key[i + 2][j + 1] = ' ';
                G.visit[i][j] = 1;
                G.visit[i + 1][j + 1] = 1;
                G.visit[i + 2][j + 2] = 1;
                G.visit[i][j + 1] = 0;
                G.visit[i][j + 2] = 0;
                G.visit[i + 1][j] = 0;
                G.visit[i + 1][j + 2] = 0;
                G.visit[i + 2][j] = 0;
                G.visit[i + 2][j + 1] = 0;
            } else {
                G.key[i][j + 2] = 'X';
                G.key[i + 1][j + 1] = 'X';
                G.key[i + 2][j] = 'X';
                G.key[i][j] = ' ';
                G.key[i + 2][j + 2] = ' ';
                G.key[i][j + 1] = ' ';
                G.key[i + 1][j] = ' ';
                G.key[i + 1][j + 2] = ' ';
                G.key[i + 2][j + 1] = ' ';
                G.visit[i][j + 2] = 1;
                G.visit[i + 1][j + 1] = 1;
                G.visit[i + 2][j] = 1;
                G.visit[i][j] = 0;
                G.visit[i + 2][j + 2] = 0;
                G.visit[i][j + 1] = 0;
                G.visit[i + 1][j] = 0;
                G.visit[i + 1][j + 2] = 0;
                G.visit[i + 2][j + 1] = 0;
            }
        }
    }
    // set boundary
    for (int j = 0; j <= G.num_columns + 1; j++) {
        G.visit[0][j] = 2;
        G.visit[G.num_rows + 1][j] = 2;
    }
    for (int i = 0; i <= G.num_rows + 1; i++) {
        G.visit[i][0] = 2;
        G.visit[i][G.num_columns + 1] = 2;
    }
#ifndef ONLINE_JUDGE
    DisplayGraph(G);
    DisplayGraphVisit(G);
#endif
    return true;
}
// display graph
void DisplayGraph(Graph& G)
{
    cout << "display graph key: " << endl;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            cout << G.key[i][j];
        }
        cout << endl;
    }
}
// display graph visit
void DisplayGraphVisit(Graph& G)
{
    cout << "display graph visit: " << endl;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            cout << G.visit[i][j];
        }
        cout << endl;
    }
}
// DFS method
int max_area;
// struct for stack
typedef struct {
    int x;
    int y;
} Point;
// DFS by own stack array
Point stack_own[57375];
int stack_top = 0;
int DFS_by_ownstack(Graph& G) {
    Point temp, top;
    int num = 0;
    max_area = 0;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            if (!G.visit[i][j] && G.key[i][j] == ' ') {
                temp.x = i; temp.y = j;
                stack_own[0] = temp;
                stack_top = 0;
                int area = 0;
                bool flag_bound_area = false;
                while (stack_top != -1) {
                    top = stack_own[stack_top];
                    stack_top--;
                    if (!flag_bound_area && G.visit[top.x][top.y] == 2)
                        flag_bound_area = true;
                    if (G.visit[top.x][top.y] != 0 ||
                            G.key[top.x][top.y] != ' ')
                        continue;
                    G.visit[top.x][top.y] = 1;
                    G.key[top.x][top.y] = '#';
                    area++;
                    temp.x = top.x + 1; temp.y = top.y; stack_top++;
                    stack_own[stack_top] = temp;
                    temp.x = top.x - 1; temp.y = top.y; stack_top++;
                    stack_own[stack_top] = temp;
                    temp.x = top.x; temp.y = top.y + 1; stack_top++;
                    stack_own[stack_top] = temp;
                    temp.x = top.x; temp.y = top.y - 1; stack_top++;
                    stack_own[stack_top] = temp;
                }
#ifndef ONLINE_JUDGE
                cout << "area : " << area << endl;
                cout << "flag : " << flag_bound_area << endl;
#endif
                if (!flag_bound_area) {
                    if (max_area < area) max_area = area;
                    num++;
                }
            }
        }
    }
    return num;
}

int main(void)
{
    Graph G;
    int num_case = 1;
    while (CreateGraph(G)) {
        int num_cycles = DFS_by_ownstack(G);
#ifndef ONLINE_JUDGE
        DisplayGraph(G);
        DisplayGraphVisit(G);
#endif
        cout << "Maze #" << num_case++ << ":" << endl;
        if (num_cycles == 0)
            cout << "There are no cycles." << endl;
        else
            cout << num_cycles << " Cycles; the longest has length " <<
                max_area / 3 << "." << endl;
        cout << endl;
    }
    return 0;
}
