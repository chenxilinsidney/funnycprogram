/**
 * @file id_10785.cpp
 * @brief AOAPC I 10785
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-27
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string vowel_list = "AAAAAAAAAAAAAAAAAAAAAUUUUUUUUUUUUUUUUUUUUUEEEEEEEEEEEEEEEEEEEEEOOOOOOOOOOOOOOOOOOOOOIIIIIIIIIIIIIIIIIIIII";
string consonant_list = "JJJJJSSSSSBBBBBKKKKKTTTTTCCCCCLLLLLDDDDDMMMMMVVVVVNNNNNWWWWWFFFFFXXXXXGGGGGPPPPPYYYYYHHHHHQQQQQZZZZZRRRRR";

int main()
{
    int num_case;
    cin >> num_case;
    for (int index_case = 1; index_case <= num_case; index_case++) {
        // input length
        int length;
        cin >> length;
#ifndef ONLINE_JUDGE
        cout << "length = " << length << endl;
#endif
        int count_even = length / 2;
        int count_odd = length - count_even;
        string vowel = vowel_list.substr(0, count_odd);
        string consonant = consonant_list.substr(0, count_even);
        sort(vowel.begin(), vowel.end());
        sort(consonant.begin(), consonant.end());
        cout << "Case " << index_case << ": ";
        for (int i = 0; i < count_even; i++)
            cout << vowel[i] << consonant[i];
        if (count_odd > count_even)
            cout << vowel.back();
        cout << endl;
    }
    return 0;
}
