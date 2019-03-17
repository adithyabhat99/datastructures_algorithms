/*
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
#include<bits/stdc++.h>
using namespace std;
int minKeyPos(int *key,bool mst,int v){
	int p,M=INT_MAX;
	for(int i=0;i<v;i++){
		if(!(mst+i) && key[i]<M){
			M=key[i];
			p=i;
		}
	}
	return p;
}
void printGraph(int *parent,int **graph,int v){
	cout<<"Edge   Weight\n";
	for(int i=1;i<v;i++){
		cout<<parent[i]<<"-"<<i<<"-"<<graph[i][parent[i]]<<endl;
	}
}
void prims(int **graph,int v){
	int key[v],parent[v];
	bool mst[v];
	memset(mst,false,sizeof(mst));
	memset(key,INT_MAX,sizeof(key));
	key[0]=0;
	parent[0]=-1;
	for(int i=0;i<v-1;i++){
		int u=minKeyPos(key,mst,v);
			mst[u]=true;
			for(int w=0;w<v;w++){
				if(graph[u][w] && !mst[w] && graph[u][w]<key[w]){
					parent[w]=u;
					key[w]=graph[u][w];
				}
			}
	}
	printGraph(parent,graph,v);
}
int main(){
	int **graph,v,i,j;
	cout<<"Enter numer of vertices\n";
	cin>>v;
	graph=new int* [v];
	for(i=0;i<v;i++)
		graph[i]=new int [v];
	cout<<"Enter matrix now\n";
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			cin>>graph[i][j];
	prims(graph,v);
	for(i=0;i<v;i++)
		delete []graph[i];
	delete []graph;
	return 0;
}