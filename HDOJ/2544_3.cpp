/*************************************************************************
	> File Name: 2544_3.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-11 Tue 14:47:22 CST
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

const int MAX_V = 105;
const int MAX_E = 10005;
struct edge {
	int to, cost;
	edge(int t, int c): to(t), cost(c){}
};
vector<edge> G[MAX_V];
int d[MAX_V];
typedef pair<int, int> P; // first是最短距离, second是顶点编号
int V, E;

void dijkstra(int s) {
	// greater<P>指定堆按照first从小到大的顺序取值
	priority_queue<P, vector<P>, greater<P> > que;
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	que.push(P(0, s));
	while(!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i=0; i<G[v].size(); ++i) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}



void solve() {
	cin.sync_with_stdio(false);
	while(cin >> V >> E) {
		if(V == E && E == 0)
			break;
		for(int i=0; i<E; ++i) {
			int from, to, cost;
			cin >> from >> to >> cost;
			G[from].push_back(edge(to, cost));
			G[to].push_back(edge(from, cost));
		}
		dijkstra(1);
		cout << d[V] << endl;
		for(int i=1; i<=V; ++i)
			G[i].clear();
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
