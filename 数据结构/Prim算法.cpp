#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;
int g[N][N], dist[N];
bool st[N];
int n, m;

int Prim()
{
	int res = 0;
	memset(dist, 0x3f, sizeof dist); // 将所有节点的距离初始化为一个很大的值（无穷大）。
	dist[1] = 0; // 从节点1开始算法。

	for (int i = 0; i < n; ++i) // 遍历所有节点。
	{
		int t = -1;
		// 找到还未加入集合的节点中距离最小的节点。
		for (int j = 1; j <= n; ++j)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		st[t] = true; // 标记选中的节点为已访问。

		// 如果最小距离仍保持初始值，说明有些节点是不可达的，图是非连通的。
		if (dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
		
		// 累加记得提前，防止负权自环。
		res += dist[t]; // 将当前节点的距离累加到结果中。

		// 更新其他节点到集合的最小距离，如果有更小的距离则更新。
		for (int j = 1; j <= n; ++j)
			dist[j] = min(dist[j], g[t][j]);
	}
	return res; // 返回最小生成树的权值和。
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	memset(g, 0x3f, sizeof g); // 初始化所有边的权值为一个很大的值（无穷大）。
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w); // 更新边的权值。
	}
	int t = Prim(); // 执行Prim算法得到最小生成树的权值和。
	if (t == 0x3f3f3f3f) cout << "impossible" << endl; // 如果最小生成树不存在，则输出"impossible"。
	else cout << t << endl; // 输出最小生成树的权值和。
	return 0;
}



