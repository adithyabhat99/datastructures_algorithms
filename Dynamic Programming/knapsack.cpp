#include<iostream>
using namespace std;
int knap(int profit[],int weight[],int n,int W){
        int v[n+1][W+1];
        int i,w;
        for(i=0;i<=n;i++)
        {
                for(w=0;w<=W;w++){
                        if(i==0 || w==0)
                                v[i][w]=0;
                        else if(weight[i-1]>w){
                                v[i][w]=v[i-1][w];
                        }
                        else
                        {
                                v[i][w]=max(v[i-1][w],profit[i-1]+v[i-1][w-weight[i-1]]);
                        }
                }
        }
        return v[n][W];
}
int main(){
        int n,W;
        cout<<"Enter the number of bags\n";
        cin>>n;
        int profit[n],weight[n];
        cout<<"Enter profit array then weight array\n";
        for(int i=0;i<n;i++)
                cin>>profit[i];
        for(int i=0;i<n;i++)
                cin>>weight[i];
        cout<<"Enter maximum knapsack capapcity\n";
        cin>>W;
        cout<<"Maximum profit that can be obtained is "<<knap(profit,weight,n,W)<<endl;
        return 0;
}
~