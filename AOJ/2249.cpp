/*************************************************************************
	> File Name: 2249.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-14 六 09:47:56 CST
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
	int to, dist, cost;
	edge(int to, int dist, int cost) : to(to), dist(dist), cost(cost) {}
	bool operator<(const edge &b) const{
		return dist > b.dist;
	}
};
vector<edge> G[10005];
int N, M; // 节点数，道路数
int d[10005]; // 距离源点s(s==1)的最小距离
int prev_min_cost[10005]; // 前面节点的最小花费
int ans;

void dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(prev_min_cost, 0x3f, sizeof(prev_min_cost));
	d[s] = 0;
	priority_queue<edge> que;
	que.push(edge(s, d[s], 0));
	while(!que.empty()) {
		edge p = que.top(); que.pop();
		int v = p.to;
		if(d[v] < p.dist) continue;
		for(int i=0; i<G[v].size(); ++i) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.dist) {
				d[e.to] = d[v] + e.dist;
				que.push(edge(e.to, d[e.to], G[v][i].cost));
				prev_min_cost[e.to] = e.cost; // 最短路必经之路，则费用也必须要
			}
			else if(d[e.to] == d[v] + e.dist) // 最短路可选择之路，选择最小的费用连接
				prev_min_cost[e.to] = min(prev_min_cost[e.to], e.cost);
		}
	}
}

void solve() {
	dijkstra(1);
	for(int u=2; u<=N; ++u) ans+=prev_min_cost[u]; // 求出所有必须的费用
	cout << ans << endl;

}

int main()
{
#ifdef Oj
	freopen("2249.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int u,v,d,c;
	while(cin >> N >> M) {
		for(int u=1; u<=N; ++u) G[u].clear();
		ans = 0;
		if(N == M && N == 0) break;
		for(int i=0; i<M; ++i) {
			cin >> u >> v >> d >> c;
			G[u].push_back(edge(v, d, c)); // 构图
			G[v].push_back(edge(u, d, c));
		}

		solve();
	}
	return 0;
}
