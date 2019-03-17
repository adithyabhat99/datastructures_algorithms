/*
Test case
9
999 4 999 999 999 999 999 8 999    
4 999 8 999 999 999 999 11 999
999 8 999 7 999 4 999 999 2
999 999 999 7 0 9 14 999 999
999 999 999 9 999 10 999 999 999 
999 999 4 14 10 999 2 999 999 
999 999 999 999 999 2 999 1 6
8 11 999 999 999 999 1 999 7
999 999 2 999 999 999 6 7 999

*/
/*
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
if you takedis[i]=999 initially and all matrix entries are 0 for no direct edges
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
        dis[i]=a[src][i]; //dis[i]=999 if you assume 0 in a[][] as no direct edge
        v[i]=0;
    }
    dis[src]=0;
    for(count=0;count<n-1;count++){
        int u=minW(dis,v,n);
        v[u]=1;
        for(w=0;w<n;w++){
            if(dis[w]>dis[u]+a[u][w] && !v[w])  // &&a[u][w] if you assume 0 in a[][] as no direct edge
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