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
#include <queue>

using namespace std;

#define MAXVEX 100
#define INF numeric_limits<int>::max()
int first[MAXVEX + 2];
int d[MAXVEX + 2];
int u[MAXVEX + 2];
int v[MAXVEX + 2];
int w[MAXVEX + 2];
int next[MAXVEX + 2];
int numVertexes;
int numEdges;
int start;
int end;
int count;
typedef pair<int, int> ppi;
priority_queue< ppi, vector<ppi>, less<ppi> > q;
int main(void)
{
    int index_cases = 1;
    while (cin >> numVertexes >> numEdges && numVertexes != 0) {
        // init vertex
        for (int i = 1; i <= numVertexes; i++)
            first[i] = -1;
        // read edges
        for (int i = 1; i <= numEdges * 2; i += 2) {
            cin >> u[i] >> v[i] >> w[i];
            v[i + 1] = u[i];
            u[i + 1] = v[i];
            w[i + 1] = w[i];
            next[i] = first[u[i]];
            first[u[i]] = i;
            next[i + 1] = first[u[i + 1]];
            first[u[i + 1]] = i + 1;
        }
        // read param
        cin >> start >> end >> count;
        // Dijkstra
        // init distance and enque process flag
        for (int i = 1; i <= numVertexes; i++) d[i] = -1;
        // push start
        d[start] = INF;
        q.push(make_pair(d[start], start));
        // process priority queue
        while (!q.empty()) {
            ppi top = q.top();
            q.pop();
            int index = top.second;
            if (top.first != d[index]) continue;
            for (int i = first[index]; i != -1; i = next[i]) {
                if (d[index] != -1 && d[v[i]] < d[index] && d[v[i]] < w[i]) {
                    d[v[i]] = min(d[index], w[i]);
                    q.push(make_pair(d[v[i]], v[i]));
                }
            }
        }
        // output
        cout << "Scenario #" << index_cases++ << endl;
        cout << "Minimum Number of Trips = " <<
            int(ceil(count * 1.0 / (d[end] - 1))) << endl << endl;
    }
    return 0;
}
