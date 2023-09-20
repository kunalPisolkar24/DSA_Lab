/*
A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method. 
*/

#include "bits/stdc++.h"
using namespace std;

struct Node
{
    string label;
    int n;
    struct Node *child[10];
} *root;

class GT
{
public:
    GT() {
        root = NULL;
    }
    void createTree()
    {
        root = new Node;
        cout << "Enter the name of the book :";
        getline(cin, root->label);

        cout << "Enter the number of chapters :";
        cin >> root->n;
        cin.ignore();

        for(int i = 0; i < root->n; i++) {
            root->child[i] = new Node;
            cout << "Enter the name of chapter " << i + 1 << " : ";
            getline(cin, root->child[i]->label);

            cout << "Enter the number of sections :";
            cin >> root->child[i]->n;
            cin.ignore();

            for(int j = 0; j < root->child[i]->n; j++)  {
                root->child[i]->child[j] = new Node;
                cout << " Enter the name of section " << j + 1 << " : ";
                getline(cin, root->child[i]->child[j]->label);

                cout << "Enter the number of subsections: ";
                cin >> root->child[i]->child[j]->n;
                cin.ignore();

                for(int k = 0; k < root->child[i]->child[j]->n; k++) {
                    root->child[i]->child[j]->child[k] = new Node;
                    cout << "Enter the name of the subsection " << k + 1 << ":";
                    getline(cin,root->child[i]->child[j]->child[k]->label);
                }
            }
        }
    }


    void display(struct Node*root) {
        if(root) {
            cout << "BOOK Name -> " << root->label << endl;
            for(int i = 0; i < root->n; i++) {
                cout << "\tChapter -> " << root->child[i]->label << endl;

                for(int j = 0; j < root->child[i]->n; j++) {
                    cout << "\t\t Section -> " << root->child[i]->child[j]->label << endl;

                    for(int k = 0; k < root->child[i]->child[j]->n;k++) {
                        cout << "\t\t\tSub-section -> " << root->child[i]->child[j]->child[k]->label << endl;
                    }
                }
            }
        }
    }
};

int main()
{
    int choice;
    GT gt;
    while (1)
    {
        cout << "---------------------" << endl;
        cout << " BOOK TREE CREATION " << endl;
        cout << "----------------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            gt.createTree();
            break;
        case 2:
            gt.display(root);
            break;
        case 3:
            cout << " Thanks for using this program !";
            exit(1);
        default:
            cout << "Wrong Choice !!! " << endl;
        }
    }
    return 0;
}

/*
----------------------------------------------------------------------------
Output
----------------------------------------------------------------------------

---------------------
 BOOK TREE CREATION 
----------------------
1.Create
2.Display
3.Quit
Enter your choice: 1
Enter the name of the book :DSA_BOOK2
Enter the number of chapters :2
Enter the name of chapter 1 : HASHING
Enter the number of sections : 2
Enter the name of section 1 : HASHTABLE
Enter the number of subsections: 3
Enter the name of the subsection 1: CONCEPTS_OF_HASH_TABLE
Enter the name of the subsection 2: HASH_FUNCTIONS
Enter the name of the subsection 3: TYPES_OF_HASHING
Enter the name of section 2 : SKIPLIST
Enter the number of subsections: 2
Enter the name of the subsection 1: REPRESENTATION
Enter the name of the subsection 2: OPERATIONS_ON_SKIP_LIST
Enter the name of chapter 2 : TREES
Enter the number of sections : 2
Enter the name of section 1 : TREE_BASIC_CONCEPTS
Enter the number of subsections: 2
Enter the name of the subsection 1:TREE_REPRESENTATION
Enter the name of the subsection 2: BINARY_TREE
Enter the name of section 2 : THREADED_BINARY_TREE
Enter the number of subsections: 2
Enter the name of the subsection 1: TRAVERSAL_OF_TBT
Enter the name of the subsection 2: OPERATIONS_ON_TBT
---------------------
 BOOK TREE CREATION 
----------------------
1.Create
2.Display
3.Quit
Enter your choice: 2
 BOOK Name -> DSA_BOOK
        Chapter -> HASHING
                 Section -> HASHTABLE
                        Sub-section -> CONCEPTS_OF_HASH_TABLE
                        Sub-section -> HASH_FUNCTIONS
                        Sub-section -> TYPES_OF_HASHING
                 Section -> SKIPLIST
                        Sub-section -> REPRESENTATION
                        Sub-section -> OPERATIONS_ON_SKIP_LIST
        Chapter -> TREES
                 Section -> TREE_BASIC_CONCEPTS
                        Sub-section -> TREE_REPRESENTATION
                        Sub-section -> BINARY_TREE
                 Section -> THREADED_BINARY_TREE
                        Sub-section -> TRAVERSAL_OF_TBT
                        Sub-section -> OPERATIONS_ON_TBT
---------------------
 BOOK TREE CREATION 
----------------------
1.Create
2.Display
3.Quit
Enter your choice: 3

Thanks for using this program !
*/