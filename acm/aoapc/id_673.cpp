/**
 * @file id_673.cpp
 * @brief AOAPC I 673
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-29
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool ispair(char a, char b)
{
    return (a == '[' && b == ']') || (a == '(' && b == ')');
}
int main()
{
    int num_strings;
    cin >> num_strings;
    cin.get();
    string parantheses;
    while (num_strings--) {
        getline(cin, parantheses);
        stack<char> parantheses_stack;
        for (int i = 0; i < parantheses.size(); i++) {
            if (parantheses_stack.empty()) {
                parantheses_stack.push(parantheses[i]);
            } else {
                if (ispair(parantheses_stack.top(), parantheses[i]))
                    parantheses_stack.pop();
                else
                    parantheses_stack.push(parantheses[i]);
            }
        }
        if (parantheses_stack.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
