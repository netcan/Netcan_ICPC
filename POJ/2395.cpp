/*************************************************************************
	> File Name: 2395.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-04 五 20:28:18 CST
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

int N, M; // 农场数，道路数
int par[2005];

void init_union() {
	for(int i=1; i<=N; ++i) par[i] = i;
}

int find(int x) {
	return par[x] == x?x:par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x!=y) par[x] = y;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

struct edge {
	int u, v, cost;
	edge(int u, int v, int cost): u(u), v(v), cost(cost) {}
	bool operator<(const edge &b) const {
		return cost < b.cost;
	}
};
vector<edge> es;

void solve() {
	sort(es.begin(), es.end());
	init_union();
	for(vector<edge>::iterator i=es.begin(); i!=es.end(); ++i) {
		if(!same(i->u, i->v)) {
			unite(i->u, i->v);
			N--;
		}

		if(N==1) {
			cout << i->cost << endl;
			break;
		}
	}
}

int main()
{
#ifdef Oj
	freopen("2395.in", "r", stdin);
#endif
	cin >> N >> M;
	int u, v, cost;
	for(int i=0; i<M; ++i) {
		cin >> u >> v >> cost;
		es.push_back(edge(u, v, cost));
	}
	solve();
	return 0;
}
