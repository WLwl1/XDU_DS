#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int DFS(int arc[100][100],int v,int k[100],int m,int n){
	int h=1;
	k[v]=1;
	int j;
	for(j=1;j<=m;j++){
		if((arc[v][j]!=0)&&(!k[j])){
			h+=DFS(arc,j,k,m,n);
		}
	}
	return h;
}
int main(){
	int m,n;
	cin>>m>>n;
	int j;
	int count=0;
	int c=0;
	int arc[100][100]={0};
	int i,t=0;
	for(i=0;i<n;++i){
		int a,b;
		cin>>a>>b;
		arc[a][b]=1;
		arc[b][a]=1;
	}
	int k[100]={0};
	int b[100]={0};
	for(i=1;i<=m;i++){
		if(!k[i]){
			b[t++]=DFS(arc,i,k,m,n);
			c++;
		}
	}
	cout<<c<<endl;
	for(i=0;i<c-1;i++){
		for(j=0;j<c-1-i;j++){
			if(b[j+1]<b[j]){
				int temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
			}
		}
	}
	for(i=0;i<c;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

