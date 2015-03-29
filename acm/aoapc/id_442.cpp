/**
 * @file id_442.cpp
 * @brief AOAPC I 442
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-29
 */

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

typedef struct {
    int matrix_row;
    int matrix_column;
} matrix_struct;

int main()
{
    // 1 <= num_matrix <= 26
    int num_matrix;
    cin >> num_matrix;
    cin.get();
    // add matrix to map
    map<char, matrix_struct> map_matrix;
    char matrix_name;
    matrix_struct matrix_info;
    while (num_matrix--) {
        cin >> matrix_name >> matrix_info.matrix_row
            >> matrix_info.matrix_column;
        map_matrix.insert(make_pair<char, matrix_struct>(
                    matrix_name, matrix_info));
    }
    cin.get();
    string expressions;
    while (getline(cin, expressions)) {
#ifndef ONLINE_JUDGE
        cout << expressions << endl;
#endif
        // single matrix
        if (expressions.size() == 1) {
            cout << '0' << endl;
            continue;
        }
        // expressions width '(' and ')'
        // count multiplications total values
        int multiplications = 0;
        stack<matrix_struct> stack_expression;
        for (size_t i = 0; i < expressions.size(); i++) {
            if (expressions[i] == ')') {
                // get two matrix
                matrix_struct right = stack_expression.top();
                stack_expression.pop();
                matrix_struct left = stack_expression.top();
                stack_expression.pop();
                // illegal
                if (left.matrix_column != right.matrix_row) {
                    multiplications = -1;
                    break;
                }
                // count multiplications
                multiplications += left.matrix_row *
                    left.matrix_column * right.matrix_column;
                // refresh stack
                matrix_struct result = {left.matrix_row,
                    right.matrix_column};
                stack_expression.push(result);
            } else if (expressions[i] != '(') {
                stack_expression.push(map_matrix[expressions[i]]);
            }
        }
        if (multiplications == -1)
            cout << "error" << endl;
        else
            cout << multiplications << endl;
    }
    return 0;
}
