#include <stdio.h>
void heapify(int a[], int n, int i)
{
	int largest, l, r, x;
	largest = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		x = a[i];
		a[i] = a[largest];
		a[largest] = x;
		heapify(a, n, largest);
	}
}
void heeapSort(int a[], int n)
{
	int i, x;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (i = n - 1; i >= 0; i--)
	{
		x = a[0];
		a[0] = a[i];
		a[i] = x;
		heapify(a, i, 0);
	}
}
void display(int a[], int n)
{
	int i;
	printf("Elements are\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}
void main()
{
	int a[] = {6, 5, 4, 3, 2, 1}, n = 6;
	display(a, n);
	printf("\n");
	printf("After sorting\n");
	heeapSort(a, n);
	display(a, n);
	printf("\n");
}
