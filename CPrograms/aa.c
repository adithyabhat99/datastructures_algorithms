#include <stdio.h>
#include <stdlib.h>
 
// A heap has current size and array of elements
struct MaxHeap
{
    int size;
    int* array;
};
 
// A utility function to swap to integers
void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }
 
// The main function to heapify a Max Heap. The function
// assumes that everything under given root (element at
// index idx) is already heapified
void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
   int lar=idx;    
   int l=2*idx+1;
   int r=2*idx+2;
   if(l<maxHeap->size&&maxHeap->array[lar]<maxHeap->array[l])
   lar=l;
   if(r<maxHeap->size&&maxHeap->array[lar]<maxHeap->array[r])
   lar=r;
   if(lar!=idx)
     {
         swap(&(maxHeap->array[idx]),&(maxHeap->array[lar]));
         maxHeapify(maxHeap,lar);
     }
    
}
 
// A utility function to create a max heap of given capacity
struct MaxHeap* createAndBuildHeap(int *array, int size)
{
    /*----------Fill your code here--------------*/
    struct MaxHeap *tmp;
    tmp=(struct MaxHeap*)malloc(sizeof(struct MaxHeap));
   // array=(int *)malloc(sizeof(int)*size);
    tmp->size=size;
    tmp->array=array;
    return tmp;
}
 
// The main function to sort an array of given size
void heapSort(int* array, int size)
{
   int i;
   struct MaxHeap *p=createAndBuildHeap(array,size); 
   for(i=size/2-1; i>=0; i--)
   maxHeapify(p,i);
   for(i=size-1; i>=1; i--)
    {
        swap(&array[0],&array[i]);
        p->size--;
        maxHeapify(p,0);
    }
    
}
 
// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
/* Driver program to test above functions */
int main()
{
    int *arr,i;
    // = {12, 11, 13, 5, 6, 7};
    int size;
    printf("Enter the size of the array\n");
	scanf("%d",&size);
	arr = (int*)malloc(sizeof(int)*size);
    printf("Enter the array elements\n");
    //printArray(arr, size);
    for(i=0;i<size;i++){
		scanf("%d",arr+i);
	}
 
    heapSort(arr, size);
 
    printf("Sorted array is\n");
    printArray(arr, size);
    printf("\n");
    return 0;
}
