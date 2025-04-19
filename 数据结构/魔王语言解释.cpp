#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define Maxsize 50
typedef struct Sqstack{
	int top;
	char a[Maxsize];
}Sqstack;

void Initstack(Sqstack &L) {
	L.top = 0;
}

void Push(Sqstack &L, char m) {
	if(L.top!=Maxsize)
		L.a[L.top++] = m;
}

void Pop(Sqstack& L, char& m) {
	if (L.top != 0) {
		m = L.a[L.top - 1];
		L.top--;
	}
}

bool Empty(Sqstack L) {
	if (L.top == 0) {
		return true;
	}
	else {
		return false;
	}
}

void switch_it(char c[], int length) {
	Sqstack L;
	Initstack(L);
	int i;
	char m;
	char sign;
	for (i = 0; i < length; i++) {
		if (c[i] == 'A') {
			cout << "sae";
		}
		else if (c[i] == 'B') {
			cout << "tsaedsae";
		}
		else if (c[i] == '(') {
			Push(L, c[i]);
			sign = c[i + 1];
			while (c[i+1] != ')') {
				Push(L, c[i + 1]);
				i++;
			}
			i++;
			cout << sign;
			while (L.top!=2) {
				Pop(L, m);
				if(m=='A'){
					cout<<"sae"<<sign;
				}else if(m=='B'){
					cout<<"tsaedsae"<<sign;
				}else{
					cout << m << sign;
				}
			}
			Pop(L, m);

		}
		else {
			cout << c[i];
		}
	}
	
}

int main() {
	char c[Maxsize];
	scanf("%s", c);
	switch_it(c, strlen(c));

	return 0;
}
