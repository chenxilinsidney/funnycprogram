/**
 * @file id_327.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

#define WIDTH 115
char array[WIDTH] = {0};
bool flag_letter[26] = {0};
int flag_letter_before[26] = {0};
int flag_letter_after[26] = {0};

using namespace std;

int main(void)
{
    while (gets(array)) {
        // reset letter
        memset(flag_letter, 0, sizeof(bool) * 26);
        memset(flag_letter_before, 0, sizeof(int) * 26);
        memset(flag_letter_after, 0, sizeof(int) * 26);
        // process
        int length = strlen(array);
        string ignore_blank = "";
        for (int index = 0; index < length; index++) {
            if (array[index] != ' ')
                ignore_blank += array[index];
        }
        // get ++ --
        for (size_t index = 0; index < ignore_blank.size(); index++) {
            if (islower(ignore_blank[index])) {
                flag_letter[ignore_blank[index] - 'a'] = true;
                if (index >= 2) {
                    if (ignore_blank[index - 1] ==
                            ignore_blank[index - 2] &&
                            ignore_blank[index - 1] == '+') {
                        flag_letter_before[ignore_blank[index] - 'a'] = 1;
                        ignore_blank.erase(index - 2, 2);
                        index -= 2;
                    } else if (ignore_blank[index - 1] ==
                            ignore_blank[index - 2] &&
                            ignore_blank[index - 1] == '-') {
                        flag_letter_before[ignore_blank[index] - 'a'] = -1;
                        ignore_blank.erase(index - 2, 2);
                        index -= 2;
                    }
                }
                if (2 + index < ignore_blank.size()) {
                    if (ignore_blank[index + 1] ==
                            ignore_blank[index + 2] &&
                            ignore_blank[index + 1] == '+') {
                        flag_letter_after[ignore_blank[index] - 'a'] = 1;
                        ignore_blank.erase(index + 1, 2);
                    } else if (ignore_blank[index + 1] ==
                            ignore_blank[index + 2] &&
                            ignore_blank[index + 1] == '-') {
                        flag_letter_after[ignore_blank[index] - 'a'] = -1;
                        ignore_blank.erase(index + 1, 2);
                    }
                }
            }
        }
#ifndef ONLINE_JUDGE
        cout << "value: " << ignore_blank << endl;
#endif
        // get sum
        int sum = ignore_blank[0] - 'a' + 1 +
            flag_letter_before[ignore_blank[0] - 'a'];
        for (size_t index = 1; index < ignore_blank.size(); index++) {
            if (ignore_blank[index] == '+') {
                sum += ignore_blank[index + 1] - 'a' + 1 +
                    flag_letter_before[ignore_blank[index + 1] - 'a'];
                index++;
            } else if (ignore_blank[index] == '-') {
                sum -= ignore_blank[index + 1] - 'a' + 1 +
                    flag_letter_before[ignore_blank[index + 1] - 'a'];
                index++;
            } 
        }
        // print result
        cout << "Expression: " << array << endl;
        cout << "    value = " << sum << endl;
        for (int i = 0; i < 26; i++) {
            if (flag_letter[i])
                cout << "    " << char(i + 'a') << " = " <<
                    flag_letter_before[i] + i + 1 + flag_letter_after[i]
                    << endl;
        }
    }
    return 0;
}
