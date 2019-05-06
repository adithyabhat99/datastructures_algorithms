#include<iostream>
using namespace std;
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int partition(int *a,int l,int h){
    int i=l;
    int key=a[l];
    int j=h;
    while(i<=j){
        while(i<=h && a[i]<=key){
            i++;
        }
        while(a[j]>key){
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    swap(a[j],a[l]);
    return j;
}
void quicksort(int *a,int l,int h){
    if(l<h){
        int mid=partition(a,l,h);
        quicksort(a,l,mid-1);
        quicksort(a,mid+1,h);
    }
}
int main(){
 int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    print(a,n);
    return 0;
}