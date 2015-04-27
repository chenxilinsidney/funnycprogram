/**
 * @file id_10801.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-27
 */

#include <iostream>
#include <string>
#include <limits>
#include <queue>

using namespace std;

#define MAXVEX 102
#define INF numeric_limits<int>::max()

int first[MAXVEX];
int d[MAXVEX];
int c[MAXVEX];
int parent[MAXVEX];
int flag_p[MAXVEX * MAXVEX];
int u[MAXVEX * MAXVEX];
int v[MAXVEX * MAXVEX];
int next_edge[MAXVEX * MAXVEX];
int w[MAXVEX * MAXVEX];
int num_elevators;
int num_edges;
int speed[5];
int elevator[MAXVEX];
int targetfloor;
string line;
typedef pair<int, int> pii;
priority_queue< pii, vector<pii>, greater<pii> > q;
int main(void)
{
    while (cin >> num_elevators) {
        // read
        cin >> targetfloor;
        for (int i = 0; i < num_elevators; i++)
            cin >> speed[i];
        // init
        num_edges = 0;
        for (int i = 0; i < MAXVEX; i++) first[i] = -1;
        cin.get();
        for (int i = 0; i < num_elevators; i++) {
            getline(cin, line);
            bool flag = false;
            int start = 0;
            int count = 0;
            for (size_t k = 0; k <= line.size(); k++) {
                if (!flag && (!isdigit(line[k]) || k == line.size())) {
                    string number = line.substr(start, k - start);
                    elevator[count++] = stoi(number);
                    flag = true;
                }
                if (flag && isdigit(line[k])) {
                    flag = false;
                    start = k;
                }
            }
            for (int k = 0; k < count - 1; k++) {
                w[num_edges] = speed[i] * (elevator[k + 1] - elevator[k]);
                u[num_edges] = elevator[k];
                v[num_edges] = elevator[k + 1];
                next_edge[num_edges] = first[u[num_edges]];
                first[u[num_edges]] = num_edges;
                flag_p[num_edges] = i;
                num_edges++;
                w[num_edges] = w[num_edges - 1];
                u[num_edges] = elevator[k + 1];
                v[num_edges] = elevator[k];
                next_edge[num_edges] = first[u[num_edges]];
                first[u[num_edges]] = num_edges;
                flag_p[num_edges] = i;
                num_edges++;
            }
        }
        // Dijkstra
        for (int i = 0; i < MAXVEX; i++) {
            d[i] = INF;
            parent[i] = -1;
            c[i] = -1;
        }
        d[0] = 0;
        q.push(make_pair(d[0], 0));
        while (!q.empty()) {
            pii top = q.top();
            q.pop();
            int index = top.second;
            if (top.first != d[index]) continue;
            for (int i = first[index]; i != -1; i = next_edge[i]) {
                if (d[index] != INF && d[index] + w[i] < d[v[i]]) {
                    d[v[i]] = d[index] + w[i];
                    c[v[i]] = flag_p[i];
                    parent[v[i]] = index;
                    q.push(make_pair(d[v[i]], v[i]));
                }
            }
        }
        if (d[targetfloor] == INF) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        // sum
        int count = 0;
        int temp = targetfloor;
        while (parent[temp] != -1) {
            if (c[temp] != c[parent[temp]])
                count++;
            temp = parent[temp];
        }
        cout << count * 60 + d[targetfloor] << endl;
    }
    return 0;
}
