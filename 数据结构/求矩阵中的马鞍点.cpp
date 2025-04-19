#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
typedef struct{
	int x;
	int y;
	int d;
}Node[50];
int main(){
	int m,n;
	cin>>m>>n;
	int s[50][50];
	int i,j,sign=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>s[i][j];
		}
	}
	Node a;
	for(i=0;i<m;i++){
		int min=s[i][0];
		int b=i,c=0;
		for(j=0;j<n;j++){
			if(s[i][j]<min){
				min=s[i][j];
				c=j;
			}
		}
		a[i].d=min;
		a[i].x=b;
		a[i].y=c;
	}
	int k;
	for(k=0;k<m;k++){
		for(i=0;i<m;i++){
			if(s[i][a[k].y]>a[k].d){
				break;
			}
		}
		if(i==m){
			sign=1;
			cout<<a[k].x+1<<" "<<a[k].y+1<<" "<<a[k].d<<endl;
		}
	}
	if(!sign){
		cout<<"NO";
	}
	return 0;
} 


