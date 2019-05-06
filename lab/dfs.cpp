#include<iostream>
using namespace std;
void dfs(int **a,int *vis,int n,int k){
    cout<<k<<" ";
    vis[k]=1;
    for(int i=0;i<n;i++){
        if(a[k][i] && !vis[i])
            dfs(a,vis,n,i);
    }
}
int main(){
    int *vis,**a,n;
    cin>>n;
    int i,j;
    a=new int* [n];
    vis=new int [n];
    for(i=0;i<n;i++){
        a[i]=new int[n];
        vis[i]=0;
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dfs(a,vis,n,0);
    cout<<endl;
    return 0;
}