#include<iostream>
using namespace std;
int search(int *a,int i,int n,int k){
    if(i==n) return -1;
    if(a[i]==k) return i;
    return search(a,i+1,n,k);
}
int main(){
    int n,i,*a;
    cin>>n;
    a=new int [n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    cout<<search(a,0,n,k)<<"\n";
    return 0;
}