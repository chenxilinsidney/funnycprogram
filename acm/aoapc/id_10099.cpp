/**
 * @file id_10099.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-26
 */

#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define MAXVEX 100
#define INF numeric_limits<int>::max()
int grid[MAXVEX + 2][MAXVEX + 2];
int numVertexes;
int numEdges;
int start;
int end;
int count;

int main(void)
{
    int index_cases = 1;
    while (cin >> numVertexes >> numEdges && numVertexes != 0) {
        // init grid
        for (int i = 1; i <= numVertexes; i++)
            for (int j = 1; j <= numVertexes; j++)
                grid[i][j] = INF;
        for (int i = 1; i <= numVertexes; i++)
            grid[i][i] = 0;
        // read edges
        while (numEdges--) {
            int i, j, w;
            cin >> i >> j >> w;
            grid[i][j] = w;
            grid[j][i] = w;
        }
        // read param
        cin >> start >> end >> count;
        // floyd
        for (int k = 1; k <= numVertexes; k++) {
            for (int i = 1; i <= numVertexes; i++) {
                for (int j = 1; j <= numVertexes; j++) {
                    if (grid[i][j] == INF)
                        grid[i][j] = min(grid[i][k], grid[k][j]);
                    else
                        grid[i][j] = max(grid[i][j],
                                min(grid[i][k], grid[k][j]));
                }
            }
        }
        // output
        cout << "Scenario #" << index_cases++ << endl;
        cout << "Minimum Number of Trips = " <<
            int(ceil(count * 1.0 / (grid[start][end] - 1))) << endl << endl;
    }
    return 0;
}
