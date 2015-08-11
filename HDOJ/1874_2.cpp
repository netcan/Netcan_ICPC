/*************************************************************************
	> File Name: 1874.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-11 Tue 16:12:20 CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <stack>
#include <set>
#include <numeric>
#include <utility>
#include <cstring>
using namespace std;
const int MAX_N = 205;
const int MAX_M = 1004;
const int INF = 0x3f3f3f3f;
int N, M, S, T; // 城镇数量， 道路数量， 起点， 终点
int d[MAX_N];
bool used[MAX_N];
int cost[MAX_N][MAX_N];

void dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	memset(used, 0, sizeof(used));

	while(true) {
		int v = -1;
		for(int u=0; u<N; ++u)
			if(!used[u] && (v==-1 || d[u] < d[v])) v = u;
		if(v == -1) break;
		used[v] = true;
		for(int u=0; u<N; ++u)
			d[u] = min(d[u], d[v] + cost[v][u]);
	}
}

void solve() {
	cin.sync_with_stdio(false);
	while(cin >> N >> M) {
		int A, B, C;
		memset(cost, 0x3f, sizeof(cost));
		for(int i=0; i<M; ++i) {
			cin >> A >> B >> C;
			if(cost[A][B] == INF) // 题目有坑！A->B的路径不一定只有一条。。。。
				cost[A][B] = cost[B][A] = C;
			else
				cost[A][B] = cost[B][A] = min(cost[A][B], C);
		}
		cin >> S >> T;
		dijkstra(S);

		if(d[T] == INF)
			cout << -1 << endl;
		else
			cout << d[T] << endl;
	}
}

int main()
{
#ifdef Oj
	freopen("1874.in", "r", stdin);
#endif
	solve();
	return 0;
}
