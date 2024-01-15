
/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular student. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data.
*/

#include "bits/stdc++.h"
using namespace std;

class Students {
    string path = "students.txt";
public:
    void insert(int id, string name, string rollno, string address) {
        fstream file(path, ios::in | ios::app);
        file << id << "|" << name << "|" << rollno << "|" << address << endl;
        file.close();
    }

    void modifyLine(int lineNo, string &res) {
        fstream file(path, ios::out | ios::in);
        vector<string> overwrite;
        string line;

        int i = 1;

        while(getline(file, line)) {
            if(i == lineNo) overwrite.push_back(res);
            else overwrite.push_back(line);
            i++;
        }
        file.close();

        fstream file1(path, ios::out);
        for(auto &x: overwrite){
            file1 << x << endl;
        }
        file1.close();
    }
void remove(int id) {
    fstream file(path, ios::in);
    string line;
    int i = 1;
    while(getline(file, line)) {
        string temp;
        stringstream ss(line);
        getline(ss, temp, '|');

        if(temp.empty() || !isNumeric(temp)) {
            i++;
            continue;
        }

        int cid = stoi(temp);

        if(cid == id) {
            string res = "-1";
            getline(ss, temp, '|');
            res += "|" + temp;

            getline(ss, temp, '|');
            res += "|" + temp;

            getline(ss, temp, '|');
            res += "|" + temp;

            modifyLine(i, res);
        }
        i++;
    }
}


void display(int id) {
    fstream file(path, ios::in);
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string temp;
        getline(ss,temp, '|');

        if(isNumeric(temp)) {
            int cid = stoi(temp);

            if(cid == id and cid != -1) {
                cout << "Student Id -> " << id << endl;

                getline(ss, temp, '|');
                cout << "Student Name -> " << temp << endl;

                getline(ss, temp, '|');
                cout << "Student Class -> " << temp << endl;

                getline(ss, temp, '|');
                cout << "Student City -> " << temp << endl;
                return;
            }
        }
    }
    cout << " Data Not found " << endl;
    file.close();
}
bool isNumeric(const string &str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

};

int main() {
    Students st;
    int ch;
    do {
        cout << "1.Insert Record: " << endl;
        cout << "2.Remove Record: " << endl;
        cout << "3.Display Record: " << endl;
        cout << "4.Exit" << endl;
        cin >> ch;

        switch(ch) {
            case 1: {
                string name, clss, city;
                int id;
                cout << "Enter id, name, class, city all seprated by space: ";
                cin >> id >>  name >> clss >> city;
                st.insert(id, name, clss, city);
                break;
            }
            case 2: {
                cout << "Enter id of record to be removed: ";
                int id;
                cin >> id;
                st.remove(id);
                break;
            }
            case 3: {
                cout << "Enter the id to display record: ";
                int id;
                cin >> id;
                st.display(id);
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

Enter id, name, class, city all seprated by space: 1 Patrick SE(A) Norway

1.Insert Record:
2.Remove Record:
3.Display Record:
4.Exit

1

Enter id, name, class, city all seprated by space: 81 Mathew SE(B) Montana

1.Insert Record:
2.Remove Record:
3.Display Record:
4.Exit

2

Enter id of record to be removed: 1

1.Insert Record:
2.Remove Record:
3.Display Record:
4.Exit

3

Enter the id to display record: 81

Student Id -> 81
Student Name -> Mathew
Student Class -> SE(B)
Student City -> Montana

1.Insert Record:
2.Remove Record:
3.Display Record:
4.Exit

3

Enter the id to display record: 1
 Data Not found

1.Insert Record:
2.Remove Record:
3.Display Record:
4.Exit

4
Exiting...



*/

