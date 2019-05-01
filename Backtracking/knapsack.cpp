/*
0-1 knapsack using backtracking
*/

#include <iostream>
using namespace std;
int *P, *W, c, bestP, cp, cw;
int bound(int i, int n)
{
    int cleft = c - cw;
    int b = cp;
    while (i <= n && W[i] <= cleft)
    {
        cleft -= W[i];
        b += P[i];
        i++;
    }
    if (i <= n)
    {
        b += P[i] / (W[i] * cleft);
    }
    return b;
}
void knap(int i, int n)
{
    if (i > n - 1)
    {
        bestP = cp;
        return;
    }
    if (cw + W[i] <= c)
    {
        cw += W[i];
        cp += P[i];
        knap(i + 1, n);
        cw -= W[i];
        cp -= P[i];
    }
    if (bound(i + 1, n) > bestP)
    {
        knap(i + 1, n);
    }
}
int main()
{
    int n;
    cout << "Enter number of items\n";
    cin >> n;
    P = new int[n];
    W = new int[n];
    cout << "Enter weight array,then profit array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    cout << "Enter knapsack capacity\n";
    cin >> c;
    knap(0, n);
    cout << "Maximum profit is " << bestP << endl;
    return 0;
}