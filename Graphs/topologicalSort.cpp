#include<bits/stdc++.h>
using namespace std;
void sort(int **a,int n){
    int ind[n];
    memset(ind,0,sizeof(ind));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ind[i]+=a[j][i];
    int c=0,f=0;
    while(c<n){
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                f=1;
                cout<<i<<" ";
                ind[i]=-1;
                for(int k=0;k<n;k++)
                    if(a[i][k]==1)
                        ind[k]--;
            }
        }
        c++;
    }
    if(!f) cout<<"Cannot traverse\n";
    else cout<<endl;
}
int main(){
    int n,i,j;
    cout<<"Enter number of rows/columns\n";
    cin>>n;
    int **a=(int **)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        a[i]=(int*)malloc(sizeof(int)*n);
    cout<<"Enter the array\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Topological traversal is \n";
    sort(a,n);
    return 0;
}