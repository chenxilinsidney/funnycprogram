/**
 * @file id_439.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-19
 */

#include <iostream>
#include <queue>
#include <limits>

using namespace std;

enum {
    WHITE,
    GRAY,
    BLACK
};
#define MAXGRIDROW 30              // maximum grid rows in the graph
#define MAXGRIDCOL 30              // maximum grid columns in the graph
#define MAXGRIDLEV 30              // maximum grid level in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE

// single grid data type
typedef struct {
    char key;
    int visit;
    int distance;
} GridType;                  // grid data type
// struct for stack or queue
typedef struct {
    int k;
    int x;
    int y;
} Point;
// graph data structure
typedef struct {
    GridType grid[MAXGRIDLEV + 2][MAXGRIDROW + 2][MAXGRIDCOL + 2];
    // matrix with extra bound
    int num_rows;                             // matrix row numbers
    int num_columns;                          // matrix column numbers
    int num_levels;                           // matrix level numbers
    Point start, end;
} Graph;
// display graph
void DisplayGraph(Graph& G)
{
    cout << "display graph: " << endl;
    for (int k = 1; k <= G.num_levels; k++) {
        cout << "level: " << k << endl;
        for (int i = 1; i <= G.num_rows; i++) {
            for (int j = 1; j <= G.num_columns; j++) {
                cout << G.grid[k][i][j].key;
            }
            cout << endl;
        }
    }
}
// display graph distance
void DisplayGraphDist(Graph& G)
{
    cout << "display graph distance: " << endl;
    for (int k = 1; k <= G.num_levels; k++) {
        cout << "level: " << k << endl;
        for (int i = 1; i <= G.num_rows; i++) {
            for (int j = 1; j <= G.num_columns; j++) {
                if (G.grid[k][i][j].distance != INFINITY)
                    cout << G.grid[k][i][j].distance;
                else
                    cout << "  ";
            }
            cout << endl;
        }
    }
}
// display graph visit
void DisplayGraphVisit(Graph& G)
{
    cout << "display graph visit: " << endl;
    for (int k = 1; k <= G.num_levels; k++) {
        cout << "level: " << k << endl;
        for (int i = 1; i <= G.num_rows; i++) {
            for (int j = 1; j <= G.num_columns; j++) {
                cout << G.grid[k][i][j].visit;
            }
            cout << endl;
        }
    }
}
// create graph method
bool CreateGraph(Graph& G)
{
    // input graph level and row and column numbers
    cin >> G.num_levels >> G.num_rows >> G.num_columns;
    // unavaliable graph
    if (G.num_levels <= 0 || G.num_rows <= 0 || G.num_columns <= 0)
        return false;
    // get grid data from input
    for (int k = 1; k <= G.num_levels; k++) {
        for (int i = 1; i <= G.num_rows; i++) {
            for (int j = 1; j <= G.num_columns; j++) {
                cin >> G.grid[k][i][j].key;
                // set flag for search
                G.grid[k][i][j].distance = INFINITY;
                G.grid[k][i][j].visit = WHITE;
                if (G.grid[k][i][j].key == 'S') {
                    G.start.k = k;
                    G.start.x = i;
                    G.start.y = j;
                } else if (G.grid[k][i][j].key == 'E') {
                    G.end.k = k;
                    G.end.x = i;
                    G.end.y = j;
                }
            }
        }
    }
    // set boundary
    for (int i = 0; i <= G.num_rows + 1; i++) {
        for (int j = 0; j <= G.num_columns + 1; j++) {
            G.grid[0][i][j].visit = BLACK;
            G.grid[G.num_levels + 1][i][j].visit = BLACK;
        }
    }
    for (int k = 0; k <= G.num_levels + 1; k++) {
        for (int j = 0; j <= G.num_columns + 1; j++) {
            G.grid[k][0][j].visit = BLACK;
            G.grid[k][G.num_rows + 1][j].visit = BLACK;
        }
    }
    for (int k = 0; k <= G.num_levels + 1; k++) {
        for (int i = 0; i <= G.num_rows + 1; i++) {
            G.grid[k][i][0].visit = BLACK;
            G.grid[k][i][G.num_columns + 1].visit = BLACK;
        }
    }
    return true;
}
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

int main(void)
{
    Graph G;
    while (CreateGraph(G)) {
        int num_length = BFS(G); 
#ifndef ONLINE_JUDGE
        DisplayGraph(G);
        DisplayGraphVisit(G);
        DisplayGraphDist(G);
#endif
        if (num_length == 0)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << num_length << " minute(s)." << endl;
    }
    return 0;
}
