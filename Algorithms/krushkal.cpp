/*
Testcase
Enter number of vertices
6
Enter number of edges
11
Enter each edge's source,dest and weight
0 3 3
0 2 4
0 1 2
1 3 1
4 5 5
2 3 6
3 5 7
2 1 8
2 4 9
2 5 10
3 4 11
*/
#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
int findParent(int *parent,int n){
    if(parent[n]==n)
        return n;
    return findParent(parent,parent[n]);
}
bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}
void krushkal(Edge *E,int e,int n){
    int *parent=new int[e];
    sort(E,E+e,compare);
    int i,count;
    for(i=0;i<e;i++)
        parent[i]=i;
    count=i=0;
    Edge curr;
    Edge *output=new Edge[n-1];
    while(count<n){
        curr=E[i];
        int sourceParent=findParent(parent,curr.source);
        int destParent=findParent(parent,curr.dest);
        if(sourceParent!=destParent){
            output[count]=curr;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    cout<<"Minimum spanning tree is\n";
    for(int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}
int main(){
    int n,i,e;
    cout<<"Enter number of vertices\n";
    cin>>n;
    cout<<"Enter number of edges\n";
    cin>>e;
    Edge *E=new Edge[e];
    cout<<"Enter each edge's source,dest and weight\n";
    for(i=0;i<e;i++)
    {
        cin>>E[i].source>>E[i].dest>>E[i].weight;
    }
    krushkal(E,e,n);
}