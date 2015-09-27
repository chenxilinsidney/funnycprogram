/**
 * @file id_515.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-27
 */

#include <iostream>
#include <limits>
#include <queue>

#define INF numeric_limits<int>::max()
#define MAXVEX 100
#define MAXEDGE 100

first[MAXVEX];
d[MAXVEX];
u[MAXEDGE];
v[MAXEDGE];
w[MAXEDGE];
next[MAXEDGE];
int numVertexes;
int numEdges;

int main(void)
{
    int s, n, k, a, b;
    string o;
    while (cin >> numVertexes && numVertexes != 0) {
        // read
        for (int i = 1; i <= numVertexes; i++) first[i] = -1;
        cin >> numEdges;
        for (int i = 0; i < numEdges; i++) {
            cin >> s >> n >> o >> k;
            if (o == "gt") {
                a = s;
                b = s + n;
            } else {
                a = s + n;
                b = s;
                k = -1 * k;
            }
            u[i] = a;
            v[i] = b;
            w[i] = k;
            next[i] = first[u[i]];
            first[u[i]] = i;
        }
        // spfa

    }
}
