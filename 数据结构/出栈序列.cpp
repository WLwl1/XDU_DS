#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int s[50];
	int i;
	for(i=0;i<n;i++){
		cin>>s[i];
	}
	int j;
	for(i=0;i<n;i++){
		int t=s[i];
		for(j=i+1;j<n;j++){
			if(s[j]<t){
				t=s[j];
			}else if(s[j]>t&&s[j]>s[i]){
				j+=1;
			}else{
				cout<<"no";
				return 1;
			}
		}
	}
	cout<<"yes";
	return 0;
} 


