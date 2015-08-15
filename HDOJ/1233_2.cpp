/*************************************************************************
	> File Name: 1233_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-15 Sat 15:29:31 CST
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
int V, E;
int par[MAX_V];
struct edge {
	int u, v, cost;
	bool operator<(const edge &b) const {
		return cost < b.cost;
	}
} es[MAX_V*(MAX_V-1)/2];

void init_union_find(int N) {
	for(int i=1; i<=N; ++i)
		par[i] = i;
}

int find(int x) {
	return x==par[x]?x:find(par[x]);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y)
		par[x] = y;
}

int kruskal() {
	sort(es, es+E);
	init_union_find(V);
	int res = 0;
	for(int i=0; i<E; ++i) {
		edge e = es[i];
		if(find(e.u) != find(e.v)) {
			unite(e.u, e.v);
			res+=e.cost;
		}
	}
	return res;
}


void solve() {
	cin.sync_with_stdio(false);
	while(cin >> V && V) {
		E = V*(V-1)/2;

		int from, to, cost;
		for(int i=0; i<E; ++i) {
			cin >> from >> to >>cost;
			es[i].u = from;
			es[i].v = to;
			es[i].cost = cost;
		}
		printf("%d\n", kruskal());
	}

}

int main()
{
#ifdef Oj
	freopen("1233.in", "r", stdin);
#endif
	solve();
	return 0;
}
