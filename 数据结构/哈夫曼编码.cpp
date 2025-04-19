#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int b,c;
	int sum=0;
	priority_queue<int,vector<int>,greater<int> > a;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a.push(t);
	}
	while(a.size()>1){
		b=a.top();
		a.pop();
		c=a.top();
		a.pop();
		a.push(b+c);
		sum=sum+b+c;
	}
	cout<<sum;
	return 0;
}

