#include<iostream>
using namespace std;
int knap(int *wt,int *p,int n,int W){
    int a[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0){
                a[i][w]=0;
            }   
            else if(wt[i-1]>w){
                a[i][w]=a[i-1][w];
            }
            else{
                a[i][w]=max(a[i-1][w],p[i-1]+a[i-1][w-wt[i-1]]);
            }
        }
    }
    return a[n][W];
}
int main(){
    int n,i,*w,*p,W;
    cin>>n;
    w=new int[n];
    p=new int[n];
    for(i=0;i<n;i++){
        cin>>w[i];
    }
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    cin>>W;
    cout<<"Maximum profit possible is "<<knap(w,p,n,W)<<endl;
    return 0;
}