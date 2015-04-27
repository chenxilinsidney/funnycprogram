/**
 * @file id_10986.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-27
 */

#include <iostream>
#include <limits>
#include <queue>

using namespace std;

#define INF numeric_limits<int>::max()
#define MAXVEX 20000
#define MAXEDGE 50000 * 2
int first[MAXVEX];
int d[MAXVEX];
int u[MAXEDGE];
int v[MAXEDGE];
int w[MAXEDGE];
int next[MAXEDGE];
int numVertexes;
int numEdges;
int target_start;
int target_end;
typedef pair<int, int> pii;
priority_queue< pii, vector<pii>, greater<pii> > q;

int main(void)
{
    int num_cases;
    int index_cases = 1;
    cin >> num_cases;
    while (num_cases--) {
        // read
        cin >> numVertexes >> numEdges >> target_start >> target_end;
        // init vertex
        for (int i = 0; i < numVertexes; i++) first[i] = -1;
        // get edge
        for (int i = 0; i < numEdges * 2; i++) {
            cin >> u[i] >> v[i] >> w[i];
            next[i] = first[u[i]];
            first[u[i]] = i;
            i++;
            u[i] = v[i - 1];
            v[i] = u[i - 1];
            w[i] = w[i - 1];
            next[i] = first[u[i]];
            first[u[i]] = i;
        }
        // Dirkstra
        for (int i = 0; i < numVertexes; i++) d[i] = INF;
        d[target_start] = 0;
        q.push(make_pair(d[target_start], target_start));
        while (!q.empty()) {
            pii top = q.top();
            q.pop();
            int index = top.second;
            if (top.first != d[index]) continue;
            for (int i = first[index]; i != -1; i = next[i]) {
                if (d[index] != INF && d[index] + w[i] < d[v[i]]) {
                    d[v[i]] = d[index] + w[i];
                    q.push(make_pair(d[v[i]], v[i]));
                }
            }
        }
        // output
        cout << "Case #" << index_cases++ << ": ";
        if (d[target_end] == INF)
            cout << "unreachable" << endl;
        else
            cout << d[target_end] << endl;
    }
    return 0;
}
