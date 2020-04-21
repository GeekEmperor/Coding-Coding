#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
struct edge
{
	int e, l, c;
	edge(int _e, int _l, int _c) { e = _e; l = _l; c = _c; }
};
int main()
{
	int n, m;
	cin >> n >> m;
	int s, e, l, c;
	vector<vector<edge>> graph(n);
	vector<int> degree1(n, 0), degree2(n, 0);
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e >> l >> c;
		graph[s].emplace_back(e, l, c);
		if (c == 1)
			++degree1[e];
		else
			++degree2[e];
	}
	vector<int> dis1(n, INT_MAX >> 1), dis2(n, INT_MAX >> 1);
	vector<bool> visit1(n, false), visit2(n, false);
	dis1[0] = dis2[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int s1 = -1, s2 = -1;
		for (int j = 0; j < n; ++j)
			if (!visit1[j] && (s1 == -1 || dis1[j] < dis1[s1]))
				s1 = j;
		for (int j = 0; j < n; ++j)
			if (!visit2[j] && (s2 == -1 || dis2[j] < dis2[s2]))
				s2 = j;
		if (!degree1[s1])
			visit1[s1] = true;
		if (!degree2[s2])
			visit2[s2] = true;
		for (const edge& it : graph[s1])
		{
			
			if (it.c == 2 && dis2[it.e] > dis1[s1] + it.l)
				dis2[it.e] = dis1[s1] + it.l;
		}
		for (const edge& it : graph[s2])
		{
			--degree1[it.e];
			if (it.c == 1 && dis1[it.e] > dis2[s2] + it.l)
				dis1[it.e] = dis2[s2] + it.l;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int d = min(dis1[i], dis2[i]);
		cout << (d == INT_MAX >> 1 ? -1 : d) << ' ';
	}
	// system("pause");
	return 0;
}
/*
6 7
0 1 1 1
0 4 1 1
0 3 1 1
1 2 1 1
4 2 1 2
3 2 2 2
2 5 3 1
*/
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define maxValue 0x3f3f3f3f

struct edge
{
	int dest;
	int weight;
	int driver;
	edge* next;
	edge(int _dest, int _weight, int _driver, edge* _next) :driver(_driver), dest(_dest), weight(_weight), next(_next) {}
};

struct vertex {
	int v;
	edge* next;
	vertex(int _v = 0) :v(_v) { next = nullptr; }
};


int main()
{
	int n, m;
	cin >> n >> m;
	vertex* graph = new vertex[n];
	for (int i = 0; i < n; i++)
		graph[i].v = i;
	for (int i = 0; i < m; i++)
	{
		int s, e, l, c;
		cin >> s >> e >> l >> c;
		//if (s != e)
		graph[s].next = new edge(e, l, c - 1, graph[s].next);
	}

	vector<vector<bool>> S(n, vector<bool>(2));
	vector<vector<int>> dist(n, vector<int>(2));
	for (int i = 0; i < n; i++)
	{
		dist[i][0] = maxValue;
		dist[i][1] = maxValue;
		S[i][0] = false;
		S[i][1] = false;
	}

	for (auto ptr = graph[0].next; ptr != nullptr; ptr = ptr->next)
	{
		dist[ptr->dest][ptr->driver] = ptr->weight;
	}

	S[0][0] = true;
	S[0][1] = true;
	dist[0][0] = 0;
	dist[0][1] = 0;
	int u0 = 0;
	int u1 = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int min0 = maxValue;
		int min1 = maxValue;
		for (int j = 0; j < n; j++)
		{
			if (S[j][0] == false && dist[j][0] < min0)
			{
				min0 = dist[j][0];
				u0 = j;
			}
			if (S[j][1] == false && dist[j][1] < min1)
			{
				min1 = dist[j][1];
				u1 = j;
			}
		}

		S[u0][0] = true;		//小蓝鲸驾驶到达的结点
		S[u1][1] = true;        //朋友驾驶到达的结点

		for (auto ptr = graph[u0].next; ptr != nullptr; ptr = ptr->next)
		{
			if (ptr->driver == 1)
			{
				if (dist[u0][0] + ptr->weight < dist[ptr->dest][1])
					dist[ptr->dest][1] = dist[u0][0] + ptr->weight;
			}
		}

		for (auto ptr = graph[u1].next; ptr != nullptr; ptr = ptr->next)
		{
			if (ptr->driver == 0)
			{
				if (dist[u1][1] + ptr->weight < dist[ptr->dest][0])
					dist[ptr->dest][0] = dist[u1][1] + ptr->weight;
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		int t = min(dist[i][0], dist[i][1]);
		if (t != maxValue)
			cout << min(dist[i][0], dist[i][1]) << ' ';
		else
			cout << -1 << ' ';
	}
	system("pause");
	return 0;
}
*/