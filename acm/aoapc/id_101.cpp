/**
 * @file id_101.cpp
 * @brief AOAPC I 101
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-27
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > blocks;

int main()
{
    // get block numbers < 25
    int num_blocks;
    cin >> num_blocks;
    cin.get();
    for (int i = 0; i < num_blocks; i++) {
        vector<int> block;
        block.push_back(i);
        blocks.push_back(block);
    }
    string command;
    int value_a;
    int value_b;
    string position;
    while (cin >> command && command != "quit") {
        cin >> value_a >> position >> value_b;
#ifndef ONLINE_JUDGE
        cout << command << value_a << position << value_b << endl;
#endif
        cin.get();
        queue<int> data;
        // ignore illegal command
        if (value_a == value_b) continue;
        int blocks_a, blocks_b;
        int block_a, block_b;
        for (size_t i = 0; i < blocks.size(); i++) {
            for (size_t j = 0; j < blocks[i].size(); j++) {
                if (blocks[i][j] == value_a) {
                    blocks_a = i;
                    block_a = j;
                }
                if (blocks[i][j] == value_b) {
                    blocks_b = i;
                    block_b = j;
                }
            }
        }
        if (blocks_a == blocks_b) continue;
        // move and pile
        if (command == "move") {
            // move a only
            data.push(value_a);
            // return any blocks that are stacked on top of a to their
            // initial position
            for (size_t k = block_a + 1; k < blocks[blocks_a].size(); k++) {
                int i = blocks[blocks_a][k];
                blocks[i].push_back(i);
            }
        } else {
            // pile a
            for (size_t k = block_a; k < blocks[blocks_a].size(); k++)
                data.push(blocks[blocks_a][k]);
        }
        // remove old data of a
        blocks[blocks_a].erase(blocks[blocks_a].begin() + block_a,
                blocks[blocks_a].end());
#ifndef ONLINE_JUDGE
        cout << "data:" << data.size() << endl;
#endif
        // onto and over
        if (position == "over") {
            // onto the top of stack containing block b
            while (!data.empty()) {
                blocks[blocks_b].push_back(data.front());
                data.pop();
            }
        } else {
            // return any blocks that are stacked on top of b to their
            // initial position
            for (size_t k = block_b + 1; k < blocks[blocks_b].size(); k++) {
                int i = blocks[blocks_b][k];
                blocks[i].push_back(i);
            }
            // clear
            blocks[blocks_b].erase(blocks[blocks_b].begin() + block_b + 1,
                    blocks[blocks_b].end());
        }
        // refresh new data of a
        while (!data.empty()) {
            blocks[blocks_b].insert(blocks[blocks_b].begin() + block_b + 1,
                    data.front()); 
            data.pop();
        }
    }
    // output result
    for (size_t i = 0; i < blocks.size(); i++) {
        cout << i << ":";
        for (size_t j = 0; j < blocks[i].size(); j++) {
            cout << " " << blocks[i][j];
        }
        cout << endl;
    }
    return 0;
}
