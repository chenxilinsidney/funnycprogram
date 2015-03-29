/**
 * @file id_11234.cpp
 * @brief AOAPC I 11234
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-29
 */

#include <iostream>
#include <cctype>
#include <string>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int num_expression;
    cin >> num_expression;
    cin.get();
    string expression;
    while (num_expression--) {
        getline(cin, expression);
        // to original expression
        deque<char> deque_expression;
        for (size_t i = 0; i < expression.size(); i++) {
            if (islower(expression[i])) {
                deque_expression.push_back(expression[i]);
            } else {
                // get temp value a and b by stack
                stack<char> temp_stack_exp1;
                stack<char> temp_stack_exp2;
                int flag_pair = 0;
                int flag_num = 0;
                while (flag_num != 2 && !deque_expression.empty()) {
                    if (deque_expression.back() == ')')
                        flag_pair++;
                    else if (deque_expression.back() == '(')
                        flag_pair--;
                    if (flag_num == 0)
                        temp_stack_exp1.push(deque_expression.back());
                    else
                        temp_stack_exp2.push(deque_expression.back());
                    deque_expression.pop_back();
                    if (flag_pair == 0)
                        flag_num++;
                }
#ifndef ONLINE_JUDGE
                cout << "temp stack 1: " << temp_stack_exp1.size() << endl;
                cout << "temp stack 2: " << temp_stack_exp2.size() << endl;
#endif
                // get queue like (b a A)
                queue<char> temp_expression;
                temp_expression.push('(');
                while (!temp_stack_exp1.empty()) {
                    temp_expression.push(temp_stack_exp1.top());
#ifndef ONLINE_JUDGE
                    cout<< "temp stack 1:" << temp_stack_exp1.top() << endl;
#endif
                    temp_stack_exp1.pop();
                }
                while (!temp_stack_exp2.empty()) {
                    temp_expression.push(temp_stack_exp2.top());
#ifndef ONLINE_JUDGE
                    cout<< "temp stack 2:" << temp_stack_exp2.top() << endl;
#endif
                    temp_stack_exp2.pop();
                }
                temp_expression.push(expression[i]);
                temp_expression.push(')');
                while (!temp_expression.empty()) {
                    deque_expression.push_back(temp_expression.front());
#ifndef ONLINE_JUDGE
                    cout<< "temp queue:" << temp_expression.front() << endl;
#endif
                    temp_expression.pop();
                }
            }
        }
        string explain;
        while (!deque_expression.empty()) {
            explain += deque_expression.front();
            deque_expression.pop_front();
        }
#ifndef ONLINE_JUDGE
        cout << explain << endl;
        cout << explain.size() << endl;
#endif
        // queue expression
        char* queue_expression = new char[expression.size() + 1];
        int queue_expression_index = expression.size();
        queue_expression[queue_expression_index--] = '\0';
        while (explain.size() > 0) {
            size_t i = explain.size() - 1;
            if (explain[i] == ')') {
                queue_expression[queue_expression_index--] = explain[i - 1];
                int flag = 0;
                for (size_t k = i; k >= 0; k--) {
                    if (explain[k] == ')')
                        flag++;
                    if (explain[k] == '(')
                        flag--;
                    if (flag == 0) {
                        flag = k;
                        break;
                    }
                }
                if (flag == 0) {
                    explain = explain.substr(1, i - 2);
                } else {
                    explain =
                        explain.substr(flag + 1, i - flag - 2) +
                        explain.substr(0, flag);
                }
            } else {
                queue_expression[queue_expression_index--] = explain[i];
                explain = explain.substr(0, i);
            }
        }
        // output result
        cout << queue_expression << endl;
    }
    return 0;
}
