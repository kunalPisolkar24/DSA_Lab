/*
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
deleting keywords, updating values of any entry. Provide facility to display whole data 
sorted in ascending/ Descending order. Also find how many maximum comparisons may 
require for finding any keyword. Use Height balance tree and find the complexity for 
finding a keyword 
*/

#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    string keyword, val;
    int height;
    Node *left, *right;
    Node(string key,string val, Node *left, Node *right)
    {
        this->keyword = key;
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int height(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    x->right = T2;
    y->left = x;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return x;
}

int getBalance(Node *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

Node *insert(Node *root, string data, string val)
{
    Node *temp = new Node(data,val, NULL, NULL);
    if (!root)
        root = temp;
    else if (data < root->keyword)
        root->left = insert(root->left, data, val);
    else if (data > root->keyword)
        root->right = insert(root->right, data, val);
    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 and data < root->left->keyword)
        return rotateRight(root);

    if (balance < -1 and data > root->right->keyword)
        return rotateLeft(root);

    if (balance > 1 and data > root->left->keyword)
    {
        root->left = rotateRight(root->left);
        return rotateLeft(root);
    }

    if (balance < -1 and data < root->right->keyword)
    {
        root->right = rotateLeft(root->right);
        return rotateRight(root);
    }
    return root;
}

pair<Node*, int> search(Node* root, string key) {
    if (root == nullptr || root->keyword == key)
        return make_pair(root, 1);

    if (root->keyword < key) {
        pair<Node*, int> result = search(root->right, key);
        return make_pair(result.first, result.second + 1);
    }

    pair<Node*, int> result = search(root->left, key);
    return make_pair(result.first, result.second + 1);
}

void searchAndPrint(Node* root, string key) {
    pair<Node*, int> result = search(root, key);
    cout << "Number of comparisons: " << result.second << endl;
    if (result.first == nullptr) {
        cout << "Key not found" << endl;
    } else {
        cout << "Key: " << result.first->keyword << ", Value: " << result.first->val << endl;
    }
}



void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->keyword << " => " << root->val << endl;
        inOrder(root->right);
    }
}

Node * minValueNode(Node *root)
{
    Node *p = root;
    while (p->right)
        p = p->right;
    return p;
}

Node* remove(Node* root, string data) {
    if (root == nullptr)
        return root;

    if (data < root->keyword)
        root->left = remove(root->left, data);
    else if (data > root->keyword)
        root->right = remove(root->right, data);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
                delete temp;
            }
        } else {
            Node* temp = minValueNode(root->right);
            root->keyword = temp->keyword;
            root->right = remove(root->right, temp->keyword);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void update(Node* root, string key, string newVal) {
    Node* result = search(root, key).first;
    if (result == nullptr) {
        cout << "Key not found" << endl;
    } else {
        result->val = newVal;
        cout << "Updation successful" << endl;
    }
}



int main() {
    Node *root = nullptr;
    int choice;
    string key, value;

    do {
        cout << "Choose an operation:\n";
        cout << "1. Insert\n";
        cout << "2. Update\n";
        cout << "3. Remove\n";
        cout << "4. Search\n";
        cout << "5. Display\n";
        cout << "6. Min Element\n";
        cout << "7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key and value for insertion: ";
                cin >> key >> value;
                root = insert(root, key, value);
                cout << "Insertion successful\n";
                break;
            case 2:
                cout << "Enter the key and new value for update: ";
                cin >> key >> value;
                update(root, key, value);
                break;
            case 3:
                cout << "Enter the key to be removed: ";
                cin >> key;
                root = remove(root, key);
                cout << "Removal successful\n";
                break;
            case 4:
                cout << "Enter the key to search: ";
                cin >> key;
                searchAndPrint(root, key);
                break;
            case 5:
                cout << "Displaying Elements: " << endl;
                inOrder(root);
                break;
            case 6:{

                cout << "Printing Minimum element: " << endl;
                Node *temp = minValueNode(root);
                cout << temp->keyword << " => " << temp->val << endl;
                break;
            }
            case 7:
                cout << "Exiting the program\n";
                break;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 7.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}

/*

--------------------------------------------------------------------------------
OUTPUT
---------------------------------------------------------------------------------

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

1

Enter the key and value for insertion: a b

Insertion successful

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

1

Enter the key and value for insertion: b c

Insertion successful

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

1

Enter the key and value for insertion: c d

Insertion successful

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit
5

Displaying Elements: 
a => b
b => c
c => d

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

2

Enter the key and new value for update: c e

Updation successful

Choose an operation:

1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

5

Displaying Elements: 
a => b
b => c
c => e

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

3

Enter the key to be removed: c
Removal successful

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

5

Displaying Elements: 
a => b
b => c

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

6

Printing Minimum element: 
b => c

Choose an operation:
1. Insert
2. Update
3. Remove
4. Search
5. Display
6. Min Element
7. Exit

7

Exiting the program

*/