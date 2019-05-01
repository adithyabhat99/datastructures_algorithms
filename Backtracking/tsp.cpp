/*
Given a set of cities and distance between every pair of cities,
the problem is to find the shortest possible route that visits every city exactly once 
and returns back to the starting point

Its similar to hamiltonian cycle prblem(hamiltonian cycle prblem is NP Hard)
*/

#include <iostream>
using namespace std;
int **a, *x, *best;
int cc, bestc = 999;
void tsp(int i, int n)
{
    if (i == n)
    {
        if (a[x[n - 1]][x[n]] != 999 && a[x[n]][1] != 999 && cc + a[x[n - 1]][x[n]] + a[x[n]][1] < bestc || bestc == 999)
        {
            for (int j = 1; j <= n; j++)
            {
                best[j] = x[j];
            }
            bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][1];
        }
        return;
    }
    for (int j = i; j <= n; j++)
    {
        if (a[x[i - 1]][x[j]] != 999 && cc + a[x[i - 1]][x[j]] < bestc || bestc == 999)
        {
            swap(x[i], x[j]);
            cc += a[x[i - 1]][x[j]];
            tsp(i + 1, n);
            cc -= a[x[i - 1]][x[j]];
            swap(x[i], x[j]);
        }
    }
}
int main()
{
    int n, i, j;
    cout << "Enter number of cities\n";
    cin >> n;
    cout << "Enter adjacancy matrix,999 for no edge\n";
    a = new int *[n + 1];
    x = new int[n + 1];
    best = new int[n + 1];
    for (i = 0; i <= n; i++)
    {
        a[i] = new int[n + 1];
        x[i] = i;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    tsp(2, n);
    cout << "Best cost is " << bestc << endl;
    cout << "Best path is\n";
    for (i = 1; i <= n; i++)
        cout << best[i] << " ";
    cout << best[1];
    cout << endl;
    return 0;
}