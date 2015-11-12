/*************************************************************************
	> File Name: 3268.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-12 四 19:27:43 CST
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

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
	bool operator<(const edge &b) const {
		return cost > b.cost;
	}
};
vector<edge> G[1002]; // 图
int s[1002]; // 从目标回去各个出发点的最短路
int d[1002]; // 从各个出发点到达目标的最短路
int N, M, X;

void dijkstra(int s) {
	priority_queue<edge> que;
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	que.push(edge(s, 0));
	while(!que.empty()) {
		edge p = que.top(); que.pop();
		int v = p.to;
		if(d[v] < p.cost) continue;
		for(int i=0; i<G[v].size(); ++i) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(edge(e.to, d[e.to]));
			}
		}
	}
}

void solve() {
	dijkstra(X); // 先求出由出发点回去的最短路
	memcpy(s+1, d+1, sizeof(int)*N);
	int ans = 0;
	for(int i=1; i<=N; ++i) // 再分别求出到达目标的最短路
		if(i!=X) {
			dijkstra(i);
			ans=max(ans, d[X]+s[i]);
		}
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("3268.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> N >> M >> X;
	int from, to, cost;
	for(int i=0; i<M; ++i) {
		cin >> from >> to >> cost;
		G[from].push_back(edge(to, cost));
	}
	solve();
	return 0;
}
