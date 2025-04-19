#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
	stack<char> sk;
	queue<char> q;
	int i;
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		char k;
		cin>>k;
		q.push(k);
		sk.push(k);
	}
	while(!q.empty()){
		if(q.front()!=sk.top()){
			cout<<"NO";
			return 1;
		}else{
			q.pop();
			sk.pop();
		}
	}
	cout<<"YES";
	return 0;
}
