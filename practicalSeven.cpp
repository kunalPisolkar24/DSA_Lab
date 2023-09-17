/* 

You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices with
a minimum total cost. Solve the problem by suggesting appropriate data structures. 

*/

#include "bits/stdc++.h"
using namespace std;

int V = 7, e = 0;
int u{0}, v{0}, w{0};

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
#define vec(a) vector<a>

void displayAdjMatrix(vec(pii) graph[])
{
    vec(vi) adjacencyMatrix(V, vector<int>(V, 0));

    for (int i = 0; i < V; ++i)
    {
        for (const auto &neighbor : graph[i])
        {
            int j = neighbor.first;
            int weight = neighbor.second;
            adjacencyMatrix[i][j] = weight;
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << i << " |";
        for (int j = 0; j < V; ++j)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

vec(tiii) prims(vec(pii) graph[], int start)
{
    vi key(V, INT_MAX);
    vi parent(V, -1);
    vec(bool) inMST(V, false);

    key[start] = 0;
    priority_queue<pii, vec(pii), greater<pii>> pq;
    pq.push({0, start});

    vec(tiii) res;
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        if (parent[v] != -1 and inMST[v] == false)
            res.push_back({parent[v], v, key[v]});

        inMST[v] = true;
        for (auto i : graph[v])
        {
            int av = i.first;
            int w = i.second;

            if (inMST[av] == false and key[av] > w)
            {
                parent[av] = v;
                key[av] = w;
                pq.push({key[av], av});
            }
        }
    }
    return res;
}

void addEdge(vec(pii) graph[], int u, int v, int w)
{
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main()
{

    vec(pii) graph[V];
    vec(tiii) res;
    char choice = 'n';
    int input = 0;
    do
    {
        cout << "1. Input" << endl;
        cout << "2. Display Adj Matrix" << endl;
        cout << "3. Calculate MST" << endl;
        cout << "4. Quit" << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            [&]()
            {
                cout << "Enter the number of Branches : ";
                cin >> V;

                cout << endl;

                cout << "Enter the number of connections: ";
                cin >> e;

                while (e--)
                {

                    cout << "Enter the vertices: ";
                    cin >> u >> v;

                    cout << "Enter their weight: ";
                    cin >> w;

                    addEdge(graph, u, v, w);
                }
            }();
            break;
        case 2:
            displayAdjMatrix(graph);
            break;
        case 3:
            int sum{0};
            res = prims(graph, 0);
            cout << "Minimum-Spanning-Tree" << endl;
            
            for (int i = 0; i < res.size(); i++){
                sum += get<2>(res[i]);
                cout << get<0>(res[i]) << " is connected to " << get<1>(res[i]) << " , at weight " << get<2>(res[i]) << endl;
            }
            cout << endl;
            cout << "Total cost of minimum spanning Tree: " << sum << endl;
            break;
        case 4:
            cout << "Area you sure you want to quit: ";
            cin >> choice;
            break;
        default:
            cout << "Invalid Input" << endl;
        };
    } while (choice != 'y');

    return 0;
}

/*

------------------------------------------------------------------
Output
------------------------------------------------------------------
1. Input
2. Display Adj Matrix
3. Calculate MST
4. Quit

1

Enter the number of Branches : 7

Enter the number of connections: 12
Enter the vertices: 0 1
Enter their weight: 2
Enter the vertices: 0 3
Enter their weight: 7
Enter the vertices: 0 5
Enter their weight: 2
Enter the vertices: 1 2
Enter their weight: 1
Enter the vertices: 1 3
Enter their weight: 4
Enter the vertices: 1 4
Enter their weight: 3
Enter the vertices: 1 5
Enter their weight: 5
Enter the vertices: 2 4
Enter their weight: 4
Enter the vertices: 2 5
Enter their weight: 4
Enter the vertices: 3 4
Enter their weight: 1
Enter the vertices: 3 6 
Enter their weight: 5
Enter the vertices: 4 6
Enter their weight: 7

1. Input
2. Display Adj Matrix
3. Calculate MST
4. Quit

2

Adjacency Matrix:
0 |0 2 0 7 0 2 0 
1 |2 0 1 4 3 5 0 
2 |0 1 0 0 4 4 0 
3 |7 4 0 0 1 0 5 
4 |0 3 4 1 0 0 7 
5 |2 5 4 0 0 0 0 
6 |0 0 0 5 7 0 0 

1. Input
2. Display Adj Matrix
3. Calculate MST
4. Quit

3

Minimum-Spanning-Tree
0 is connected to 1 , at weight 2
1 is connected to 2 , at weight 1
0 is connected to 5 , at weight 2
1 is connected to 4 , at weight 3
4 is connected to 3 , at weight 1
3 is connected to 6 , at weight 5

Total cost of minimum spanning Tree: 14

1. Input
2. Display Adj Matrix
3. Calculate MST
4. Quit

4

Area you sure you want to quit: y

*/