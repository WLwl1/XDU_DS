#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define Maxsize 50
#include<string.h>
using namespace std;
typedef struct{
	char data[Maxsize];
	int top;
}Sqstack;

void Initstack(Sqstack &L){
	L.top=0;
}

bool Emptyis(Sqstack L){
	if(L.top==0){
		return true;
	}else{
		return false;
	}
}

int Push(Sqstack &L,char m){
	if(L.top==Maxsize){
		return -1;
	}
	L.data[L.top++]=m;
}

int Pop(Sqstack &L,char &m){
	if(Emptyis(L)){
		return -1;
	}
	m = L.data[L.top-1];
	L.top--;
}

bool bracketCheck(char str[],int length){
	Sqstack L;
	Initstack(L);
	int i;
	for(i=0;i<length;i++){
		if(str[i]=='('||str[i]=='['||str[i]=='{'){
			Push(L,str[i]);
		}else{
			if(Emptyis(L)){
				return false;
			}
			char elem;
			Pop(L,elem);
			if(str[i]==')'&&elem!='('){
				return false;
			}else if(str[i]=='}'&&elem!='{'){
				return false;
			}else if(str[i]==']'&&elem!='['){
				return false;
			}
		}
	}
	return Emptyis(L);
}

int main(){
	int n;
	cin>>n;
	int i;
	int a[50]={0};
	for(i=0;i<n;i++){
		char m[50];
		scanf("%s",&m);
		if(bracketCheck(m,strlen(m))){
			a[i]=0; 
		}else{
			a[i]=1;
		}
	}
	for(i=0;i<n;i++){
		if(!a[i]){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}


