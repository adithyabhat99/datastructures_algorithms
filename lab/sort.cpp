#include<iostream>
using namespace std;
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void sort(int *a,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
void sort1(int *a,int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(a[i],a[min]);
    }
}
void sort2(int *a,int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int p=a[i];
        while(j>=0 && a[j]>p){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=p;
    }
}
void sort3(int *a,int n){
    int rank[n],c[n],i,j;
    for(i=0;i<n;i++)
        rank[i]=0;
    for(i=1;i<n;i++){
        for(j=i-1;j>=0;j--){
            if(a[i]>=a[j])
                rank[i]++;
            else
                rank[j]++;
        }
    }
    for(i=0;i<n;i++){
        c[rank[i]]=a[i];
    }
    for(i=0;i<n;i++)
        a[i]=c[i];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    //sort(a,n);
    //sort1(a,n);
    //sort2(a,n);
    //sort3(a,n);
    print(a,n);
    return 0;
}