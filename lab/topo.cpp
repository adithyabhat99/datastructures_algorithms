#include<iostream>
using namespace std;
void topo(int **a,int n){
    int ind[n],i,j;
    for(i=0;i<n;i++){
        ind[i]=0;
        for(j=0;j<n;j++)
            ind[i]+=a[j][i];
    }
    int c=0,f=0;
    while(c<n){
        for(i=0;i<n;i++){
            if(ind[i]==0){
                cout<<i<<" ";
                ind[i]=-1;
                for(j=0;j<n;j++){
                    if(a[i][j])
                        ind[j]--;
                }
            }
        }
        c++;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int **a;
    a=new int* [n];
    int i,j;
    for(i=0;i<n;i++){
        a[i]=new int[n];
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    topo(a,n);
    return 0;
}