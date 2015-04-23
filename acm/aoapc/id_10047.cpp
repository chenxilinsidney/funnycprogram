/**
 * @file id_10047.cpp
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
    BLACK,
};
enum {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};
enum {
    COLOR_A = 1,
    COLOR_B = 2,
    COLOR_C = 3,
    COLOR_D = 4,
    COLOR_E = 5
};
#define MAXGRIDROW 30              // maximum grid rows in the graph
#define MAXGRIDCOL 30              // maximum grid columns in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE
#define COLORTYPE 6
#define DIRECTIONTYPE 5
// single grid data type
typedef struct {
    char key;
    int visit;
    int distance[COLORTYPE][DIRECTIONTYPE]; // color and direction
} GridType;                  // grid data type
// struct for stack or queue
typedef struct {
    int x;
    int y;
    int color;
    int direction;
} Point;
// graph data structure
typedef struct {
    GridType grid[MAXGRIDROW + 2][MAXGRIDCOL + 2];
    // matrix with extra bound
    int num_rows;                             // matrix row numbers
    int num_columns;                          // matrix column numbers
    Point start, end;
} Graph;
// display graph
void DisplayGraph(Graph& G)
{
    cout << "display graph: " << endl;
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            cout << G.grid[i][j].key;
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
            cout << G.grid[i][j].visit;
        }
        cout << endl;
    }
}
// create graph method
bool CreateGraph(Graph& G)
{
    // unavaliable graph
    if (G.num_rows <= 0 || G.num_columns <= 0)
        return false;
    // get grid data from input
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            cin >> G.grid[i][j].key;
            // set boundary flag
            if (G.grid[i][j].key == '#') {
                G.grid[i][j].visit = BLACK;
                continue;
            }
            G.grid[i][j].visit = WHITE;
            // set flag for search
            for (int ii = 0; ii < COLORTYPE; ii++)
                for (int jj = 0; jj < COLORTYPE; jj++)
                    G.grid[i][j].distance[ii][jj] = INFINITY;
            // set start and end grid
            if (G.grid[i][j].key == 'S') {
                G.start.x = i;
                G.start.y = j;
                G.start.direction = NORTH;
                G.start.color = COLOR_A;
            } else if (G.grid[i][j].key == 'T') {
                G.end.x = i;
                G.end.y = j;
                G.end.color = COLOR_A;
            }
        }
    }
    // set boundary
    for (int j = 0; j <= G.num_columns + 1; j++) {
        G.grid[0][j].visit = BLACK;
        G.grid[G.num_rows + 1][j].visit = BLACK;
    }
    for (int i = 0; i <= G.num_rows + 1; i++) {
        G.grid[i][0].visit = BLACK;
        G.grid[i][G.num_columns + 1].visit = BLACK;
    }
    return true;
}
// BFS method
int move[5][2] = {{0, 0}, {-1, 0},{0, 1},{1, 0},{0, -1}};
int BFS(Graph& G)
{
    int distance = -1;
    // init start distance
    G.grid[G.start.x][G.start.y].distance[G.start.color][G.start.direction] = 0;
    // add to queue
    Point temp, top;
    queue<Point> q;
    q.push(G.start);
    while(!q.empty()) {
        top = q.front();
        q.pop();
        // cout << "visit point x: " << top.x << "," << top.y << endl;
        // out of range
        if (G.grid[top.x][top.y].visit == BLACK)
            continue;
        // get to end
        if (top.x == G.end.x && top.y == G.end.y && top.color == G.end.color) {
            distance = G.grid[top.x][top.y].distance[top.color][top.direction];
            break;
        }
        // move same direction
        temp.x = top.x + move[top.direction][0];
        temp.y = top.y + move[top.direction][1];
        temp.direction = top.direction;
        temp.color = top.color == 5 ? 1 : top.color + 1;
        if (G.grid[temp.x][temp.y].distance[temp.color][temp.direction] ==
                INFINITY)  {
            G.grid[temp.x][temp.y].distance[temp.color][temp.direction] =
                G.grid[top.x][top.y].distance[top.color][top.direction] + 1;
            q.push(temp);
        }
        // turn left and right 
        temp.x = top.x;
        temp.y = top.y;
        temp.color = top.color;
        for (int i = 0; i < 2; i++) {
            if (i == 0)
                temp.direction = top.direction == 4 ? 1 : top.direction + 1;
            else
                temp.direction = top.direction == 1 ? 4 : top.direction - 1;
            if (G.grid[temp.x][temp.y].distance[temp.color][temp.direction] ==
                    INFINITY)  {
                G.grid[temp.x][temp.y].distance[temp.color][temp.direction] =
                    G.grid[top.x][top.y].distance[top.color][top.direction] + 1;
                q.push(temp);
            }
        }
    }
    return distance;
}
int main(void)
{
    Graph G;
    int index_case = 1;
    cin >> G.num_rows >> G.num_columns;
    while (G.num_rows != 0 && G.num_columns != 0) {
        CreateGraph(G);
#ifndef ONLINE_JUDGE
        DisplayGraph(G);
        DisplayGraphVisit(G);
#endif
        int distance = BFS(G);
        // display result
        cout << "Case #" << index_case++ << endl;
        if (distance == -1)
            cout << "destination not reachable" << endl;
        else
            cout << "minimum time = " << distance << " sec" << endl;
        cin >> G.num_rows >> G.num_columns;
        if (G.num_rows != 0 && G.num_columns != 0)
            cout << endl;
    }
    return 0;
}
