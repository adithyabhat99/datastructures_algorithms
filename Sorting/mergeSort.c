#include<stdio.h>
void merge(int a[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L1[n1],L2[n2];
	for(i=0;i<n1;i++)
		L1[i]=a[l+i];
	for(i=0;i<n2;i++)
		L2[i]=a[m+1+i];
	i=j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L1[i]<=L2[j])
		{
			a[k]=L1[i];
			i++;
		}
		else
		{
			a[k]=L2[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=L2[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void printa(int a[],int n)
{
	int i;
	printf("Elements are\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void main()
{
	int a[]={5,4,3,2,1,0};
	int n=6;
	printa(a,n);
	printf("\n");
	mergesort(a,0,n-1);
	printf("Sorted array is \n");
	printa(a,n);
	printf("\n");
}

/*
#include<iostream>
using namespace std;
void merge(int *a,int l,int mid,int h){
    int temp[h-l+1];
    int i,j,k;
    i=l;
    j=mid+1;
    k=0;
    while(i<=mid && j<=h){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=h)
        temp[k++]=a[j++];
    for(i=l;i<=h;i++)
        a[i]=temp[i-l];
}
void mergesort(int *a,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main(){
    int n,i;
    cout<<"Enter number of elements\n";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n-1);
    cout<<"Array after sorting\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
*/