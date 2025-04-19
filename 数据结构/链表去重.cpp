#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

typedef struct{
	int ad;
	int value;
	int next;
	int sign;
}Node,link[100001];
int main(){
	int count=0;
	int n;
	link a;
	int head;
	cin>>head>>n;
	int i;
	int adv;
	for(i=0;i<n;i++){
		cin>>adv;
		cin>>a[adv].value>>a[adv].next;
		a[adv].sign=1;
		a[adv].ad=adv;
	}
	adv=head;
	int p=a[adv].next;
	while(adv!=-1){
		while(p!=-1&&a[adv].sign==1){
			if(abs(a[p].value)==abs(a[adv].value)){
				a[p].sign=0;
				n--;
			}
			p=a[p].next;
		}
		adv=a[adv].next;
		p=a[adv].next;
	}
	p=head;
	int j=a[p].next;
	while(j!=-1){
		if(a[j].sign==0){
			a[p].next=a[j].next;
			j=a[p].next;
		}else{
			p=a[p].next;
			j=a[j].next;
		}
	}
	a[p].next=-1;
	cout<<n<<endl;
	while(head!=-1){
		if(a[head].sign&&a[head].next!=-1)
			{
				printf("%.5d %d %.5d\n",a[head].ad,a[head].value,a[head].next);
			}else if(a[head].sign&&a[head].next==-1){
				printf("%.5d %d -1\n",a[head].ad,a[head].value);
			}
		head=a[head].next;
	}
	return 0;
} 


