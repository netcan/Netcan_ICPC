/*************************************************************************
	> File Name: 3723.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-18 二 14:34:00 CST
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

int N, M, R;
int par[20005];

struct edge {
	int u, v, cost;
	bool operator<(const edge &b) const {
		return cost > b.cost;
	}
} es[50010];

void init_union_find() {
	for(int i=0; i<2*N; ++i)
		par[i] = i;
}
int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x!=y)
		par[x] = y;
}
int kruskal() {
	sort(es, es+R);
	init_union_find();
	int res = 0;
	for(int i=0; i<R; ++i) {
		edge &e = es[i];
		if(find(e.u) != find(e.v)) {
			unite(e.u, e.v);
			res+=e.cost;
		}
	}
	return res;
}


void solve() {
	int T;
	cin >> T;
	while(T--) {
		scanf("%d%d%d", &N, &M, &R);
		for(int i=0; i<R; ++i) {
			// cin >> es[i].u >> es[i].v >> es[i].cost;
			scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);
			es[i].v+=N;
		}
		// cout << 10000*(N+M) + kruskal() << endl;
		printf("%d\n", 10000*(N+M)-kruskal());
	}

}

int main()
{
#ifdef Oj
	freopen("3723.in", "r", stdin);
#endif
	solve();
	return 0;
}
