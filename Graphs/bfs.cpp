#include<bits/stdc++.h>
using namespace std;
void bfs(int **a,int n){
    queue<int> q;
    q.push(0);
    bool vis[n];
    memset(vis,false,sizeof(vis));
    vis[0]=1;
    while(!q.empty()){
        int f=q.front();
        cout<<f<<" ";
        for(int i=0;i<n;i++){
            if(a[f][i] && !vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
        q.pop();
    }
    cout<<endl;
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
    cout<<"BFS\n";
    bfs(a,n);
    return 0;
}