/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Minimum data value found in the tree
iii. Search a value 
iv. Display all the nodes.
v. Find number of nodes in longest path from root
vi. Change a tree so that the roles of the left and right pointers are swapped at every node 
*/

#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    Node *insert(Node *root, int x)
    {
        Node *temp = new Node(x, NULL, NULL);
        if (!root)
        {
            root = temp;
        }
        else if (root->data > x)
            root->left = insert(root->left, x);
        else if (root->data < x)
            root->right = insert(root->right, x);
        return root;
    }

    void search(Node *root, int x)
    {
        if (root)
        {
            if (root->data == x)
            {
                cout << "Entry found :) " << endl;
                return;
            }
            else if (x < root->data)
                search(root->left, x);
            else if (x > root->data)
                search(root->right, x);
            else
                return;
        }
    }

    void min(Node *root)
    {
        Node *p = root;
        while (p->left)
            p = p->left;
        cout << p->data << endl;
    }

    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node *root)
    {
        if (root)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    int height(Node *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }

    void swapChildren(Node *root) {
        if (root != NULL) {
            swap(root->left, root->right);
            swapChildren(root->left);
            swapChildren(root->right);
        }
    }

};

int main()
{
    BST tree;
    int ch = 5;
    do
    {
        cout << "Choose Operation: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Traversal" << endl;
        cout << "3. Search" << endl;
        cout << "4. Min" << endl;
        cout << "5. Longest Path from root" << endl;
        cout << "6. Swap nodes" << endl;
        cout << "7. Exit " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            [&]()
            {
                int n;
                cout << "Enter the number of Elements you want to insert: ";
                cin >> n;

                for (int i = 0; i < n; i++)
                {
                    int ip;
                    cin >> ip;
                    tree.root = tree.insert(tree.root, ip);
                }
                cout << "Insertion Complete ... " << endl
                     << endl;
            }();
            break;
        case 2:
            [&]()
            {
                cout << "Traversals ..." << endl;

                cout << "PreOrder" << endl;
                tree.preorder(tree.root);
                cout << endl;

                cout << "InOrder" << endl;
                tree.inorder(tree.root);
                cout << endl;

                cout << "PostOrder" << endl;
                tree.postorder(tree.root);
                cout << endl;
            }();
            break;
        case 3:
            [&]() {
                int ip;
                cout << "Enter element to search : ";
                cin >> ip;
                tree.search(tree.root, ip);

            }();
            break;
        case 4:
            [&]() {
                cout << "Min Element : ";
                tree.min(tree.root);
            }();
            break;
        case 5:
            [&]() {
                cout << "Longest path : ";
                cout << tree.height(tree.root) << endl;
            }();
            break;
        case 6:
            [&]() {
                cout << "Swap nodes: ";
                tree.swapChildren(tree.root);
                tree.preorder(tree.root);
            }();
            break;
        }

    } while (ch != 7);

    return 0;
}

/*
---------------------------------------------------------------------------------------------------
Output
---------------------------------------------------------------------------------------------------
Choose Operation: 
1. Insert
2. Traversal
3. Search
4. Min
5. Longest Path from root
6. Swap nodes
7. Exit 

1

Enter the number of Elements you want to insert: 3
10 9 15

Insertion Complete ... 

Choose Operation: 
1. Insert
2. Traversal
3. Search
4. Min
5. Longest Path from root
6. Swap nodes
7. Exit 

2

Traversals ...
PreOrder
10 9 15 
InOrder
9 10 15 
PostOrder
9 15 10 

Choose Operation: 
1. Insert
2. Traversal
3. Search
4. Min
5. Longest Path from root
6. Swap nodes
7. Exit 

3

Enter element to search : 15
Entry found :) 
Choose Operation: 
1. Insert
2. Traversal
3. Search
4. Min
5. Longest Path from root
6. Swap nodes
7. Exit 

4

Min Element : 9

Choose Operation: 
1. Insert
2. Traversal
3. Search
4. Min
5. Longest Path from root
6. Swap nodes
7. Exit 

5

Longest path : 2
Choose Operation: 
1. Insert
2. Traversal
3. Search
4. Min
5. Longest Path from root
6. Swap nodes
7. Exit 

6

Swap nodes: 10 15 9 Choose Operation: 
1. Insert
2. Traversal
3. Search
4. Min
5. Longest Path from root
6. Swap nodes
7. Exit 

7

*/