/*************************************************************************
	> File Name: 2544.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-10 Mon 15:31:55 CST
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
const int inf = 0x3f3f3f3f;

struct Edge{
	int from, to, cost;
} edge[10005*2];
int d[10005];
int N, M;  // 路口N, 路的数量M

bool bellman_ford(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	for(int i=1; i<=N-1; ++i)
		for(int j=1; j<=2*M; ++j) {
			Edge e=edge[j];
			// printf("%d %d %d\n", e.to, e.from, e.cost);
			if(d[e.to] > d[e.from] + e.cost)
				d[e.to] = d[e.from] + e.cost;
		}

	int flag = true; // 判断有没有负圈
	for(int j=1; j<=2*M; ++j)
		if(d[edge[j].to] > d[edge[j].from] + edge[j].cost) {
			flag = false;
			break;
		}
	return flag;
}

void solve() {
	cin.sync_with_stdio(false);
	while(cin >> N >> M)  {
		if(N==M && M==0)
			break;
		for(int i=1; i<=M; ++i) {
			cin >> edge[i].from >> edge[i].to >> edge[i].cost;
			edge[i+M].to = edge[i].from;
			edge[i+M].from = edge[i].to;
			edge[i+M].cost = edge[i].cost;
		}

		bellman_ford(1);
		// for(int i=1; i<=N; ++i)
			// cout << d[i] << endl;
		cout << d[N] << endl;

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
