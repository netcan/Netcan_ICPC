/*************************************************************************
	> File Name: 3255.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-17 一 14:48:51 CST
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

const int INF = 0x3f3f3f3f;

struct edge{
	int to, value;
	edge(int to, int value) : to(to), value(value) {}
	bool operator<(const edge &b) const {
		return value > b.value;
	}
};

int N, R;
vector<edge> G[5005];
int dist[5005];
int dist2[5005];

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof(dist));
	memset(dist2, 0x3f, sizeof(dist2));
	dist[s] = 0;
	priority_queue<edge> que;
	que.push(edge(s, 0));
	while(!que.empty()) {
		edge p = que.top(); que.pop();
		int v = p.to, d = p.value;
		if(dist2[v] < d) continue;
		for(int i=0; i<G[v].size(); ++i) {
			edge &e = G[v][i];
			int d2 = d + e.value;
			if(dist[e.to] > d2) {
				swap(dist[e.to], d2);
				que.push(edge(e.to, dist[e.to]));
			}
			if(dist2[e.to] > d2) {
				dist2[e.to] = d2;
				que.push(edge(e.to, dist2[e.to]));
			}

		}
	}
}


void solve() {
	cin.sync_with_stdio(false);
	cin >> N >> R;
	int u, v, r;
	for(int i=0; i<R; ++i) {
		cin >> u >> v >> r;
		G[u].push_back(edge(v,r));
		G[v].push_back(edge(u,r));
	}
	dijkstra(1);
	cout << dist2[N] << endl;
}

int main()
{
#ifdef Oj
	freopen("3255.in", "r", stdin);
#endif
	solve();
	return 0;
}
