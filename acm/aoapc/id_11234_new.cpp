/**
 * @file id_11234.cpp
 * @brief AOAPC I 11234
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-29
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    char data;
    int left_index;
    int right_index;
};

Node node[10005];

string expression;

char result[10005];
int result_index;

int main()
{
    int num_expression;
    cin >> num_expression;
    cin.get();
    while (num_expression--) {
        // get expression
        getline(cin, expression);
        int expression_length = expression.size();
        stack<int> stack_expression;
        // explain by stack and create binary tree
        for (size_t i = 0; i < expression_length; i++) {
            if (islower(expression[i])) {
                // add node index to stack
                stack_expression.push(i);
                // node with no child
                node[i].data = expression[i];
                node[i].left_index = -1;
                node[i].right_index = -1;
            } else {
                // pop to node index from stack
                int right_index = stack_expression.top();
                stack_expression.pop();
                int left_index = stack_expression.top();
                stack_expression.pop();
                // node with child
                node[i].data = expression[i];
                node[i].left_index = left_index;
                node[i].right_index = right_index;
                stack_expression.push(i);
            }
        }
        // root node index
        int root = stack_expression.top();
        // queue
        result_index = expression_length;
        result[result_index] =  '\0';
        queue<int> queue_expression;
        queue_expression.push(root);
        result[--result_index] = node[root].data;
        while (!queue_expression.empty()) {
            int t = queue_expression.front();
            queue_expression.pop();
            if (node[t].left_index != -1) {
                result[--result_index] = node[node[t].left_index].data;
                queue_expression.push(node[t].left_index);
            }
            if (node[t].right_index != -1) {
                result[--result_index] = node[node[t].right_index].data;
                queue_expression.push(node[t].right_index);
            }
        }
        cout << result << endl;
    }
    return 0;
}
