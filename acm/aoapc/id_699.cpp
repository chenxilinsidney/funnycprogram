/**
 * @file id_699.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>

#define LEAVES_HALF_WIDTH 85
int left_array[LEAVES_HALF_WIDTH] = {0};
int right_array[LEAVES_HALF_WIDTH] = {0};

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
    if (root == NULL) return;
    Node* temp = root;
    stack<Node*> s;
    while (temp || !s.empty()) {
        if (temp) {
            // push left child for node temp
            s.push(temp);
            temp = temp->lchild;
        } else {
            // get top node
            temp = s.top();
            s.pop();
            cout << temp->key << " ";
            // check right child next time
            temp = temp->rchild;
        }
    }
}

void destroy_tree(Node* root)
{
    if (root == NULL) return;
    Node* temp;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->lchild != NULL)
            q.push(temp->lchild);
        if (temp->rchild != NULL)
            q.push(temp->rchild);
        delete temp;
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
    int num_case = 0;
    while (1) {
        // build tree
        Node* root = build_tree_inorder();
        // get leaves value
        memset(left_array, 0, sizeof(int) * LEAVES_HALF_WIDTH);
        memset(right_array, 0, sizeof(int) * LEAVES_HALF_WIDTH);
        int left_max_index = 0;
        int right_max_index = 0;
        traversal_tree_path(root, 0, left_array, right_array,
                &left_max_index, &right_max_index);
        if (root == NULL) break;
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
        cout << endl;
#endif
        // destroy tree
        destroy_tree(root);
    }
    return 0;
}
