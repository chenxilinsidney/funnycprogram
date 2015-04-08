/**
 * @file id_548.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <cassert>

using namespace std;

typedef struct Node {
    int key;
    struct Node* lchild;
    struct Node* rchild;
} Node;

Node* build_treeinpost(const int* inorder,
        int inorder_start_index,
        int inorder_end_index,
        int num_node,
        const int* postorder,
        int postorder_start_index,
        int postorder_end_index)
{
    assert(postorder_end_index - postorder_start_index ==
            inorder_end_index - inorder_start_index);
    if (num_node == 0)
        return NULL;
    Node* temp = new Node;
    temp->lchild = NULL;
    temp->rchild = NULL;
    int inorder_index = inorder_start_index;
    while (inorder_index <= inorder_end_index &&
            inorder[inorder_index] != postorder[postorder_end_index]) {
        inorder_index++;
    }
    temp->key = postorder[postorder_end_index];
#ifndef ONLINE_JUDGE
    cout << "key:" << temp->key << endl;
    cout << "index:" << inorder_index << endl;
#endif
    //left child
    temp->lchild = build_treeinpost(inorder,
            inorder_start_index, inorder_index - 1,
            inorder_index - inorder_start_index,
            postorder,
            postorder_start_index,
            inorder_index - 1 - inorder_start_index + postorder_start_index);
    //right child
    temp->rchild = build_treeinpost(inorder,
            inorder_index + 1, inorder_end_index,
            inorder_end_index - inorder_index,
            postorder,
            inorder_index - inorder_start_index + postorder_start_index,
            postorder_end_index - 1);
    return temp;
}

void destroy_tree(Node* root)
{
    if (root != NULL) {
        Node* p_temp = root;
        destroy_tree(root->lchild);
        destroy_tree(root->rchild);
        delete p_temp;
    }
}

void traversal_tree_path(Node* root, int sum_path,
        int* least_path, int* leaf_key)
{
    if (root == NULL) return;
    sum_path += root->key;
    if (root->lchild == NULL && root->rchild == NULL) {
        if (*least_path > sum_path) {
            *least_path = sum_path;
            *leaf_key = root->key;
        } else if (*least_path == sum_path && *leaf_key > root->key) {
            *leaf_key = root->key;
        }
        return;
    }
    traversal_tree_path(root->lchild, sum_path, least_path, leaf_key);
    traversal_tree_path(root->rchild, sum_path, least_path, leaf_key);
}

int inorder[10005];
int postorder[10005];

int main(void)
{
    string line_inorder;
    string line_postorder;
    while (getline(cin, line_inorder) && getline(cin, line_postorder)) {
#ifndef ONLINE_JUDGE
        cout << "target:" << line_inorder << endl;
        cout << "target:" << line_postorder << endl;
#endif
        // get inorder array
        int number = 0;
        bool flag = true;
        for (size_t index = 0; index < line_inorder.size(); index++) {
            if (flag && isdigit(line_inorder[index])) {
                sscanf(line_inorder.data() + index, "%d", inorder + number++);
                flag = false;
            }
            if (!isdigit(line_inorder[index])) {
                flag = true;
            }
        }
        // get postorder array
        number = 0;
        flag = true;
        for (size_t index = 0; index < line_postorder.size(); index++) {
            if (flag && isdigit(line_postorder[index])) {
                sscanf(line_postorder.data() + index, "%d",
                        postorder + number++);
                flag = false;
            }
            if (!isdigit(line_postorder[index])) {
                flag = true;
            }
        }
#ifndef ONLINE_JUDGE
        cout << "number:" << number << endl;
#endif
        Node* root;
        root = build_treeinpost(inorder, 0, number - 1, number,
                postorder, 0, number - 1);
#ifndef ONLINE_JUDGE
        cout << "root:" << root->key << endl;
#endif
        int least_path = numeric_limits<int>::max();
        int leaf_key = 0;
        traversal_tree_path(root, 0, &least_path, &leaf_key);
        cout << leaf_key << endl;
        destroy_tree(root);
    }
}

