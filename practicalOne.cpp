/*
Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers
*/

#include "bits/stdc++.h"
using namespace std;
#define SIZE 10

class HashTable
{
private:
    vector<pair<string, string>> table;
    int getHash(string key)
    {
        hash<string> hasher;
        return hasher(key) % SIZE;
    }

public:
    HashTable()
    {
        table.resize(SIZE);
    }

    void insertLinear(string key, string value)
    {
        int index = getHash(key);
        while (!table[index].first.empty())
        {
            index = (index + 1) % SIZE;
        }
        table[index] = make_pair(key, value);
    }

    void insertQuadratic(string key, string value)
    {
        int index = getHash(key);
        int i = 0;
        while (!table[index].first.empty())
        {
            i++;
            index = (index + i * i) % SIZE;
        }
        table[index] = make_pair(key, value);
    }

    pair<string, int> searchLinear(string key)
    {
        int index = getHash(key);
        int comparisons = 0;
        while (table[index].first != key && !table[index].first.empty())
        {
            index = (index + 1) % SIZE;
            comparisons++;
        }
        return make_pair(table[index].second, comparisons);
    }

    pair<string, int> searchQuadratic(string key)
    {
        int index = getHash(key);
        int i = 0;
        int comparisons = 0;
        while (table[index].first != key && !table[index].first.empty())
        {
            i++;
            index = (index + i * i) % SIZE;
            comparisons++;
        }
        return make_pair(table[index].second, comparisons);
    }

    void remove(string key)
    {
        int index = getHash(key);
        while (table[index].first != key && !table[index].first.empty())
        {
            index = (index + 1) % SIZE;
        }
        table[index].first = "";
        table[index].second = "";
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (!table[i].first.empty())
            {
                cout << "Index: " << i << ", Key: " << table[i].first << ", Value: " << table[i].second << endl;
            }
        }
    }
};

int main()
{
    HashTable ht;

    int type = 0, ch = 0;
    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Remove" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int n = 0;
            cout << "Choose any of the following \n 1. Linear Probing \n 2. Quadratic Probing" << endl;
            cin >> type;
            cout << "Enter the number of elements : ";
            cin >> n;

            if (n > SIZE)
            {
                cout << "Overflow" << endl;
                break;
            }

            while (n--)
            {
                cout << "Enter key and value: ";
                string key, val;
                cin >> key >> val;
                if (type == 1)
                {
                    ht.insertLinear(key, val);
                }
                else if (type == 2)
                {
                    ht.insertQuadratic(key, val);
                }
                else
                    cout << "Wrong input" << endl;
            }
            break;
        }

        case 2:
        {
            if (type == 1)
            {
                string key;
                cout << "Enter an Element to be searched (Linear): ";
                cin >> key;
                cout << "Searching..." << endl;
                if (ht.searchLinear(key).first == "")
                {
                    cout << "Value: NA" << endl;
                    cout << "No of Comparisions: " << ht.searchLinear(key).second << endl;
                }
                else
                {
                    cout << "Value: " << ht.searchLinear(key).first << endl;
                    cout << "No of Comparisions: " << ht.searchLinear(key).second << endl;
                }
            }
            else if (type == 2)
            {
                string key;
                cout << "Enter an Element to be searched (Quadratic): ";
                cin >> key;
                cout << "Searching..." << endl;
                if (ht.searchQuadratic(key).first == "")
                {
                    cout << "Value: NA" << endl;
                    cout << "No of Comparisions: " << ht.searchQuadratic(key).second << endl;
                }
                else
                {
                    cout << "Value: " << ht.searchQuadratic(key).first << endl;
                    cout << "No of Comparisions: " << ht.searchQuadratic(key).second << endl;
                }
            }
            else
            {
                cout << "Invalid Type" << endl;
            }

            break;
        }
        case 3:
            ht.display();
            break;
        case 4:
        {
            string el;
            cout << "Enter element to be removed: ";
            cin >> el;
            ht.remove(el);
            break;
        }
        }

    } while (ch != 5);

    return 0;
}

/*
---------------------------------------------------------------------------------------------------
Output
---------------------------------------------------------------------------------------------------

1. Insert
2. Search
3. Display
4. Remove
5. Exit

1

Choose any of the following 
 1. Linear Probing 
 2. Quadratic Probing

1

Enter the number of elements : 6
Enter key and value: Joshua 339-191-391 
Enter key and value: Jose 398-191-198
Enter key and value: Homer 938-938-398 
Enter key and value: Tommy 999-181-598 
Enter key and value: Trevor 983-193-118
Enter key and value: James 410-198-398 

1. Insert
2. Search
3. Display
4. Remove
5. Exit

3

Index: 0, Key: Trevor, Value: 983-193-118
Index: 1, Key: Tommy, Value: 999-181-598
Index: 2, Key: Joshua, Value: 339-191-391
Index: 5, Key: Jose, Value: 398-191-198
Index: 6, Key: Homer, Value: 938-938-398
Index: 9, Key: James, Value: 410-198-398

1. Insert
2. Search
3. Display
4. Remove
5. Exit

2

Enter an Element to be searched (Linear): James
Searching...
Value: 410-198-398
No of Comparisions: 0
1. Insert
2. Search
3. Display
4. Remove
5. Exit


Enter an Element to be searched (Linear): Lama
Searching...
Value: NA
No of Comparisions: 2
1. Insert
2. Search
3. Display
4. Remove
5. Exit

4

Enter element to be removed: Joshua
1. Insert
2. Search
3. Display
4. Remove
5. Exit

3

Index: 0, Key: Trevor, Value: 983-193-118
Index: 1, Key: Tommy, Value: 999-181-598
Index: 5, Key: Jose, Value: 398-191-198
Index: 6, Key: Homer, Value: 938-938-398
Index: 9, Key: James, Value: 410-198-398

1. Insert
2. Search
3. Display
4. Remove
5. Exit

5

*/