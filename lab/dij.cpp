#include<iostream>
using namespace std;
int minW(int *dis,int *v,int n){
    int m=0,min=INT32_MAX;
    for(int i=0;i<n;i++){
        if(dis[i]<min && !v[i]){
            min=dis[i];
            m=i;
        }
    }
    return m;
}
void dij(int **a,int n,int s){
    int dis[n],i,j,u,w,count,v[n];
    for(i=0;i<n;i++){
        dis[i]=a[s][i];
        v[i]=0;
    }
    dis[s]=0;
    for(count=0;count<n-1;count++){
        u=minW(dis,v,n);
        v[u]=1;
        for(w=0;w<n;w++){
            if(dis[w]>dis[u]+a[u][w] && !v[w]){
                dis[w]=dis[u]+a[u][w];
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,**a,s,i,j;
    cin>>n;
    a=new int* [n];
    for(i=0;i<n;i++){
        a[i]=new int[n];
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    cin>>s;
    dij(a,n,s);
    return 0;
}