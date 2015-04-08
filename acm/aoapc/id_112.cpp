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

int getToken(int* num)
{
    char c = cin.get();
    while (c == ' ' || c == '\n')
        c = cin.get();
    *num = 0;
    if (c == '(') {
        return LEFT_BRACKET;
    } else if (c == ')') {
        return RIGHT_BRACKET;
    } else if ((c >= '0' && c <= '9') || c == '-') {
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = cin.get();
        }
        for (; c >= '0' && c <= '9'; c = cin.get())
            *num = *num * 10 + (c - '0');
        *num *= sign;
        cin.unget();
        return NUMBER;
    }
    return -1;
}

int traversal(int sum, int target)
{
#ifndef ONLINE_JUDGE
    cout << "in traversal" << endl;
#endif
    int num;
    // left bracket
    getToken(&num);
    // get key
    int token = getToken(&num);
    if (token == RIGHT_BRACKET) {
#ifndef ONLINE_JUDGE
    cout << "EMPTY_TREE" << endl;
#endif
        return EMPTY_TREE;
    } else {
        sum += num;
#ifndef ONLINE_JUDGE
    cout << "temp sum:" << sum << "added " << num << endl;
#endif
    }
    // left child
    int lc = traversal(sum, target);
    // right child
    int rc = traversal(sum, target);
    // right bracket
    getToken(&num);
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
        if (MATCH == traversal(0, target))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}

