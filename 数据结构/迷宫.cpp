#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ���巽����
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
const int UP = 4;

// ��������ͷ���Ľṹ��
struct Step {
    int x, y, dir;
    Step(int _x, int _y, int _dir) : x(_x), y(_y), dir(_dir) {}
};

// ��������Ƿ����Թ���Χ��
bool isValid(int x, int y, int m, int n) {
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

// DFS������Ѱ��·��
bool dfs(vector<vector<int> >& maze, int m, int n, int startX, int startY, int endX, int endY, vector<Step>& path) {
    // �������飺�ҡ��¡�����
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // ��������յ�
    if (startX == endX && startY == endY) {
        return true;
    }

    // ��ǵ�ǰ��Ϊ�ѷ���
    maze[startX - 1][startY - 1] = 1;

    // �����ĸ�����
    for (int dir = 0; dir < 4; dir++) {
        int nextX = startX + dx[dir];
        int nextY = startY + dy[dir];

        // �����һ�����Ƿ���Ч����ͨ·
        if (isValid(nextX, nextY, m, n) && maze[nextX - 1][nextY - 1] == 0) {
            path.push_back(Step(startX, startY, dir + 1)); // ��¼��ǰ����
            if (dfs(maze, m, n, nextX, nextY, endX, endY, path)) {
                return true;
            }
            path.pop_back(); // ����
        }
    }

    // δ�ҵ�·��
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;

    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    vector<vector<int> > maze(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<Step> path;
    if (dfs(maze, m, n, startX, startY, endX, endY, path)) {
        // ���·��
        path.push_back(Step(endX, endY, 0)); // ����յ�
        for (size_t i = 0; i < path.size(); i++) {
            cout << "(" << path[i].x << "," << path[i].y << "," << path[i].dir << ")";
            if (i != path.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
