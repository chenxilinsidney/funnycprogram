/**
 * @file id_10562.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char professor_tree[205][205];

typedef struct Node {
    char key;
    struct Node* lchild;
    struct Node* rchild;
} Node;

void destroy_tree(Node* root)
{
    if (root != NULL) {
        destroy_tree(root->lchild);
        destroy_tree(root->rchild);
        delete root;
    }
}

void display_tree_inorder(Node* root)
{
    if (root != NULL) {
        cout << root->key; 
        display_tree_inorder(root->lchild);
        display_tree_inorder(root->rchild);
    } else {
        cout << "#";
    }
}

void display_tree(Node* root)
{
    if (root != NULL) {
        cout << root->key; 
        if (root->lchild == NULL) {
            cout << "()";
        } else {
            cout << "(";
            display_tree(root->lchild);
            cout << ")";
        }
        display_tree(root->rchild);
    }
}

Node* build_tree(int level, int index_begin, int index_end)
{
#ifdef ONLINE_JUDGE
    cout << "level: " << level << endl;
    cout << "level: " << index_begin << endl;
    cout << "level: " << index_end << endl;
#endif
    Node* temp = new Node;
    bool flag_getchar = true;
    int char_index_left = -1;
    int char_index_right = -1;
    int index_right = 0;
    int index_child = 0;
    int count = 0;
    for (index_right = index_begin; index_right <= index_end; index_right++) {
#ifdef ONLINE_JUDGE
        cout << "get:" << professor_tree[level][index_right] << endl;
#endif
        if (flag_getchar && professor_tree[level][index_right] != ' ') {
            flag_getchar = false;
            if (count == 0) {
                sscanf(professor_tree[level] + index_right, "%s", &(temp->key));
                if (professor_tree[level + 1][index_right] == '|') {
#ifdef ONLINE_JUDGE
                    cout << "key:" << temp->key << endl;
                    cout << "get |" << endl;
#endif
                    int index_begin = index_right;
                    int index_end = index_right;
                    while (professor_tree[level + 2][index_begin] == '-')
                        index_begin--;
                    while (professor_tree[level + 2][index_end] == '-')
                        index_end++;
                    char_index_left = index_begin + 1;
                    char_index_right = index_end - 1;
                }
            }
            count++;
            if (count >= 2)
                break;
        }
        if (professor_tree[level][index_right] == ' ')
            flag_getchar = true;
    }
#ifdef ONLINE_JUDGE
    cout << "get left: " << char_index_left << endl;
    cout << "get right: " << char_index_right << endl;
    cout << "temp: " << temp->key << endl;
    cout << "count: " << count << endl;
#endif
    if (char_index_left != -1 && char_index_right != -1)
        temp->lchild = build_tree(level + 3,
                char_index_left, char_index_right);
    else
        temp->lchild = NULL;
    if (count == 2)
        temp->rchild = build_tree(level, index_right, index_end);
    else
        temp->rchild = NULL;
    return temp;
}

int main(void)
{
    int num_case;
    cin >> num_case;
    cin.get();
    while (num_case--) {
        int line_count = 0;
        while (gets(professor_tree[line_count]) &&
                professor_tree[line_count][0] != '#')
            line_count++;
        memset(professor_tree[line_count], 0,
                strlen(professor_tree[line_count - 1]));
#ifdef ONLINE_JUDGE
        cout << "line number: " << line_count << endl;
        for (int i = 0; i < line_count; i++)
            cout << professor_tree[i] << endl;
#endif
        Node* root = build_tree(0, 0, strlen(professor_tree[0]));
        cout << "(";
        display_tree(root);
        cout << ")";
        cout << endl;
        destroy_tree(root);
    }
    return 0;
}

