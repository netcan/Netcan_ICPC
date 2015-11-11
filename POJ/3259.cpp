/*************************************************************************
	> File Name: 3259.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-11 三 22:28:00 CST
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
int F, N, M, W; // 农场数，区域数，道路数，虫洞数
struct edge {
	int from, to, cost;
} es[5300];

int d[505];
// int Es;

const int INF = 0x3f3f3f3f;

bool bellman_ford(int s) { // 判断是否有负边
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	int Es = 2*M+W;
	for(int i=1; i<=N-1; ++i)
		for(int j=0; j<Es; ++j) {
			edge e = es[j];
			if(d[e.to] > d[e.from] + e.cost) d[e.to] = d[e.from] + e.cost;
		}
	int flag = true;
	for(int j=0; j<Es; ++j)
		if(d[es[j].to] > d[es[j].from] + es[j].cost) { // 负边判断, 有负边
			flag = false;
			break;
		}
	return flag;
}


void solve() {
	puts(bellman_ford(1)?"NO":"YES");
}

int main()
{
#ifdef Oj
	freopen("3259.in", "r", stdin);
#endif
	scanf("%d", &F);
	int S, E, T;
	while(F--) {
		// Es=0;
		scanf("%d%d%d", &N, &M, &W);
		for(int i=0; i<M; ++i) {
			scanf("%d%d%d", &S, &E, &T);

			es[i].from = es[i+M].to= S; // 双向边
			es[i].to = es[i+M].from = E;
			es[i].cost = es[i+M].cost = T;
		}
		for(int i=0; i<W; ++i) {
			scanf("%d%d%d", &S, &E, &T);

			es[i+2*M].from = S; // 虫洞单向边
			es[i+2*M].to = E;
			es[i+2*M].cost = -T; // 时间倒流, -T
		}
		solve();
	}
	return 0;
}
