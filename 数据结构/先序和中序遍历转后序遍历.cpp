#include<iostream>
#include<string>
using namespace std;
void post(string pre,string in ){
	if(pre.empty()){
		return;
	}
	int index=in.find(pre[0]);
	post(pre.substr(1,index),in.substr(0,index));
	post(pre.substr(index+1),in.substr(index+1));
	cout<<pre[0];
}


int main(){
	string pre;
	string in;
	cin>>pre>>in;
	post(pre,in);
	return 0;
}
