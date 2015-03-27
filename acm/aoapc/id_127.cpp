/**
 * @file id_127.cpp
 * @brief AOAPC I 127
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-27
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool pile(const stack<string>& a, const stack<string>& b)
{
    return (a.top()[0] == b.top()[0] || a.top()[1] == b.top()[1]);
}

int main()
{
    vector<stack<string>> cards;
    string single_card;
    while (cin >> single_card && single_card[0] != '#') {
        // add pile to card
        stack<string> single_pile;
        single_pile.push(single_card);
        cards.push_back(single_pile);
        // proccess a group until spectial count
        if (cards.size() != 52)
            continue;
        int finish_flag = 1;
        int remain = cards.size();
        while (finish_flag) {
            finish_flag = 0;
            for (int i = 0; i < remain; i++) {
                int pile_flag = 1;
                while (pile_flag) {
                    pile_flag = 0;
                    if (i > 2 && pile(cards[i], cards[i - 3])) {
                        cards[i - 3].push(cards[i].top());
                        cards[i].pop();
                        if (cards[i].empty()) {
                            cards.erase(cards.begin() + i);
                            remain--;
                        }
                        i -= 3;
                        pile_flag = 1;
                        finish_flag = 1;
                        continue;
                    }
                    if (i > 0 && pile(cards[i], cards[i - 1])) {
                        cards[i - 1].push(cards[i].top());
                        cards[i].pop();
                        if (cards[i].empty()) {
                            cards.erase(cards.begin() + i);
                            remain--;
                        }
                        i--;
                        pile_flag = 1;
                        finish_flag = 1;
                        continue;
                    }
                }
            }
        }
        if (remain != 1)
            cout << remain << " piles remaining:";
        else
            cout << remain << " pile remaining:";
        for (size_t i = 0; i < cards.size(); i++) {
            cout << " " << cards[i].size(); 
        }
        cout << endl;
        // clear data
        cards.clear();
    }
    return 0;
}
