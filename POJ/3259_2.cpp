/*************************************************************************
	> File Name: 3259_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-12 四 09:38:12 CST
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
struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
};

int V, E; // 节点数，边数
int d[505]; // 单源最短距离
vector<edge> G[505]; // 图， 邻接表
bool vinque[505]; // 判断节点是否已经在队列中
int cnt[505]; // 记录每个节点入队次数，超过V则退出（有负圈）。

bool SPFA(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(vinque, 0, sizeof(vinque));
	memset(cnt, 0, sizeof(cnt));
	d[s] = 0;
	queue<int> que; // 入队，存储SPFA需要松弛计算的节点
	que.push(s);
	vinque[s] = true;
	cnt[s] = 1;
	while(!que.empty()) {
		int from = que.front();
		for(int i=0; i<G[from].size(); ++i) {
			edge *t = &G[from][i]; // 据说用指针可以提高寻址速度。。
			if(d[t->to] > d[from] + t->cost) {
				d[t->to] = d[from] + t->cost; // 松弛计算
				if(!vinque[t->to]) { // 该节点未入队，将其入队
					que.push(t->to);
					vinque[t->to] = true;
					++cnt[t->to]; // 入队次数加一
					if(cnt[t->to] > V) {
						// while(!que.empty()) que.pop();
						return false;
					}
				}
			}
		}
		que.pop();
		vinque[from] = false;
	}
	return true;
}


void solve() {
	puts(SPFA(1)?"NO":"YES");
}

int main()
{
#ifdef Oj
	freopen("3259.in", "r", stdin);
#endif
	int F; // 农场数
	int M, W; // 区域数，虫洞数
	int S, E, T; // 起点，终点，时间
	scanf("%d", &F);
	while(F--) {
		scanf("%d%d%d", &V, &M, &W);

		for(int i=1; i<=V; ++i) G[i].clear(); // 清空图

		for(int i=0; i<M; ++i) {
			scanf("%d%d%d", &S, &E, &T);
			G[S].push_back(edge(E, T));
			G[E].push_back(edge(S, T));
		}
		for(int i=0; i<W; ++i) {
			scanf("%d%d%d", &S, &E, &T);
			G[S].push_back(edge(E, -T));
		}
		solve();
	}
	return 0;
}
