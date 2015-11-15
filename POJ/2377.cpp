/*************************************************************************
	> File Name: 2377.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-15 日 10:32:04 CST
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

// 求出最大生成树
int N, M; // 节点数，路径数
struct edge {
	int from, to, cost;
	bool operator<(const edge &b) const { // 从大到小选
		return cost > b.cost;
	}
} es[20005];

int par[1005];
void init() {
	for(int i=1; i<=N; ++i) par[i] = i;
}
int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if(x!=y) par[x] = y;
}

int kruskal() {
	int res = 0;
	init();
	sort(es, es+M);
	for(int i=0; i<M; ++i) {
		edge e = es[i];
		if(find(e.from) != find(e.to)) { // 检验是否成环
			unite(e.from, e.to);
			res+=e.cost;
		}
	}
	return res;
}

void solve() {

	int res = kruskal();
	int cnt = 0;

	for(int i=1; i<=N; ++i)
		if(find(i) == i) ++cnt; // 求出根节点数，如果最终结果为一棵树，那么根节点只有一个

	if(cnt != 1)  // 根节点数为1才能形成树
		cout << -1 << endl;
	else
		cout << res << endl;

}

int main()
{
#ifdef Oj
	freopen("2377.in", "r", stdin);
#endif
	cin >> N >> M;
	int u, v, w;
	for(int i=0; i<M; ++i) {
		cin >> u >> v >> w;
		es[i].from = u;
		es[i].to = v;
		es[i].cost = w;
	}
	solve();
	return 0;
}
