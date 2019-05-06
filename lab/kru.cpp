#include<iostream>
#include<algorithm>
using namespace std;
class edge{
    public:int s,d,w;
};
bool compare(edge &e1,edge &e2){
    if(e1.w==e2.w)
        return e1.s<e2.s;
    return e1.w<e2.w;
}
int findParent(int *p,int n){
    if(p[n]==n)
        return n;
    return findParent(p,p[n]);
}
void krushkal(edge *E,int e,int v){
    sort(E,E+e,compare);
    int *parent=new int[e];
    int i,count;
    edge curr;
    edge output[v-1];
    for(i=0;i<e;i++)
        parent[i]=i;
    count=i=0;
    while(count<v){
        curr=E[i];
        int sp=findParent(parent,curr.s);
        int dp=findParent(parent,curr.d);
        if(sp!=dp){
            output[count]=curr;
            parent[dp]=sp;
            count++;
        }
        i++;
    }
    cout<<"Minimum spanning tree is\n";
    for(int i=0;i<v-1;i++){
        if(output[i].s<output[i].d){
            cout<<output[i].s<<" "<<output[i].d<<" "<<output[i].w<<endl;
        }
        else{
            cout<<output[i].d<<" "<<output[i].s<<" "<<output[i].w<<endl;
        }
    }
}
int main(){
    int e,v,i;
    cin>>e>>v;
    edge *E=new edge[e];
    for(i=0;i<e;i++){
        cin>>E[i].s>>E[i].d>>E[i].w;
    }
    krushkal(E,e,v);
    return 0;
}
