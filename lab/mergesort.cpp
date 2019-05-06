#include<iostream>
using namespace std;
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void merge(int *a,int l,int h,int mid){
    int temp[h-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else
            temp[k++]=a[j++];
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=h){
        temp[k++]=a[j++];
    }
    for(i=l;i<=h;i++){
        a[i]=temp[i-l];
    }
}
void mergesort(int *a,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,h,mid);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n-1);
    print(a,n);
    return 0;
}