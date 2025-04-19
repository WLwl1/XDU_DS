#include<iostream>
#include<queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i;
	queue <int> q1;
	queue <int> q2;
	for(i=1;i<=n;i++){
		int k;
		cin>>k;
		if(i%2==1){
			q1.push(k);
		}else{
			q2.push(k);
		}
	}
	while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
	while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
	return 0;
}
