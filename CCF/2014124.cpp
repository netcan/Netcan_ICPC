/*************************************************************************
	> File Name: 2014124.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-12 六 16:08:09 CST
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

int n, m; // 麦田数量， 道路数量
int par[1005];
struct edge {
	int u, v, cost;
	bool operator<(const edge &b) const {
		return cost < b.cost;
	}
} es[200005];

void init_union_find(int n) {
	for(int i=1; i<=n; ++i)
		par[i] = i;
}
int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x!=y) par[x] = y;
}

int kruskal() {
	init_union_find(n);
	sort(es, es+2*m);
	int res = 0;
	for(int i=0; i<2*m; ++i) {
		edge e = es[i];
		if(find(e.u) != find(e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

void solve() {
	cout << kruskal() << endl;
}

int main()
{
#ifdef Oj
	freopen("2014124.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> es[i].u >> es[i].v >> es[i].cost;
		es[i+m].u = es[i].v;
		es[i+m].v = es[i].u;
		es[i+m].cost = es[i].cost;
	}
	solve();
	return 0;
}
