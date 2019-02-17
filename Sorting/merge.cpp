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