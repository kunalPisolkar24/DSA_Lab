/* 
Construct an expression tree from the given prefix expression eg. +--a*bc/def and
traverse it using postordertraversal(non recursive) and then delete the entire tree. 
*/

#include "bits/stdc++.h"
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode *left, *right;
};

class ExpTree {
    public:
    TreeNode *top;
    void getExpression(string);
    void iterativePostOrder(TreeNode*);
    void postOrder(TreeNode*);
    void remove(TreeNode*);
};

void ExpTree::getExpression(string prefix) {
    stack<TreeNode*> stk;
    TreeNode *t1, *t2;
    int len = prefix.size(), i;

    for(i = len - 1; i >= 0; i--) {
        top = new TreeNode;
        top->left = top->right = nullptr;

        if(isalpha(prefix[i])) {
            top->data = prefix[i];
            stk.push(top);
        }else if(prefix[i] == '+' or prefix[i] == '*' or prefix[i] == '-' or prefix[i] == '/') {
            t2 = stk.top();
            stk.pop();

            t1 = stk.top();
            stk.pop();

            top->data = prefix[i];
            top->left = t2;
            top->right = t1;
            stk.push(top);
        }
    }
    top = stk.top();
    stk.pop();
}

void ExpTree::postOrder(TreeNode *root) {
    if(root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data;
    }
}

void ExpTree::iterativePostOrder(TreeNode *root) {
    if (root == nullptr) return;

    stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* prev = nullptr;

    while (!stk.empty()) {
        TreeNode* curr = stk.top();
        if (!prev || prev->left == curr || prev->right == curr) {
            if (curr->left) {
                stk.push(curr->left);
            } else if (curr->right) {
                stk.push(curr->right);
            } else {
                cout << curr->data;
                stk.pop();
            }
        } else if (curr->left == prev) {
            if (curr->right) {
                stk.push(curr->right);
            } else {
                cout << curr->data;
                stk.pop();
            }
        } else if (curr->right == prev) {
            cout << curr->data;
            stk.pop();
        }
        prev = curr;
    }
}


void ExpTree::remove(TreeNode *node)  {
    if(!node) return;
    remove(node->left);
    remove(node->right);
    cout << "Removing node: " << node->data << endl;
    delete node;
}

int main() {

    ExpTree t;
    string expr;
    int ch = 0;
    do {
        cout << "Choose Options" << endl;
        cout << "1. Input Expression " << endl;
        cout << "2. Iterative & Recursive PostOrder " << endl;
        cout << "3. Remove Nodes " << endl;
        cout << "4. Exit" << endl;

        cin >> ch;

        switch(ch) {
            case 1: 
            [&](){
                cout << "Enter the prefix expression : ";
                cin >> expr;
                t.getExpression(expr);
            }();
            break;
            case 2: 
            [&](){
                cout << "Iterative Post Order" << endl;
                t.iterativePostOrder(t.top);
                cout << endl;
                cout << "Recursive Post Order" << endl;
                t.postOrder(t.top);
                cout << endl;
            }();
            break;
            case 3: 
            [&](){
                cout << " Removing Elements " << endl;
                t.remove(t.top);
            }();
            break;
        }
    }while(ch != 4);
}




/*
--------------------------------------------------------------------------------
OUTPUT
---------------------------------------------------------------------------------

Choose Options
1. Input Expression 
2. Iterative & Recursive PostOrder 
3. Remove Nodes 
4. Exit

1

Enter the prefix expression : +--a*bc/def

Choose Options
1. Input Expression 
2. Iterative & Recursive PostOrder 
3. Remove Nodes 
4. Exit

2

Iterative Post Order
abc*-de/-f+
Recursive Post Order
abc*-de/-f+

Choose Options
1. Input Expression 
2. Iterative & Recursive PostOrder 
3. Remove Nodes 
4. Exit

3

Removing Elements 
Removing node: a
Removing node: b
Removing node: c
Removing node: *
Removing node: -
Removing node: d
Removing node: e
Removing node: /
Removing node: -
Removing node: f
Removing node: +

Choose Options
1. Input Expression 
2. Iterative & Recursive PostOrder 
3. Remove Nodes 
4. Exit

4

*/