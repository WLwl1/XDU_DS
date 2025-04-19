#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main(){
	vector<int>a(0);
	char s[50];
	gets(s); 
	int i;
	vector<int>b(0);
	for(i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			int k=0;
			while(s[i]!=' '&&s[i]!='\0'){
				k=k*10+s[i]-'0';
				i++;
			}
			b.push_back(k);
		}
	}
	for(i=strlen(s)-1;i>=0;i--){
		if(s[i]<='9'&&s[i]>='0'){
			int m=b.back();
			b.pop_back();
			a.push_back(m);
			while(s[i]!=' '){
				i--;
			}
		}
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			int n1=a.back();
			a.pop_back();
			int n2=a.back();
			a.pop_back();
			if(s[i]=='+'){
				a.push_back(n1+n2);
			}else if(s[i]=='-'){
				a.push_back(n1-n2);
			}else if(s[i]=='*'){
				a.push_back(n1*n2);
			}else if(s[i]=='/'){
				a.push_back(n1/n2);
			}
		}
	}
	int c=a.back();
	cout<<c;
	return 0;
} 


