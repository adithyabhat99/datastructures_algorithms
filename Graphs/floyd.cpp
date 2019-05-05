//All pair shortest path-Floyd's algorithm
#include<iostream>
using namespace std;
int main(){
    int n,i,j,k;
    cout<<"Enter number of vertices\n";
    cin>>n;
    int a[n][n];
    cout<<"Enter adjacancy matrix\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    cout<<"New adjacancy matrix\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}