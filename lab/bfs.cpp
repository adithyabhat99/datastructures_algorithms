#include<iostream>
using namespace std;
void bfs(int **a,int n){
    int q[n];
    int r=-1,f=0;
    q[++r]=0;
    int vis[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    while(f<=r){
        if(!vis[q[f]])
            cout<<q[f]<<" ";
        vis[q[f]]=1;
        for(int i=0;i<n;i++){
            if(a[q[f]][i] && !vis[i])
                q[++r]=i;
        }
        f++;
    }
}
int main(){
    int **a,n;
    cin>>n;
    int i,j;
    a=new int* [n];
    for(i=0;i<n;i++){
        a[i]=new int[n];
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    bfs(a,n);
    cout<<endl;
    return 0;
}