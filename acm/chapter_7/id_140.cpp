/**
 * @file id_140.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-29
 */

#include <iostream>
#include <cstring>

using namespace std;

#define MAXVEX 30
#define MAXEDGE MAXVEX * MAXVEX

string line;
bool vertex[MAXVEX];
int hash[10];
bool visit[10];
int grid[MAXVEX][MAXVEX];
int numVertex;
int min_bandwidth;

int key_max[10];
int key_temp[10];

void dfs(int cur, int max_bandwidth)
{
#ifndef ONLINE_JUDGE
    cout << "dfs: " << cur << "," << max_bandwidth << endl;
    for (int i = 0; i < cur; i++)
        cout << char(key_temp[i] + 'A') << " ";
    cout << endl;
#endif
    if (cur == numVertex) {
        if (min_bandwidth > max_bandwidth) {
            min_bandwidth = max_bandwidth;
            memcpy(key_max, key_temp, sizeof(key_max[0]) * cur);
            for (int i = 0; i < cur; i++) key_max[i] = key_temp[i];
        } 
    }
    for (int i = 0; i < numVertex; i++) {
        if (!visit[i]) {
            bool flag_add = true;
            int max = max_bandwidth;
            for (int j = 0; j < cur; j++) {
                if (grid[key_temp[j]][hash[i]]) {
                    if (cur - j >= min_bandwidth) {
                        flag_add = false;
                        break;
                    }
                    if (cur - j > max) max = cur - j;
                }
                for (int k = 0; k < numVertex; k++) {
                    if (grid[key_temp[j]][hash[k]] &&
                            k != i && !visit[k] &&
                            cur + 1 - j >= min_bandwidth) {
                        flag_add = false;
                        break;
                    }
                }
            }
            if (flag_add) {
                visit[i] = 1;
                key_temp[cur] = hash[i];
                dfs(cur + 1, max);
                visit[i] = 0;
            }
        }
    }
}

int main(void)
{
    while (getline(cin, line) && line[0] != '#') {
        // init edge and vertex
        for (int i = 0; i < MAXVEX; i++) vertex[i] = false;
        for (int i = 0; i < MAXVEX; i++)
            for (int j = 0; j < MAXVEX; j++)
                grid[i][j] = 0;
        // get graph
        int edge_from, edge_to;
        for (size_t i = 0; i < line.size(); i++) {
            edge_from = line[i] - 'A';
            vertex[edge_from] = true;
            i += 2;
            while (line[i] != ';' && i < line.size()) {
                edge_to = line[i] - 'A';
                vertex[edge_to] = true;
                grid[edge_from][edge_to] = 1;
                grid[edge_to][edge_from] = 1;
                i++;
            }
        }
        // get hash table
        numVertex = 0;
        for (int i = 0; i < MAXVEX; i++) {
            if (vertex[i])
                hash[numVertex++] = i;
        }
        // dfs
        min_bandwidth = 1000;
        for (int i = 0; i < numVertex; i++) {
            for (int j = 0; j < numVertex; j++) visit[j] = false;
            key_temp[0] = hash[i];
            visit[0] = true;
#ifndef ONLINE_JUDGE
            cout << "begin with: " << i << endl;
            cout << "begin with: " << char(key_temp[0] + 'A') << endl;
#endif
            dfs(1, 0);
        }
        // output
        for (int i = 0; i < numVertex; i++)
            cout << char(key_max[i] + 'A') << " ";
        cout << "-> " << min_bandwidth << endl;
    }
    return 0;
}
