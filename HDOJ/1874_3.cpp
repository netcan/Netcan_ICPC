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
struct edge{
	int to, val;
	edge(int t, int v): to(t), val(v) {}
	bool operator<(const edge &b) const {
		return val > b.val;
	}
};
vector<edge> G[MAX_N];
int d[MAX_N];
bool used[MAX_N];

void dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	priority_queue<edge> que;
	que.push(edge(s, 0));
	while(!que.empty()) {
		edge p = que.top(); que.pop();
		int v = p.to;
		if(p.val > d[v]) continue;
		for(int i=0; i<G[v].size(); ++i) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.val) {
				d[e.to] = d[v] + e.val;
				que.push(edge(e.to, d[e.to]));
			}
		}
	}
}

void solve() {
	cin.sync_with_stdio(false);
	while(cin >> N >> M) {
		int A, B, C;
		for(int i=0; i<M; ++i) {
			cin >> A >> B >> C;
			G[A].push_back(edge(B, C));
			G[B].push_back(edge(A, C));
		}
		cin >> S >> T;
		dijkstra(S);
		for(int i=0; i<N; ++i)
			G[i].clear();

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
