#include<iostream>
using namespace std;
int place(int k,int j,int *x){
    for(int i=1;i<k;i++){
        if(x[i]==j || (x[i]-j==(i-k)) || (j-x[i]==(i-k)))
            return 0;
    }
    return 1;
}
void nq(int n,int *x,int k){
    for(int j=1;j<=n;j++){
        if(place(k,j,x)){
            x[k]=j;
            if(k==n){
                for(int i=1;i<=n;i++)
                    cout<<x[i]<<" ";
                    cout<<endl;
            }
            else{
                nq(n,x,k+1);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int x[n+1];
    nq(n,x,1);
    return 0;
}