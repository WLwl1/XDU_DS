#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 定义方向常量
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
const int UP = 4;

// 定义坐标和方向的结构体
struct Step {
    int x, y, dir;
    Step(int _x, int _y, int _dir) : x(_x), y(_y), dir(_dir) {}
};

// 检查坐标是否在迷宫范围内
bool isValid(int x, int y, int m, int n) {
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

// DFS函数，寻找路径
bool dfs(vector<vector<int> >& maze, int m, int n, int startX, int startY, int endX, int endY, vector<Step>& path) {
    // 方向数组：右、下、左、上
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // 如果到达终点
    if (startX == endX && startY == endY) {
        return true;
    }

    // 标记当前点为已访问
    maze[startX - 1][startY - 1] = 1;

    // 尝试四个方向
    for (int dir = 0; dir < 4; dir++) {
        int nextX = startX + dx[dir];
        int nextY = startY + dy[dir];

        // 检查下一个点是否有效且是通路
        if (isValid(nextX, nextY, m, n) && maze[nextX - 1][nextY - 1] == 0) {
            path.push_back(Step(startX, startY, dir + 1)); // 记录当前步骤
            if (dfs(maze, m, n, nextX, nextY, endX, endY, path)) {
                return true;
            }
            path.pop_back(); // 回溯
        }
    }

    // 未找到路径
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
        // 输出路径
        path.push_back(Step(endX, endY, 0)); // 添加终点
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
