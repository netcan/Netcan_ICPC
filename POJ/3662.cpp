/*************************************************************************
	> File Name: 3662.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-28 一 09:35:21 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, P, K;
struct edge {
	int to, length;
	edge(int to, int length) : to(to), length(length) {}
};

vector<edge> G[1005];
bool visited[1005];
int ans = (1<<30)-5;
int que[100000];
int que_id = 0;

void dfs(const int s, const int t) {
	visited[s] = true;
	if(s == t) {
		if(que_id <= K) {
			ans = 0;
		}
		else {
			sort(que, que+que_id);
			ans = min(ans, que[K]);
		}
	}

	for(unsigned int i=0; i<G[s].size(); ++i) {
		int to = G[s][i].to;
		int len = G[s][i].length;
		if(!visited[to]) {
			// printf("%d->%d len:%d\n", s, to, len);
			visited[to] = true;
			que[que_id++] = len;
			dfs(to, t);
			visited[to] = false;
			que[que_id--] = (1<<30) - 1;
		}
	}
}

void solve() {
	dfs(1, N);
	printf("%d\n", ans == (1<<30)-5?-1:ans);

}

int main() {
#ifdef Oj
	freopen("3662.in", "r", stdin);
#endif
	scanf("%d%d%d", &N, &P, &K);
	int a, b, l;
	for (int i = 0; i < P; ++i) {
		scanf("%d%d%d", &a, &b, &l);
		G[a].push_back(edge(b, l));
		G[b].push_back(edge(a, l));
	}
	solve();
	return 0;
}
