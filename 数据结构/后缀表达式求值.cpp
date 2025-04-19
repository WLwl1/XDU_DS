#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main(){
	vector<int>a(0);
	char s[50];
	scanf("%s",s);
	int i;
	for(i=0;i<strlen(s);i++){
		if(s[i]<='9'&&s[i]>='0'){
			a.push_back(s[i]-'0');
		}else{
			int n1=a.back();
			a.pop_back();
			int n2=a.back();
			a.pop_back();
			if(s[i]=='+'){
				a.push_back(n1+n2);
			}else if(s[i]=='-'){
				a.push_back(n2-n1);
			}else if(s[i]=='*'){
				a.push_back(n2*n1);
			}else if(s[i]=='/'){
				a.push_back(n2/n1);
			}
		}
	}
	cout<<a.back();
	return 0;
} 


