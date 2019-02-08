#include<iostream>
using namespace std;
int partition(int a[],int l,int h){
    int key=a[l];
    int i=l+1;
    int j=h;
    while(i<=j){
        while(a[i]<=key && i<=h)
            i++;
        while(a[j]>key)
            j--;
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}
void quicksort(int a[],int l,int h){
    int mid;
    if(l<h){
        mid=partition(a,l,h);
        quicksort(a,l,mid-1);
        quicksort(a,mid+1,h);
    }
}
int main(){
    int n,i;
    cout<<"Enter number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    cout<<"After sorting array is \n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
