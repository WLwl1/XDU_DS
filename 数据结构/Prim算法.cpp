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
	memset(dist, 0x3f, sizeof dist); // �����нڵ�ľ����ʼ��Ϊһ���ܴ��ֵ������󣩡�
	dist[1] = 0; // �ӽڵ�1��ʼ�㷨��

	for (int i = 0; i < n; ++i) // �������нڵ㡣
	{
		int t = -1;
		// �ҵ���δ���뼯�ϵĽڵ��о�����С�Ľڵ㡣
		for (int j = 1; j <= n; ++j)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		st[t] = true; // ���ѡ�еĽڵ�Ϊ�ѷ��ʡ�

		// �����С�����Ա��ֳ�ʼֵ��˵����Щ�ڵ��ǲ��ɴ�ģ�ͼ�Ƿ���ͨ�ġ�
		if (dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
		
		// �ۼӼǵ���ǰ����ֹ��Ȩ�Ի���
		res += dist[t]; // ����ǰ�ڵ�ľ����ۼӵ�����С�

		// ���������ڵ㵽���ϵ���С���룬����и�С�ľ�������¡�
		for (int j = 1; j <= n; ++j)
			dist[j] = min(dist[j], g[t][j]);
	}
	return res; // ������С��������Ȩֵ�͡�
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	memset(g, 0x3f, sizeof g); // ��ʼ�����бߵ�ȨֵΪһ���ܴ��ֵ������󣩡�
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w); // ���±ߵ�Ȩֵ��
	}
	int t = Prim(); // ִ��Prim�㷨�õ���С��������Ȩֵ�͡�
	if (t == 0x3f3f3f3f) cout << "impossible" << endl; // �����С�����������ڣ������"impossible"��
	else cout << t << endl; // �����С��������Ȩֵ�͡�
	return 0;
}



