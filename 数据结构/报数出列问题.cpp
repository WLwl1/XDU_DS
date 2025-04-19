#include <iostream>
#include <queue>
using namespace std;

void get(queue<int>& q, int n) {
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
}

void operator_(queue<int>& q) {
    while (q.size() > 3) {
        int size = q.size();

        for (int i = 1; i <= size; ++i) {
            int num = q.front();
            q.pop();
            if (i % 2 != 0) {
                q.push(num);
            }
        }
        if (q.size() <= 3) break;

        size = q.size();

        for (int i = 1; i <= size; ++i) {
            int num = q.front();
            q.pop();
            if (i % 3 != 0) {
                q.push(num);
            }
        }
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n;
    cin >> n;
    get(q,n);
    operator_(q);
    return 0;
}

