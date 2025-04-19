#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int m,n;
	int a[50][50];
	int b[50][50];
	int i,j;
	cin>>m>>n;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]){
				cin>>a[i][j];
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>b[i][j];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(b[i][j]){
				cin>>b[i][j];
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			a[i][j]+=b[i][j];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]){
				cout<<"1";
			}else{
				cout<<"0";
			}
			if(j==n-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]){
				cout<<a[i][j];
				cout<<" ";
			}
		}
	}
	return 0;
} 


