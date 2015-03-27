
/**
 * @file id_123.cpp
 * @brief AOAPC I 123
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-27
 */

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

string string_to_upper(string str)
{
    for (string::iterator it = str.begin(); it != str.end(); it++)
        *it = toupper(*it);
    return str;
}

string string_to_lower(string str)
{
    for (string::iterator it = str.begin(); it != str.end(); it++)
        *it = tolower(*it);
    return str;
}

int main()
{
    // get word ignore list
    set<string> word_ignore_list;
    string word;
    while (getline(cin, word)) {
        if (word == "::")
            break;
        else
            word_ignore_list.insert(word);
    }
    cout << "word list size: " << word_ignore_list.size() << endl;
    // get title list
    multimap<string, string> kwic;
    string title;
    while (getline(cin, title)) {
        title = string_to_lower(title);
        string titile_modified = title;
        string key;
        // get kwic list
        for (int i = 0; i <= title.size(); i++) {
            if ((title[i] == ' ' || i == title.size()) && !key.empty()) {
                if (!word_ignore_list.count(key)) {
                    key = string_to_upper(key);
                    titile_modified.replace(i - key.size(),
                            key.size(), key);
                    kwic.insert(make_pair(key, titile_modified));
                    titile_modified = title;
                }
                key.clear();
            } else {
                key += title[i];
            }
        }
    }
    for (multimap<string, string>::iterator it = kwic.begin();
            it != kwic.end(); it++)
        cout << it->second << endl;
    return 0;
}
