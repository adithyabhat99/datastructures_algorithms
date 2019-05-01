#include<bits/stdc++.h>
using namespace std;
bool isCycle(int **a,int n,int k,int parent,bool *vis){
    if(vis[k]) return true;
    vis[k]=true;
    for(int i=0;i<n;i++){
        if(vis[i] && a[k][i] && i!=parent)
            return true;
        else if(a[k][i])
            isCycle(a,n,i,k,vis);
    }
    return false;
}
int main(){
    int i,j,n;
    cout<<"Enter number of vertices\n";
    cin>>n;
    cout<<"Enter adjacency matrix\n";
    int **a=new int*[n];
    for(i=0;i<n;i++) a[i]=new int[n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    bool vis[n];
    memset(vis,false,sizeof(vis));
    if(isCycle(a,n,0,0,vis))
        cout<<"Yes,there is a cycle\n";
    else 
        cout<<"There is no cycle\n";
    return 0;
}