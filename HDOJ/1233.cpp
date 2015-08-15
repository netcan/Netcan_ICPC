/*************************************************************************
	> File Name: 1233.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-15 Sat 15:03:47 CST
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
const int MAX_V = 100;
const int INF = 0x3f3f3f3f;
int V;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];

int prim() {
	int res = 0;
	memset(used, 0, sizeof(used));
	memset(mincost, 0x3f, sizeof(mincost));
	mincost[1] = 0;
	while(true) {
		int v = -1;
		for(int u=1; u<=V; ++u)
			if(!used[u] && ( v==-1 || mincost[u] < mincost[v])) v = u;
		if(v == -1) break;
		used[v] = true;
		res += mincost[v];
		for(int u=1; u<=V; ++u)
			mincost[u] = min(mincost[u], cost[v][u]);
	}
	return res;
}

void solve() {
	cin.sync_with_stdio(false);
	while(cin >> V && V)  {
		int from, to, dist;
		memset(cost, 0x3f, sizeof(cost));
		for(int i=V*(V-1)/2; i>0; --i) {
			cin >> from >> to >> dist;
			cost[from][to] = cost[to][from] = dist;
		}
		printf("%d\n", prim());
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
