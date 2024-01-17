/*
Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell 
data structure with modularity of programming language
*/

#include "bits/stdc++.h"
using namespace std;
class Heap
{
public:
    int a[100];
    int size = 0;

    Heap()
    {
        a[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int idx = size;
        a[idx] = val;

        while(idx > 1) {
            int p = idx / 2;
            if(a[p] < a[idx]) {
                swap(a[idx], a[p]);
                idx = p;
            }else return;
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << a[i] << endl;
        }
        cout << endl;
    }

    void remove() {
        if(size == 0) {
            cout << " Failed " << endl;
            return;
        }
        a[1] = a[size];
        size--;

        int i = 1;
        while(i < size) {
            int l = 2 * i;
            int r = 2 * i + 1;

            if(l < size and a[i] < a[l]) {
                swap(a[i], a[l]);
                i = l;
            }else if(r < size and a[i] < a[r]) {
                swap(a[i], a[r]);
                i = r;
            }else return;
        }
    }

};



void heapify(int a[], int n, int loc) {
    int i = loc;
    int l = 2 * i + 1;  // left child index
    int r = 2 * i + 2;  // right child index

    if(l < n and a[i] < a[l]) 
        i = l;
    if(r < n and a[i] < a[r])
        i = r;
    if(i != loc) {
        swap(a[i], a[loc]);
        heapify(a, n, i);
    }
}

void heapSort(int a[], int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(a[0], a[i]);

        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}


void minHeap(int a[], int n, int loc) {
    int i = loc;
    int l = 2 * i;
    int r = 2 * i + 1;

    if(l <= n and a[i] > a[l]) 
        i = l;
    if(r <= n and a[i] > a[r]) 
        i = r;
    
    if(i != loc) {
        swap(a[i], a[loc]);
        minHeap(a, n, i);
    }
}


int main()
{
    Heap h;
    int ch;
    do {
        cout << "Choose a option \n";
        cout << "1.Insert\n";
        cout << "2.Remove(Pop)\n";
        cout << "3.Print\n";
        cout << "4.Heap Sort\n";
        cout << "5.Exit.\n";
        cin >> ch;

        switch(ch) {
            case 1:{
                cout << "Insert an Element: ";
                int x = 0;
                cin >> x;
                h.insert(x);
                break;
            }
            case 2:{
                cout << "Performing Pop Operation..";
                h.remove();
                break;
            }
            case 3:{
                cout << "Printing elements\n";
                h.print();
                break;
            }
            case 4:{
                cout << "Array Size: ";
                int n;
                cin >> n;
                int a[n];
                cout << "Enter El's (space seprated): ";
                for(int i = 0; i < n; i++) cin >> a[i];
                for (int i = n / 2; i > 0; i--)
                    heapify(a, n, i);

                heapSort(a, n);
                for (int i = 0; i < n; i++) cout << a[i] << " ";
                cout << endl;
                break;
            }
            case 5: {
                cout << "Exiting...";
                break;
            }
            default: {
                cout << "Enter valid input\n";
            } 
        }
    }while(ch != 5);
    return 0;
}

/*
--------------------------------------------------------------------------------
OUTPUT
---------------------------------------------------------------------------------
Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

1

Insert an Element: 50 

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

1

Insert an Element: 55

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

1

Insert an Element: 53

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

1

Insert an Element: 52

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

1

Insert an Element: 54

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

3

Printing elements
55
54
53
50
52

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

2

Performing Pop Operation..Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

3

Printing elements
54
52
53
50

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

4

Array Size: 5
Enter El's (space seprated): 50 55 53 52 54
50 52 53 54 55 

Choose a option 
1.Insert
2.Remove(Pop)
3.Print
4.Heap Sort
5.Exit.

5
Exiting...

*/