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

bool pile(const char* a, const char* b)
{
    return (a[0] == b[0] || a[1] == b[1]);
}

char single_card[52][3];

int main()
{
    vector< stack<char*> > cards;
    int single_card_index = 0;
    while (cin >> single_card[single_card_index] &&
            single_card[single_card_index][0] != '#') {
        // add pile to card
        stack<char*> single_pile;
        single_pile.push(single_card[single_card_index]);
        cards.push_back(single_pile);
        single_card_index++;
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
                    if (i > 2 && pile(cards[i].top(), cards[i - 3].top())) {
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
                    if (i > 0 && pile(cards[i].top(), cards[i - 1].top())) {
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
        single_card_index = 0;
        cards.clear();
    }
    return 0;
}
