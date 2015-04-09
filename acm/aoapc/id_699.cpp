/**
 * @file id_699.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    int key;
    struct Node* lchild;
    struct Node* rchild;
}Node;

Node* build_tree_inorder()
{
    int key;
    cin >> key;
    if (key == -1)
        return NULL;
    Node* temp = new Node;
    temp->key = key;
    temp->lchild = build_tree_inorder();
    temp->rchild = build_tree_inorder();
    return temp;
}

void display_tree_inorder(Node* root)
{
    if (root != NULL) {
        cout << root->key << " ";
        display_tree_inorder(root->lchild);
        display_tree_inorder(root->rchild);
    } else {
        cout << "# ";
    }
}

void destroy_tree(Node* root)
{
    if (root != NULL) {
        destroy_tree(root->lchild);
        destroy_tree(root->rchild);
        delete root;
    }
}

void traversal_tree_path(Node* root, int leaves_index,
        int* left_array,
        int* right_array,
        int* left_max_index,
        int* right_max_index)
{
    if (root == NULL) return;
    if (leaves_index >= 0) {
        right_array[leaves_index] += root->key;
        *right_max_index =
            *right_max_index < leaves_index ? leaves_index : *right_max_index;
    } else {
        int positive = leaves_index * -1;
        left_array[positive] += root->key;
        *left_max_index =
            *left_max_index < positive ? positive : *left_max_index;
    }
    traversal_tree_path(root->lchild, leaves_index - 1,
            left_array, right_array,
            left_max_index, right_max_index);
    traversal_tree_path(root->rchild, leaves_index + 1,
            left_array, right_array,
            left_max_index, right_max_index);
}

int main(void)
{
    int first;
    int num_case = 0;
    while (cin >> first && first != -1) {
        // unget the first value
        cin.unget();
        // build tree
        Node* root = build_tree_inorder();
        // get leaves value
#define LEAVES_HALF_WIDTH 80
        int left_array[LEAVES_HALF_WIDTH] = {0};
        int right_array[LEAVES_HALF_WIDTH] = {0};
        int left_max_index = 0;
        int right_max_index = 0;
        traversal_tree_path(root, 0, left_array, right_array,
                &left_max_index, &right_max_index);
        // print result
        num_case++;
        cout << "Case " << num_case << ":" << endl;
        for (int index = left_max_index; index >= 1; index--)
            cout << left_array[index] << " ";
        for (int index = 0; index < right_max_index; index++)
            cout << right_array[index] << " ";
        cout << right_array[right_max_index] << endl;
        cout << endl;
#ifndef ONLINE_JUDGE
        cout << "left_max_index:" << left_max_index << endl;
        cout << "right_max_index:" << right_max_index << endl;
        display_tree_inorder(root);
#endif
        // destroy tree
        destroy_tree(root);
    }
    return 0;
}
