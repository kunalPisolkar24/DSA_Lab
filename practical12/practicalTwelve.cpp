/*
Company maintains employee information as employee ID, name, designation and salary. 
Allow user to add, delete information of employee. Display information of particular 
employee. If employee does not exist an appropriate message is displayed. If it is, then 
the system displays the employee details. Use index sequential file to maintain the data.
*/

#include "bits/stdc++.h"
using namespace std;

class Employee {
    string data = "employee.txt";
    string index = "index.txt";
    int line = 0;
    public:
    void insert(int id, string name, string des, string salary) {
        fstream file(data, ios::app);
        line++;
        file << id << "|" << name << "|" << des << "|" << salary << endl; 
        file.close();

        fstream file1(index, ios::app);
        file1 << id << "|" << line << endl;
        file1.close();
    }

    void modifyLine(int offset, string res) {
        fstream file(index, ios::in);
        vector<string> overwrite;
        string line;

        int i = 1;
        while(getline(file, line)) {
            if(i == offset) overwrite.push_back(res);
            else overwrite.push_back(line);
            i++;
        }
        file.close();
        
        fstream file1(index, ios::out);
        for(auto &x: overwrite) 
            file1 << x << endl;
        file1.close();
    }

    void remove(int id) {
        fstream file(index, ios::in);
        string line;
        int offset = 0;
        while(getline(file, line)) {
            stringstream ss(line);
            string temp;
            getline(ss, temp, '|') ;
            
            int cid = stoi(temp);
            if(cid == id) {
                 
                getline(ss, temp, '|');
                offset = stoi(temp);
                string res = "-1|-1";
                modifyLine(offset, res);
                cout << "Successful Remove " << endl;
                file.close();
                return;
            } 
        }
        cout << "Remove Failed" << endl;
    }

    void display(int id) {
        fstream file(index, ios::in);
        string line;
        int offset = -1;
        while(getline(file, line)) {
            stringstream ss(line);
            string temp;
            getline(ss, temp, '|') ;
            
            int cid = stoi(temp);
            if(cid == id) {
                 
                getline(ss, temp, '|');
                offset = stoi(temp);
                break;
            } 
        }   

        if(offset == -1) {
            cout << "No data found" << endl;
            return;
        }

        fstream file1(data, ios::in);
        int i = 1;
        while(getline(file1, line)) {
            stringstream ss(line);
            string temp;
            if(i == offset) {
                getline(ss, temp, '|');
                cout << "Emp id -> " << temp << endl;

                getline(ss, temp, '|');
                cout << "Emp Name -> " << temp << endl;

                getline(ss, temp, '|');
                cout << "Emp Designation -> " << temp << endl;

                getline(ss, temp, '|');
                cout << "Emp Salary -> " << temp << endl;
            }
            i++;
        }
        file.close();
        file1.close();
    }
};

int main() {
    Employee e;
    int ch;
    do {
        cout << "1.Insert Record: " << endl;
        cout << "2.Remove Record: " << endl;
        cout << "3.Display Record: " << endl;
        cout << "4.Exit" << endl;
        cin >> ch;

        switch(ch) {
            case 1: {
                string name, clss, sal;
                int id;
                cout << "Enter id, name, designation, salary all seprated by space: ";
                cin >> id >>  name >> clss >> sal;
                e.insert(id, name, clss, sal);
                break;
            }
            case 2: {
                cout << "Enter id of record to be removed: ";
                int id;
                cin >> id;
                e.remove(id);
                break;
            }
            case 3: {
                cout << "Enter the id to display record: ";
                int id;
                cin >> id;
                e.display(id);
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                break;
            }
        }
    }while(ch != 4);
    return 0;
}

/*
--------------------------------------------------------------------------------
OUTPUT
---------------------------------------------------------------------------------

1.Insert Record: 
2.Remove Record: 
3.Display Record: 
4.Exit

1

Enter id, name, designation, salary all seprated by space: 1 Victor Slave 3000

1.Insert Record: 
2.Remove Record: 
3.Display Record: 
4.Exit

2

Enter id of record to be removed: 1

Successful Remove 
1.Insert Record: 
2.Remove Record: 
3.Display Record: 
4.Exit

3

Enter the id to display record: 1

No data found
1.Insert Record: 
2.Remove Record: 
3.Display Record: 
4.Exit

1

Enter id, name, designation, salary all seprated by space: 2 Gon Dinosaur 999
1.Insert Record: 
2.Remove Record: 
3.Display Record: 
4.Exit

3

Enter the id to display record: 2

Emp id -> 2
Emp Name -> Gon
Emp Designation -> Dinosaur
Emp Salary -> 999

1.Insert Record: 
2.Remove Record: 
3.Display Record: 
4.Exit

4

Exiting...

*/