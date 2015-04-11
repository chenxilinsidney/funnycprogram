/**
 * @file id_297.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <string>
#include <queue>
#include <cassert>
#include <cmath>

using namespace std;

typedef struct Node {
    char key;
    struct Node* child[4];
} Node;

Node* build_tree_inorder(const char* inorder,
        int inorder_length)
{
    assert(inorder_length >= 0);
    Node* temp = new Node;
    temp->child[0] = NULL;
    temp->child[1] = NULL;
    temp->child[2] = NULL;
    temp->child[3] = NULL;
    temp->key = inorder[0];
    if (inorder[0] != 'p') {
#ifndef ONLINE_JUDGE
        cout << "key: " << temp->key << endl;
#endif
        return temp;
    }
    // get child
    int inorder_index = 1;
    int four_index[5] = {0};
    for (int i = 0; i < 4; i++) {
        int flag = 0;
        int count_p = 0;
        do {
            if (inorder[inorder_index] == 'p') {
                flag -= 4;
                count_p++;
            } else {
                flag += 1;
            }
            inorder_index++;
        } while (inorder_index < inorder_length && flag < -1 * count_p + 1);
        four_index[i + 1] = inorder_index - 1;
    }
#ifndef ONLINE_JUDGE
    cout << "four index: " << four_index[0] << endl;
    cout << "four index: " << inorder[four_index[0]] << endl;
    cout << "four index: " << four_index[1] << endl;
    cout << "four index: " << inorder[four_index[1]] << endl;
    cout << "four index: " << four_index[2] << endl;
    cout << "four index: " << inorder[four_index[2]] << endl;
    cout << "four index: " << four_index[3] << endl;
    cout << "four index: " << inorder[four_index[3]] << endl;
#endif
    for (int i = 0; i < 4; i++) {
        temp->child[i] = build_tree_inorder(inorder + four_index[i] + 1,
                four_index[i + 1] - four_index[i]);
    }
    return temp;
}

void display_tree_inorder(Node* root)
{
    if (root != NULL) {
        cout << root->key << " ";
        for (int i = 0; i < 4; i++)
            display_tree_inorder(root->child[i]);
    }
}

void display_tree_levelorder(Node* root)
{
    queue<Node*> tree_level;
    tree_level.push(root);
    while (!tree_level.empty()) {
        cout << (tree_level.front())->key << " ";
        for (int i = 0; i < 4; i++) {
            Node* temp;
            if ((temp = (tree_level.front())->child[i]) != NULL)
                tree_level.push(temp);
        }
        tree_level.pop();
    }
}

void destroy_tree(Node* root)
{
    if (root != NULL) {
        for (int i = 0; i < 4; i++) {
            destroy_tree(root->child[i]);
        }
        delete root;
    }
}

int sum = 0;

void new_tree(int level, Node* root_a, Node* root_b)
{
    if (root_a == NULL && root_b == NULL)
        return;
    if ((root_a != NULL && root_a->key == 'f') ||
            (root_b != NULL && root_b->key == 'f')) {
        sum += pow(pow(2, (5 - level)), 2);
#ifndef ONLINE_JUDGE
        cout << "sum: " << sum << endl;
#endif
    } else if (root_a != NULL && root_b != NULL &&
            root_a->key == 'p' && root_b->key == 'p') {
        new_tree(level + 1, root_a->child[0], root_b->child[0]);
        new_tree(level + 1, root_a->child[1], root_b->child[1]);
        new_tree(level + 1, root_a->child[2], root_b->child[2]);
        new_tree(level + 1, root_a->child[3], root_b->child[3]);
    } else if (root_a != NULL && root_a->key == 'p') {
        new_tree(level + 1, root_a->child[0], NULL);
        new_tree(level + 1, root_a->child[1], NULL);
        new_tree(level + 1, root_a->child[2], NULL);
        new_tree(level + 1, root_a->child[3], NULL);
    } else if (root_b != NULL && root_b->key == 'p') {
        new_tree(level + 1, NULL, root_b->child[0]);
        new_tree(level + 1, NULL, root_b->child[1]);
        new_tree(level + 1, NULL, root_b->child[2]);
        new_tree(level + 1, NULL, root_b->child[3]);
    }
}

int main(void)
{
    int num_case;
    cin >> num_case;
    cin.get();
    string line[2];
    while (num_case--) {
        getline(cin, line[0]);
        Node* root[2];
        root[0] = build_tree_inorder(line[0].data(), line[0].size());
#ifndef ONLINE_JUDGE
        display_tree_inorder(root[0]);
        cout << endl;
        display_tree_levelorder(root[0]);
        cout << endl;
#endif
        getline(cin, line[1]);
        root[1] = build_tree_inorder(line[1].data(), line[1].size());
#ifndef ONLINE_JUDGE
        display_tree_inorder(root[1]);
        cout << endl;
        display_tree_levelorder(root[1]);
        cout << endl;
#endif
        sum = 0;
        new_tree(0, root[0], root[1]);
        destroy_tree(root[0]);
        destroy_tree(root[1]);
        cout << "There are " << sum << " black pixels." << endl;
    }
    return 0;
}

