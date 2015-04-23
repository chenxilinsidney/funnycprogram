/**
 * @file id_196.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-17
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

#define MAXGRIDROW 999                   // maximum grid rows in the graph
#define MAXGRIDCOL 18278                 // maximum grid columns in the graph

// single grid data type
typedef struct {
    int key;
    vector<int> formula;
    bool number;
} GridType;                  // grid data type
// graph data structure
typedef struct {
    GridType grid[MAXGRIDROW + 2][MAXGRIDCOL + 2];
    // grid matrix with extra bound
    int num_rows;                             // matrix row numbers
    int num_columns;                          // matrix column numbers
} Graph;
// create graph method
void CreateGraph(Graph& G)
{
    // input graph row and column numbers
    cin >> G.num_columns >> G.num_rows;
    cin.get();
#ifndef ONLINE_JUDGE
    cout << "row: " << G.num_rows << ",col: " << G.num_columns << endl;
#endif
    // get grid data from input
    string line;
    for (int index_row = 1; index_row <= G.num_rows; index_row++) {
        getline(cin, line);
#ifndef ONLINE_JUDGE
        cout << "line: " << line << endl;
#endif
        size_t start_index = 0;
        int index_col = 1;
        for (size_t i = 0; i <= line.size(); i++) {
            if (line[i] == ' ' || i == line.size()) {
                if (line[start_index] != '=') {
                    G.grid[index_row][index_col].number = true;
                    // char to number, mind the negative flag
                    if (line[start_index] == '-')
                        G.grid[index_row][index_col].key =
                            -1 * stoi(line.substr(start_index + 1,
                                        i - start_index - 1));
                    else if (line[start_index] == '+')
                        G.grid[index_row][index_col].key =
                            stoi(line.substr(start_index + 1,
                                        i - start_index - 1));
                    else
                        G.grid[index_row][index_col].key =
                            stoi(line.substr(start_index, i - start_index));
                } else {
                    // formula to row and column
                    G.grid[index_row][index_col].number = false;
                    G.grid[index_row][index_col].key = 0;
                    G.grid[index_row][index_col].formula.clear();
                    for (size_t k = start_index + 1; k < i; k++) {
                        int column = 0;
                        int row = 0;
                        while (isupper(line[k])) {
                            column = column * 26 + (line[k] - 'A' + 1);
                            k++;
                        }
                        while (isdigit(line[k])) {
                            row = row * 10 + (line[k] - '0');
                            k++;
                        }
                        G.grid[index_row][index_col].formula.push_back(row);
                        G.grid[index_row][index_col].formula.push_back(column);
                    }
                }
                // fresh start_index
                start_index = i + 1;
                // set flag for dfs
                index_col++;
            }
        }
    }
}
// DFS method
int DFS_VISIT(Graph& G, int i, int j)
{
    if (G.grid[i][j].number)
        return G.grid[i][j].key;
    int sum = 0;
    for (size_t k = 0; k < G.grid[i][j].formula.size(); k += 2) {
        sum += DFS_VISIT(G, G.grid[i][j].formula[k],
                G.grid[i][j].formula[k + 1]);
    }
    G.grid[i][j].key = sum;
    G.grid[i][j].number = true;
    return sum;
}
void DFS(Graph& G) {
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j <= G.num_columns; j++) {
            if (!G.grid[i][j].number) {
                DFS_VISIT(G, i, j);
            }
        }
    }
}
// display graph
void DisplayGraph(Graph& G)
{
    for (int i = 1; i <= G.num_rows; i++) {
        for (int j = 1; j < G.num_columns; j++) {
                cout << G.grid[i][j].key << " ";
        }
        cout << G.grid[i][G.num_columns].key << endl;
    }
}
// global
Graph G;
int main(void)
{
    int num_cases;
    cin >> num_cases;
#ifndef ONLINE_JUDGE
    cout << "num_cases: " << num_cases << endl;
#endif
    while (num_cases--) {
        CreateGraph(G);
        DFS(G);
        DisplayGraph(G);
    }
    return 0;
}
