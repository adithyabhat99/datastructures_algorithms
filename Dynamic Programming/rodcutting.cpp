#include <iostream>
using namespace std;
void rod(int p[], int r[], int s[], int n)
{
	r[0] = 0;
	for (int j = 1; j <= n; j++)
	{
		int q = -9999;
		for (int i = 1; i < j; i++)
		{
			if (q < p[i] + r[j - i])
			{
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		if(q<p[j]){
			q=p[j];
			s[j]=j;
		}
		r[j] = q;
	}
}
int main()
{
	int n;
	cout << "Enter rod length\n";
	cin >> n;
	int p[n + 1], i;
	cout << "Enter profit array\n";
	for (i = 1; i <= n; i++)
		cin >> p[i];
	int r[n + 1];
	int s[n + 1];
	rod(p, r, s, n);
	cout<<"Maximum profit possible is "<<r[n]<<endl<<"Solution is ";
	while (n >= 0 && s[n]>0)
	{
		cout << s[n] << " ";
		n -= s[n];
	}
	cout << endl;
	return 0;
}

/*
//GeeksforGeeks
#include<stdio.h> 
#include<limits.h> 

int max(int a, int b) { return (a > b)? a : b;} 

int cutRod(int price[], int n) 
{ 
int val[n+1]; 
val[0] = 0; 
int i, j; 
 
for (i = 1; i<=n; i++) 
{ 
	int max_val = INT_MIN; 
	for (j = 0; j < i; j++) 
		max_val = max(max_val, price[j] + val[i-j-1]); 
	val[i] = max_val; 
} 

return val[n]; 
} 

int main() 
{ 
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	printf("Maximum Obtainable Value is %dn", cutRod(arr, size)); 
	getchar(); 
	return 0; 
} 
*/