/**
 * @file id_839.cpp
 * @brief UVAOJ
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-04-08
 */

#include <iostream>
#include <string>
#include <queue>
#include <stack>

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

void display_tree_preorder_by_recursive(Node* root)
{
    if (root != NULL) {
        cout << root->lweight << " ";
        cout << root->ldistance << " ";
        cout << root->rweight << " ";
        cout << root->rdistance << " ";
        cout << "@ ";
        display_tree_preorder_by_recursive(root->lchild);
        display_tree_preorder_by_recursive(root->rchild);
    }
}

void display_tree_preorder(Node* root)
{
    if (root == NULL) return;
    Node* temp;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        temp = s.top();
        s.pop();
        cout << temp->lweight << " ";
        cout << temp->ldistance << " ";
        cout << temp->rweight << " ";
        cout << temp->rdistance << " ";
        cout << "@ ";
        if (temp->rchild != NULL)
            s.push(temp->rchild);
        if (temp->lchild != NULL)
            s.push(temp->lchild);
    }
}

void display_tree_inorder_by_recursive(Node* root)
{
    if (root != NULL) {
        display_tree_inorder_by_recursive(root->lchild);
        cout << root->lweight << " ";
        cout << root->ldistance << " ";
        cout << root->rweight << " ";
        cout << root->rdistance << " ";
        cout << "@ ";
        display_tree_inorder_by_recursive(root->rchild);
    }
}

void display_tree_inorder(Node* root)
{
    if (root == NULL) return;
    Node* temp = root;
    stack<Node*> s;
    while (temp || !s.empty()) {
        if (temp) {
            s.push(temp);
            temp = temp->lchild;
        } else {
            temp = s.top();
            s.pop();
            cout << temp->lweight << " ";
            cout << temp->ldistance << " ";
            cout << temp->rweight << " ";
            cout << temp->rdistance << " ";
            cout << "@ ";
            temp = temp->rchild;
        }
    }
}

void display_tree_postorder_by_recursive(Node* root)
{
    if (root != NULL) {
        display_tree_postorder_by_recursive(root->lchild);
        display_tree_postorder_by_recursive(root->rchild);
        cout << root->lweight << " ";
        cout << root->ldistance << " ";
        cout << root->rweight << " ";
        cout << root->rdistance << " ";
        cout << "@ ";
    } else {
        cout << "# ";
    }
}

void display_tree_postorder(Node* root)
{
    if (root == NULL) return;
    Node* temp;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        if (temp->rchild != NULL) {
            s.push(temp->rchild);
        if (temp->lchild != NULL)
            s.push(temp->lchild);
        temp = s.top();
        if (temp->lchild == NULL && temp->rchild == NULL) {
            s.pop();
            cout << temp->lweight << " ";
            cout << temp->ldistance << " ";
            cout << temp->rweight << " ";
            cout << temp->rdistance << " ";
            cout << "@ ";
        }
    }
}

void destroy_tree_by_recursive(Node* root)
{
    if (root != NULL) {
        destroy_tree_by_recursive(root->lchild);
        destroy_tree_by_recursive(root->rchild);
        delete root;
    }
}

void destroy_tree_by_queue(Node* root)
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

bool traversal_tree_path(Node* root)
{
    if (root == NULL) return false;
    if (root->lweight * root->ldistance != root->rweight * root->rdistance)
        return true;
    bool left, right;
    if (root->lchild != NULL)
        left = traversal_tree_path(root->lchild);
    else
        left = false;
    if (root->lchild != NULL)
        right = traversal_tree_path(root->rchild);
    else
        right = false;
    return left || right;
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
        display_tree_inorder_by_recursive(root);
        cout << endl;
        display_tree_inorder(root);
        cout << endl;
        display_tree_preorder_by_recursive(root);
        cout << endl;
        display_tree_preorder(root);
        cout << endl;
        display_tree_postorder_by_recursive(root);
        cout << endl;
        display_tree_postorder(root);
        cout << endl;
#endif
        // destroy tree
        destroy_tree_by_queue(root);
    }
    return 0;
}
