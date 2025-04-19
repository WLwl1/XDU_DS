#include<iostream>
using namespace std;
int parent[100];
struct EdgeType{
	int from,to;
	int w;
};
struct EdgeGraph{
	EdgeType edge[100];
	int vertexNum,edgeNum;
};
int root(int parent[],int vex){
	int temp=vex;
	while(parent[temp]>-1){
		temp=parent[temp];
	}
	return temp;
}
void Kruskal(EdgeGraph G){
	int i;
	int cnt=0;
	for(i=0;i<G.vertexNum;i++){
		parent[i]=-1;
	}
	for(i=0;i<G.edgeNum;i++){
		int r1=root(parent,G.edge[i].from);
		int r2=root(parent,G.edge[i].to);
		if(r1!=r2){
			if(G.edge[i].from>G.edge[i].to){
				int t=G.edge[i].from;
				G.edge[i].from=G.edge[i].to;
				G.edge[i].to=t;
			}
			cout<<G.edge[i].from<<" "<<G.edge[i].to<<" "<<G.edge[i].w<<endl;
			parent[r2]=r1;
			cnt++;
			if(cnt==G.vertexNum-1){
				return;
			}
		}
	}
}

int main(){
	int m,n;
	cin>>m>>n;
	EdgeGraph G;
	G.vertexNum=m;
	G.edgeNum=n;
	int i,j;
	for(i=0;i<n;i++){
		cin>>G.edge[i].from>>G.edge[i].to>>G.edge[i].w;
	}
	for(i=0;i<G.edgeNum-1;i++){
		for(j=0;j<G.edgeNum-i-1;j++){
			if(G.edge[j+1].w<G.edge[j].w){
				EdgeType temp=G.edge[j];
				G.edge[j]=G.edge[j+1];
				G.edge[j+1]=temp; 
			}
		}
	}
	Kruskal(G);
	return 0;
} 

