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
#define MAXGRIDROW 8              // maximum grid rows in the graph
#define MAXGRIDCOL 8              // maximum grid columns in the graph
#define INFINITY   numeric_limits<int>::max()  // NO VALUE

// single grid data type
typedef struct {
    char key;
    int visit;
    int distance;
} GridType;                  // grid data type
// graph data structure
typedef struct {
    GridType grid[MAXGRIDROW + 4][MAXGRIDCOL + 4];   // matrix with extra bound
    int num_rows;                             // matrix row numbers
    int num_columns;                          // matrix column numbers
} Graph;
// display graph
void DisplayGraph(Graph& G)
{
    cout << "display graph distance: " << endl;
    for (int i = 2; i <= G.num_rows; i++) {
        for (int j = 2; j <= G.num_columns; j++) {
            if (G.grid[i][j].distance != INFINITY)
                cout << G.grid[i][j].distance;
            else
                cout << " ";
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
// BFS method
int move[8][2] = {{-2,-1},{-1,-2},{1, -2},{2,-1},{1,2},{2,1},{-1,2},{-2,1}};
// struct for stack
typedef struct {
    int x;
    int y;
} Point;
int BFS(Graph& G, int s_index_i,
        int s_index_j,
        int t_index_i,
        int t_index_j)
{
    // init chessboard
    for (int i = 2; i < G.num_rows + 2; i++) {
        for (int j = 2; j < G.num_columns + 2; j++) {
            G.grid[i][j].distance = INFINITY;
            G.grid[i][j].visit = WHITE;
        }
    }
    // init bound
    for (int i = 0; i < G.num_rows + 4; i++) {
        G.grid[i][0].visit = BLACK;
        G.grid[i][1].visit = BLACK;
        G.grid[i][G.num_columns + 2].visit = BLACK;
        G.grid[i][G.num_columns + 3].visit = BLACK;
    }
    for (int j = 0; j < G.num_columns + 4; j++) {
        G.grid[0][j].visit = BLACK;
        G.grid[1][j].visit = BLACK;
        G.grid[G.num_rows + 2][j].visit = BLACK;
        G.grid[G.num_rows + 2][j].visit = BLACK;
    }
    // init src destination
    G.grid[s_index_i][s_index_j].distance = 0; 
    G.grid[s_index_i][s_index_j].visit = GRAY; 
    // add to queue
    Point temp, top;
    temp.x = s_index_i; temp.y = s_index_j; 
    queue<Point> q;
    q.push(temp);
    while(!q.empty()) {
        top = q.front();
        q.pop();
        for (int move_index = 0; move_index < 8; move_index++) {
            temp.x = top.x + move[move_index][0];
            temp.y = top.y + move[move_index][1];
            if (G.grid[temp.x][temp.y].visit == WHITE) {
                G.grid[temp.x][temp.y].visit = GRAY;
                G.grid[temp.x][temp.y].distance =
                    G.grid[top.x][top.y].distance + 1;
                q.push(temp);
            }
        }
        G.grid[top.x][top.y].visit = BLACK;
        if (top.x == t_index_i && top.y == t_index_j)
            return G.grid[top.x][top.y].distance;
    }
    return G.grid[t_index_i][t_index_j].distance;
}

int main(void)
{
    Graph G;
    G.num_rows = 8;
    G.num_columns = 8;
    int s_index_i;
    int s_index_j;
    int t_index_i;
    int t_index_j;
    char line[6];
    while (cin.getline(line, 6)) {
        s_index_i = line[1] - '1' + 2;
        s_index_j = line[0] - 'a' + 2;
        t_index_i = line[4] - '1' + 2;
        t_index_j = line[3] - 'a' + 2;
        int move_length = BFS(G, s_index_i, s_index_j,
                t_index_i, t_index_j); 
#ifndef ONLINE_JUDGE
        DisplayGraph(G);
        DisplayGraphVisit(G);
#endif
        cout << "To get from " << line[0] << line[1] << " to " <<
            line[3] << line[4] << " takes " << move_length <<
            " knight moves." << endl;
    }
    return 0;
}
