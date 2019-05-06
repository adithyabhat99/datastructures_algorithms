#include<iostream>
using namespace std;
int main(){
    int **a,n;
    cin>>n;
    a=new int* [n];
    int i,j,min,u,w;
    int parent[n],used[n],dis[n];
    for(i=0;i<n;i++){
        a[i]=new int[n];
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++){
        used[i]=0;
        dis[i]=999;
    }
    dis[0]=0;
    parent[0]=-1;
    for(i=0;i<n-1;i++){
        min=999,u=0;
        for(j=0;j<n;j++){
            if(dis[j]<min && !used[j]){
                min=dis[j];
                u=j;
            }
        }
        used[u]=1;
        for(w=0;w<n;w++){
            if(!used[w] && a[u][w]!=999 && a[u][w]<dis[w]){
                dis[w]=a[u][w];
                parent[w]=u;
            }
        }
    }
    cout<<"Result\n";
    for(i=1;i<n;i++){
        cout<<parent[i]<<" "<<i<<" "<<dis[i]<<endl;
    }
    return 0;
}