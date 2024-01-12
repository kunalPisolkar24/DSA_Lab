/*
Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key)  */

#include <iostream>
#include <list>
#include <string>
#define SIZE 10

using namespace std;

class HashTable {
private:
    list<pair<string, string>>* table;
    int getHash(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % SIZE;
    }
public:
    HashTable() {
        table = new list<pair<string, string>>[SIZE];
    }
    void insert(string key, string value) {
        int index = getHash(key);
        table[index].push_back(make_pair(key, value));
    }
    string search(string key) {
        int index = getHash(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return "";
    }
    void remove(string key) {
        int index = getHash(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == key) {
                table[index].erase(it);
                break;
            }
        }
    }
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Index: " << i << endl;
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                cout << "Key: " << it->first << ", Value: " << it->second << endl;
            }
        }
    }
};


int main() {
    HashTable ht;
    string key, value;
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Remove\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                if(ht.search(key) != "") {
                    cout << "Value already Present" << endl;
                }else {
                    ht.insert(key, value);
                }
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                value = ht.search(key);
                if (value.empty()) {
                    cout << "Key not found\n";
                } else {
                    cout << "Value: " << value << endl;
                }
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                ht.remove(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}


/*
---------------------------------------------------------------------------------------------------
Output
---------------------------------------------------------------------------------------------------

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 1

Enter key: word   
Enter value: a_element_of_speech

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 1

Enter key: hello
Enter value: used_for_greeting

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 1

Enter key: car  
Enter value: a_four_wheeled_vehical

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 4

Index: 0
Key: car, Value: a_four_wheeled_vehical
Index: 1
Index: 2
Key: hello, Value: used_for_greeting
Index: 3
Index: 4
Key: word, Value: a_element_of_speech
Index: 5
Index: 6
Index: 7
Index: 8
Index: 9

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 2

Enter key: car
Value: a_four_wheeled_vehical

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 3

Enter key: car

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 2

Enter key: car
Key not found

Menu:
1. Insert
2. Search
3. Remove
4. Display
5. Exit

Enter your choice: 5

Exiting...

*/