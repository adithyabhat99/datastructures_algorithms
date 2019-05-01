#include <iostream>
using namespace std;
int a[] = {1, 2, 3, 4};
void perm(int n, int k)
{
    if (k == n - 1)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = k; i < n; i++)
    {
        swap(a[k], a[i]);
        perm(n, k + 1);
        swap(a[k], a[i]);
    }
}
int main()
{
    perm(4, 0);
    return 0;
}