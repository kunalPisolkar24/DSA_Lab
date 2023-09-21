/*
Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each
key ki . Build the Binary search tree that has the least search cost given the access
probability for each key? 

*/

#include "bits/stdc++.h"
using namespace std;

float a[20], b[20], c[20][20], wt[20][20];
int r[20][20], n;

void construct()
{
    int i, j, l;
    for (i = 0; i < n; i++)
    {
        c[i][i] = 0.0;
        r[i][i] = 0;
        wt[i][i] = b[i];

        wt[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        c[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        r[i][i + 1] = i + 1;
    }

    c[0][n] = 0.0;
    r[0][n] = 0;
    wt[0][n] = b[n];

    for (i = 2; i <= n; i++)
    {
        for (j = 0; j <= n - i; j++)
        {
            wt[j][j + i] = b[j + i] + a[j + i] + wt[j][j + i - 1];
            c[j][j + i] = 9999;
            for (l = j + 1; l <= j + i; l++)
            {
                if (c[j][j + i] > (c[j][l - 1] + c[l][j + i]))
                {
                    c[j][j + i] = c[j][l - 1] + c[l][j + i];
                    r[j][j + i] = l;
                }
            }
            c[j][j + i] += wt[j][j + i];
        }
    }
    cout << "--- OPTIMAL BST IS --- " << endl;
    cout << "\nw[0][" << n << "] :: " << wt[0][n];
    cout << "\nc[0][" << n << "] :: " << c[0][n];
    cout << "\nr[0][" << n << "] :: " << r[0][n] << endl;
}

void print(int l1, int r1)
{
    if (l1 >= r1)
        return;

    if (r[l1][r[l1][r1] - 1] != 0)
        cout << "left child of " << r[l1][r1] << " is " << r[l1][r[l1][r1] - 1] << endl;

    if (r[r[l1][r1]][r1] != 0)
        cout << "right child of " << r[l1][r1] << " is " << r[r[l1][r1]][r1] << endl;

    print(l1, r[l1][r1] - 1);
    print(r[l1][r1], r1);
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cout << "Enter the nodes ";
    cin >> n;
    cout << "Enter the probablities ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Enter the probablities for unsuccessful search :";
    for (int i = 0; i <= n; i++)
        cin >> b[i];

    construct();
    print(0, n);
    return 0;
}

/*
----------------------------------------------------------------------------------------------
OUTPUT
----------------------------------------------------------------------------------------------

Enter the nodes: 5
Enter the probablities
0.15
0.10
0.05
0.10
0.20

Enter the probablities for unsuccessful search :
0.05
0.10
0.05
0.05
0.05
0.10

--- OPTIMAL BST IS --- 
w[0][5] :: 1
c[0][5] :: 2.35
r[0][5] :: 4
left child of 4 is 2
right child of 4 is 5
left child of 2 is 1
right child of 2 is 3

*/