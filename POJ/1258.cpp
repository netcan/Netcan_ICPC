/*************************************************************************
	> File Name: 1258.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-15 日 09:59:17 CST
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

// 最小生成树裸题Kruskal

int N; // 节点数量
struct edge {
	int from, to, dist;
	bool operator<(const edge &b) const {
		return dist < b.dist;
	}
} es[10006];
int par[105];
void init() {
	for(int i=1; i<=N; ++i) par[i] = i;
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
	int res = 0;
	init();
	int E = N*N;
	sort(es+1, es+1+E);
	for(int i=1; i<=E; ++i) {
		edge e = es[i];
		// printf("u:%d v:%d d:%d\n", e.from, e.to, e.dist);
		if(find(e.from) != find(e.to)) {
			unite(e.from, e.to);
			res += e.dist;
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
	freopen("1258.in", "r", stdin);
#endif
	while(cin >> N) {
		int d;
		int id;
		for(int u=1; u<=N; ++u)
			for(int v=1; v<=N; ++v) {
				cin >> d;
				id = (u-1)*N + v;
				es[id].from = u;
				es[id].to = v;
				es[id].dist = d;
			}
		solve();
	}
	return 0;
}
