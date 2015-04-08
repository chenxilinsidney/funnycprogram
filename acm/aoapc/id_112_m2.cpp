/**
 * @file id_112.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-07
 */

#include <iostream>


using namespace std;

enum {
    LEFT_BRACKET,
    RIGHT_BRACKET,
    NUMBER,
    MATCH,
    NOT_MATCH,
    EMPTY_TREE
};

int traversal(const string& input, int start_index, int sum, int target)
{
#ifndef ONLINE_JUDGE
    cout << "in traversal" << endl;
#endif
    // empty tree
    if (input[start_index + 1] == ')') {
#ifndef ONLINE_JUDGE
    cout << "EMPTY_TREE" << endl;
#endif
        return EMPTY_TREE;
    }
    // get number
    start_index++;
    string number = "";
    while (input[start_index] != '(') {
        number += input[start_index];
        start_index++;
    }
#ifndef ONLINE_JUDGE
    cout << "number " << number << endl;
#endif
    int num = stoi(number);
#ifndef ONLINE_JUDGE
    cout << "stoi " << num << endl;
#endif
    sum += num;
#ifndef ONLINE_JUDGE
    cout << "temp sum:" << sum << "added " << num << endl;
#endif
    // left child
    int lc = traversal(input, start_index, sum, target);
    // right child
    int start_index_right = start_index;
    int num_left_bracket = 0;
    int num_right_bracket = 0;
    do {
        char c = input[start_index_right++];
        if (c == '(') num_left_bracket++;
        if (c == ')') num_right_bracket++;
    }
    while (num_left_bracket != num_right_bracket);
#ifndef ONLINE_JUDGE
    cout << "sub string:" << input.substr(start_index_right) << endl;
#endif
    int rc = traversal(input, start_index_right, sum, target);
    // leaf node
    if (lc == EMPTY_TREE && rc == EMPTY_TREE) {
        if (sum == target) {
#ifndef ONLINE_JUDGE
            cout << "MATCH BY EMPTY TREE" << endl;
#endif
            return MATCH;
        }
    }
    // match the sum
    if (lc == MATCH || rc == MATCH) {
#ifndef ONLINE_JUDGE
        cout << "MATCH" << endl;
#endif
        return MATCH;
    }
#ifndef ONLINE_JUDGE
    cout << "NOT_MATCH" << endl;
#endif
    return NOT_MATCH;
}

int main(void)
{
    int target;
    while (cin >> target) {
#ifndef ONLINE_JUDGE
        cout << "target:" << target << endl;
#endif
        string input = "(";
        char c;
        // get left bracket
        while (cin >> c && c != '(') ;
        int num_left_bracket = 1;
        int num_right_bracket = 0;
        while (num_left_bracket != num_right_bracket) {
            cin >> c;
#ifndef ONLINE_JUDGE
            cout << "char: " << (int)c << endl;
#endif
            input += c;
            if (c == '(') num_left_bracket++;
            if (c == ')') num_right_bracket++;
        }
#ifndef ONLINE_JUDGE
        cout << "string: " << input << endl;
#endif
        if (MATCH == traversal(input, 0, 0, target) ||
                EMPTY_TREE == traversal(input, 0, 0, target))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

