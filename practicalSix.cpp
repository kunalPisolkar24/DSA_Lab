/*
There are flight paths between cities. If there is a flight between city A and city B then 
there is an edge between the cities. The cost of the edge can be the time that flight take 
to reach city B from A, or the amount of fuel used for the journey. Represent this as a 
graph. The node can be represented by airport name or name of the city. Use adjacency 
list representation of the graph or use adjacency matrix representation of the graph. 
Check whether the graph is connected or not. Justify the storage representation used. 
*/

#include "bits/stdc++.h"
using namespace std;


int mat[50][50] = {0, 0};
int vis[50] = {0};

void dfs(int s, int n, string arr[]) {
    vis[s] = 1;
    cout << arr[s] << " ";
    for(int i = 0; i < n; i++) {
        if(mat[s][i] and !vis[i]) 
            dfs(i, n, arr);
    }
}

void bfs(int s, int n, string arr[]) {
    bool vis[n] = {false};
    queue<int> q;
    if(!vis[s]) {
        cout << arr[s] << " ";
        q.push(s);
        vis[s] = true;

        while(!q.empty()) {
            int v = q.front();
            for(int i = 0; i < n; i++) {
                if(mat[v][i] and !vis[i]) {
                    cout << arr[i] << " ";
                    vis[i] = true;
                    q.push(i);
                }
            }
            q.pop();
        }
    }
}

int main() {
    cout << "Enter no. of cities: ";
    int u, v, n;
    cin >> n;
    string cities[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }

    cout << "\n Your cities are: " << endl;
    for(int i = 0; i < n; i++)
        cout << "city #" << i << " : " << cities[i] << endl;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> mat[i][j];
            mat[j][i] = mat[i][j];
        }
    }
    cout << endl;

    cout << setw(15) << " ";
    for(int i = 0; i < n; i++)
        cout << setw(15) << cities[i];
    cout << "\n";

    for(int i = 0; i < n; i++) {
        cout << setw(15) << cities[i];
        for(int j = 0; j < n; j++) 
            cout << setw(15) << mat[i][j];
        cout << "\n";
    }

    cout << "Enter Starting vertex: ";
    cin >> u;

    cout << "DFS: ";
    dfs(u, n, cities);
    cout << endl;

    cout << "BFS: ";
    bfs(u, n, cities);
    cout << endl;

    return 0;
}


/*

--------------------------------------------------------------------------------
OUTPUT
---------------------------------------------------------------------------------

Enter no. of cities: 4
Enter city #0 (Airport Code): Pune
Enter city #1 (Airport Code): Delhi
Enter city #2 (Airport Code): Bangalore
Enter city #3 (Airport Code): Mumbai

 Your cities are: 
city #0 : Pune
city #1 : Delhi
city #2 : Bangalore
city #3 : Mumbai

Enter distance between Pune and Delhi : 3
Enter distance between Pune and Bangalore : 4
Enter distance between Pune and Mumbai : 6
Enter distance between Delhi and Bangalore : 1
Enter distance between Delhi and Mumbai : 19
Enter distance between Bangalore and Mumbai : 9

                          Pune          Delhi      Bangalore         Mumbai
           Pune              0              3              4              6
          Delhi              3              0              1             19
      Bangalore              4              1              0              9
         Mumbai              6             19              9              0

Enter Starting vertex: 0

DFS: Pune Delhi Bangalore Mumbai 
BFS: Pune Delhi Bangalore Mumbai 

*/



































