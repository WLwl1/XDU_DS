#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i,j;
	char a[50];
	char next[50];
	for(i=0;i<n;i++){
		char k;
		cin>>k;
		if(k!=' '){
			a[i]=k;
		}else{
			i--;
		}
	}
	next[0]=-1;
	i=0;
	j=-1;
	while(i<n){
		if(a[i]==a[j]||j==-1){
			next[++i]=++j;
		}else{
		j=next[j];
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",next[i]);
	}
	return 0;
} 


