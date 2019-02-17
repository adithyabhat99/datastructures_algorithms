/*
Test case
9
0 4 0 0 0 0 0 8 0    
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 0 7 0 9 14 0 0
0 0 0 9 0 10 0 0 0 
0 0 4 14 10 0 2 0 0 
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/

#include<iostream>
using namespace std;
int minW(int dis[],int v[],int n){
    int p=0,min=999;
    for(int i=0;i<n;i++){
        if(!v[i] && dis[i]<min)
        {
            min=dis[i];
            p=i;
        }
    }
    return p;
}
void dij(int **a,int src,int n){
    int dis[n],i,u,w,count;
    int v[n];
    for(i=0;i<n;i++){
        dis[i]=999;
        v[i]=0;
    }
    dis[src]=0;
    for(count=0;count<n-1;count++){
        int u=minW(dis,v,n);
        v[u]=1;
        for(w=0;w<n;w++){
            if(dis[w]>dis[u]+a[u][w] && !v[w] && a[u][w])
            dis[w]=dis[u]+a[u][w];
        }
    }
    for(i=0;i<n;i++)
    cout<<dis[i]<<" ";
    cout<<endl;
}
int main(){
    int **a,i,j,n;
    cin>>n;
    a=new int* [n];
    for(i=0;i<n;i++)
    a[i]=new int [n];
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    cout<<"Enter source\n";
    cin>>i;
    dij(a,i,n);
    return 0;
}