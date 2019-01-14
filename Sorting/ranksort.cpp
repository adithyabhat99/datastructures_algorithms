#include<iostream>
using namespace std;
void ranksort(int a[],int n)
{
    int i,j;
    int rank[n],sorted[n];
    for(i=0;i<n;i++)
        rank[i]=0;
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[i]>=a[j])
                rank[i]++;
            else
                rank[j]++;
        }
    }
    for(i=0;i<n;i++)
    {
        sorted[rank[i]]=a[i];
    }
     cout<<"Sorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<sorted[i]<<"\t";
    }
    cout<<"\n";
}
int main()
{
    int a[100],n,i;
    cout<<"Enter size then array\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
   ranksort(a,n);
   return 0;
}
