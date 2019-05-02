#include<bits/stdc++.h>
using namespace std;
void dfs(int **a,bool *vis,int n,int k){
    cout<<k<<" ";
    vis[k]=true;
    for(int i=0;i<n;i++){
        if(a[k][i] && !vis[i]){
            dfs(a,vis,n,i);
        }
    }
}
int main(){
    int n,**a;
    cout<<"Enter number of vertices\n";
    cin>>n;
    a=new int* [n];
    for(int i=0;i<n;i++)
        a[i]=new int[n];
    cout<<"Enter the adjacancy matrix,1 for an edge, 0 for no edge\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"DFS\n";
    bool vis[n];
    memset(vis,false,sizeof(vis));
    dfs(a,vis,n,0);
    cout<<endl;
    return 0;
}