/**
 * @file id_558.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-27
 */

#include <iostream>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()
#define MAXVEX 1000
#define MAXEDGE 2000

int first[MAXVEX];
int d[MAXVEX];
int u[MAXEDGE];
int v[MAXEDGE];
int w[MAXEDGE];
int next[MAXEDGE];
int numVertexes;
int numEdges;


int main(void)
{
    int num_case;
    cin >> num_case;
    while (num_case--) {
        cin >> numVertexes >> numEdges;
        for (int i = 0; i < numVertexes; i++) first[i] = -1;
        for (int i = 0; i < numEdges; i++) {
            cin >> u[i] >> v[i] >> w[i];
            next[i] = first[u[i]];
            first[u[i]] = i;
        }
        for (int i = 0; i < numVertexes; i++) d[i] = INF;
        d[0] = 0;
        for (int k = 0; k < numVertexes - 1; k++) {
            for (int i = 0; i < numEdges; i++) {
                if (d[u[i]] != INF && d[u[i]] + w[i] < d[v[i]])
                    d[v[i]] = d[u[i]] + w[i];
            }
        }
        bool flag = true;
        for (int i = 0; i < numEdges; i++) {
            if (d[u[i]] != INF && d[u[i]] + w[i] < d[v[i]])
                flag = false;
        }
        if (!flag) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
    return 0;
}
