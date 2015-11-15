/*************************************************************************
	> File Name: 2224.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-15 日 11:15:17 CST
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

// 求出所有道路的路径和，减去最大生成树即可。
int N, M; // 桩数量，篱笆数量

int par[10005];
void init() {
	for(int i=1; i<=N; ++i) par[i] = i;
}
int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}
bool same(int x, int y) {
	return find(x) == find(y);
}
void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if(x!=y) par[x] = y;
}

struct point{
	int x, y;
} ps[10005];

double dist(point &p1, point &p2) {
	return sqrt((p1.x - p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

struct edge {
	int from, to;
	double cost;
	edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}
	bool operator<(const edge &b) const { // 从大到小排序，求出最大生成树
		return cost > b.cost;
	}
};
vector<edge> es; // 边集


double ans = 0.0; // 答案
void kruskal() {
	init();
	sort(es.begin(), es.end());
	for(vector<edge>::iterator it=es.begin(); it!=es.end(); ++it) {
		if(!same(it->from, it->to)) {
			unite(it->from, it->to);
			ans-=it->cost; // 减去最大生成树的边即可
		}
	 }
}

void solve() {
	kruskal();
	printf("%.3lf\n", ans);
}

int main()
{
#ifdef Oj
	freopen("2224.in", "r", stdin);
#endif
	cin >> N >> M;
	for(int i=1; i<=N; ++i)
		cin >> ps[i].x >> ps[i].y;
	int u, v;
	double d;
	for(int i=0; i<M; ++i) {
		cin >> u >> v;
		d=dist(ps[u], ps[v]);
		es.push_back(edge(u, v, d));
		ans+=d; // 求出所有路径和
	}

	solve();
	return 0;
}
