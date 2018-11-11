//Credits:GeeksForGeeks.com
#include<stdio.h>
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  	int temp;
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
    	temp=arr[i];
    	arr[i]=arr[largest];
    	arr[largest]=temp;
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
	int temp;
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
void main()
{
	int a[10],i,n;
	printf("Enter size and elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	heapSort(a,n);
	printf("Sorted array ussing selection sort is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}