#include<iostream>
using namespace std;
int bin(int *a,int l,int h,int k){
    if(l<h){
        int mid=(l+h)/2;
        if(a[mid]==k) return mid;
        if(a[mid]<k) return bin(a,mid+1,h,k);
        else return bin(a,l,mid-1,k);
    }
    return -1;
}
int main(){
    int n,i,*a;
    cin>>n;
    a=new int [n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    cout<<bin(a,0,n-1,k)<<"\n";
    return 0;
}