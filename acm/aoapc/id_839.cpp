/**
 * @file id_839.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    int lweight;
    int rweight;
    int ldistance;
    int rdistance;
    struct Node* lchild;
    struct Node* rchild;
}Node;

Node* build_tree_inorder()
{
    Node* temp = new Node;
    cin >> temp->lweight >> temp->ldistance
        >> temp->rweight >> temp->rdistance;
    if (temp->lweight == 0) {
        temp->lchild = build_tree_inorder();
        temp->lweight = (temp->lchild)->lweight + (temp->lchild)->rweight;
    } else {
        temp->lchild = NULL;
    }
    if (temp->rweight == 0) {
        temp->rchild = build_tree_inorder();
        temp->rweight = (temp->rchild)->lweight + (temp->rchild)->rweight;
    } else {
        temp->rchild = NULL;
    }
    return temp;
}

void display_tree_inorder(Node* root)
{
    if (root != NULL) {
        cout << root->lweight << " ";
        cout << root->ldistance << " ";
        cout << root->rweight << " ";
        cout << root->rdistance << " ";
        cout << "@ ";
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

bool traversal_tree_path(Node* root)
{
    if (root == NULL) return false;
    if (root->lchild != NULL && root->rchild != NULL) {
        if (root->lweight * root->ldistance != root->rweight * root->rdistance)
            return true;
        else {
            return traversal_tree_path(root->lchild) ||
                traversal_tree_path(root->rchild);
        }
    }
    return false;
}

int main(void)
{
    int num_case;
    cin >> num_case;
    cin.get();
    while (num_case--) {
        // ignore previous blank line
        cin.get();
        // build tree and generate weight
        Node* root = build_tree_inorder();
        // result
        bool result = traversal_tree_path(root);
        // print result
        if (!result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        if (num_case)
            cout << endl;
#ifndef ONLINE_JUDGE
        display_tree_inorder(root);
        cout << endl;
#endif
        // destroy tree
        destroy_tree(root);
    }
    return 0;
}
