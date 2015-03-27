/**
 * @file id_152.cpp
 * @brief AOAPC I 152
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-27
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string string_to_lower(string str)
{
    for (string::iterator it = str.begin(); it != str.end(); it++)
        *it = tolower(*it);
    return str;
}

int main()
{
    // remove repeat element and sort by multimap
    string word;
    multimap<string, string> map_word;
    while (cin >> word && word != "#") {
        string word_lower = string_to_lower(word);
        sort(word_lower.begin(), word_lower.end());
        map_word.insert(make_pair(word_lower, word));
    }
    vector<string> word_special;
    for (multimap<string, string>::iterator it = map_word.begin();
            it != map_word.end(); it++) {
        if (map_word.count(it->first) == 1)
            word_special.push_back(it->second);
    }
    sort(word_special.begin(), word_special.end());
    for (vector<string>::iterator it = word_special.begin();
            it != word_special.end(); it++)
        cout << *it << endl;
    return 0;
}
