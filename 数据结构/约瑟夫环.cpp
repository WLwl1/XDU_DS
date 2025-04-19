#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct Node{
	int a;
	int b;
	struct Node*next;
}Node,*linklist;

linklist add(int i){
	linklist Nod=(linklist)malloc(sizeof(Node));
	Nod->next=NULL;
	cin>>Nod->a;
	Nod->b=i; 
	return Nod;
}

void play(linklist &p,linklist &head,int &m){
	if(head==NULL) return; 
	int j;
	linklist current=head;
	while(current->next!=current){
			for(j=0;j<m-1;j++){
				current=current->next;
				p=p->next;
			}
			p->next=current->next;
			m=current->a;
			cout<<current->b<<" ";
			free(current);
			current=p->next;
	}
	cout<<current->b<<" ";
	free(current);
}

int main(){
	int n,m;
	cin>>n>>m;
	int i;
	linklist head=NULL,p=NULL;
	for(i=0;i<n;i++){
		if(!head){
			head=add(i+1);
			p=head;
		}else{
			p->next=add(i+1);
			p=p->next;
		}
	}
	p->next=head;
	play(p,head,m);
	return 0;
}
