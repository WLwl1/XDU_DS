#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int i,j;
	char s[100];
	gets(s);
	int sign=0;
	int length=strlen(s);
	for(i=1;i<=length;i++){
		if(length%i==0){
			sign=1;
		}
		for(j=i;j<length;j++){
			if(s[j]!=s[j%i]){
				sign=0;
				break;
			}
		}
		if(sign!=0){
			cout<<i;
			break;
		}
	}
	return 0;
}
