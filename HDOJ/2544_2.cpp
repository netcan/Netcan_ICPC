/*************************************************************************
	> File Name: 2544_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-11 Tue 14:14:59 CST
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
const int MAXV = 105;
const int MAXE = 10005;
int cost[MAXV][MAXV];
int d[MAXV];
bool used[MAXV];
int V, E;

void dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(used, 0, sizeof(used));
	d[s] = 0;

	while(true) {
		int v = -1;
		for(int u=1; u<=V; ++u) // 从未使用过的节点中选择一个距离最小的顶点，编号从1开始
			if(!used[u] && (v==-1 || d[u] < d[v])) v = u;
		if(v == -1) break;
		used[v] = true;
		for(int u=1; u<=V; ++u) // 顶点编号从1开始计算
			d[u] = min(d[u], d[v]+cost[v][u]);
	}
}


void solve() {
	cin.sync_with_stdio(false);
	while(cin >> V >> E) {
		if(V==E && V==0)
			break;
		int from, to, cst;
		memset(cost, 0x3f, sizeof(cost));
		for(int i=0; i<E; ++i) {
			cin >> from >> to >> cst;
			cost[from][to] = cost[to][from] = cst;
		}
		dijkstra(1);
		cout << d[V] << endl;
		// for(int i=1; i<=V; ++i)
			// cout << d[i] <<endl;
		// cout << endl;
	}
}

int main()
{
#ifdef Oj
	freopen("2544.in", "r", stdin);
#endif
	solve();
	return 0;
}
