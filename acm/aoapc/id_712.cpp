/**
 * @file id_712.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char terminal[65];

int main(void)
{
    int depth;
    int num_case = 1;
    while (cin >> depth && depth != 0) {
        cin.get();
        // print result
        cout << "S-Tree #" << num_case++ << ":" << endl;
        // get x
        int function_x[8] = {0};
        int num = 0;
        char temp_char[3];
        while (num < depth) {
            cin >> temp_char;
            function_x[num++] = int(temp_char[1] - '1');
        }
#ifndef ONLINE_JUDGE
        for (int index = 0; index < depth; index++)
            cout << "function x: " << function_x[index] << endl;
#endif
        cin.get();
        // get terminal node
        gets(terminal);
        int terminal_length = strlen(terminal);
#ifndef ONLINE_JUDGE
        cout << "terminal_length x: " << terminal_length << endl;
        for (int index = 0; index < terminal_length; index++)
            cout << "terminal x: " << terminal[index] << endl;
#endif
        char x[8] = {0};
        int num_m;
        unsigned int temp;
        cin >> num_m;
        cin.get();
        while (num_m--) {
            num = 0;
            while (num < depth) cin >> x[num++];
#ifndef ONLINE_JUDGE
            for (int index = 0; index < depth; index++)
                cout << "x: " << x[index] << endl;
#endif
            temp = terminal_length >> 1;
            int offset = 0;
            // process
            for (int index = 0; index < depth; index++) {
                if (x[function_x[index]] == '1') offset += temp;
                temp >>= 1;
            }
            // print result
#ifndef ONLINE_JUDGE
            cout << "offset" << offset << endl;
#endif
            cout << terminal[offset];
            cin.get();
        }
        // print result
        cout << endl << endl;
    }
    return 0;
}

