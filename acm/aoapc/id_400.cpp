
/**
 * @file id_400.cpp
 * @brief AOAPC I 400
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-24
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cfloat>

using namespace std;

int main()
{
    int num_file_names;
    while (cin >> num_file_names) {
        vector<string> list;
        cin.get();
        // scan to get list and get max length
        string line;
        int max_length = 0;
        int temp_length = 0;
        for (int list_index = 0; list_index < num_file_names;
                list_index++) {
            getline(cin, line);
            list.push_back(line);
            if ((temp_length = line.size()) > max_length)
                max_length = temp_length;
        }
        // sort list
        sort(list.begin(), list.end());
        // get column and row
        int column = (int)(62.0 / (max_length + 2) + DBL_EPSILON);
        double row_f = num_file_names * 1.0 / column;
        int row = (int)(row_f + DBL_EPSILON);
        if (row * 1.0 - row_f > DBL_EPSILON ||
                row * 1.0 - row_f < -1 * DBL_EPSILON)
            row++;
        // print result
        for (int i = 0; i < 60; i++)
            cout << '-';
        cout << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                int index = i + row * j;
                if (index >= num_file_names)
                    break;
                int space = max_length + 2 - list[index].size();
                cout << list[index];
                if (j == column - 1) space -= 2;
                if (j == column - 2 && index + row >= num_file_names) continue;
                if (space > 0)
                    while (space--) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
