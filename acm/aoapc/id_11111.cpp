/**
 * @file id_11111.cpp
 * @brief AOAPC I 11111
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-29
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

#define MAX_LINE_WIDTH 1025
char line[MAX_LINE_WIDTH];

int main()
{
    string str_sequence;
    while (fgets(line, MAX_LINE_WIDTH, stdin)) {
        // stack to process
        stack<int> sequence;
        bool sequence_result = true;
        // string to int
        int line_length = strlen(line);
        bool flag = true;
        for (int i = 0; i <= line_length; i++) {
            if (flag && line[i] != ' ') {
                int value = atoi(line + i);
                // process with value;
                if (value < 0) {
                    sequence.push(value);
                } else {
                    // get container value state
                    int sub = 0;
                    while (!sequence.empty() && sequence.top() > 0) {
                        sub += sequence.top();
                        sequence.pop();
                    }
                    if (sequence.empty() || sequence.top() != -1 * value ||
                            sub >= value) {
                        // not in pair by count
                        // not in pair by value
                        // not in right value state
                        sequence_result = false;
                        break;
                    } else {
                        // remove unused value
                        sequence.pop();
                        // push new value state
                        sequence.push(value);
                    }
                }
                flag = false;
            } else if (!flag && line[i] == ' ') {
                flag = true;
            }
        }
        if (sequence.size() != 1 || !sequence_result)
            cout << ":-( Try again." << endl;
        else
            cout << ":-) Matrioshka!" << endl;
    }
    return 0;
}
