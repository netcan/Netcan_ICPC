/*************************************************************************
	> File Name: 1002.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-02 六 19:22:16 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N;
int par[100000+5];
int d[100000+5];

void init() {
	for(int i=1; i<=N; ++i) par[i] = i;
}
int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}

void link(int u, int v) {
	u = find(u);
	v = find(v);
	if(u != v) {
		par[u] = v;
		// d[v] = max(d[u], d[v]); // 坑死了，这里严重失误
		d[v] += d[u];
	}
}

void solve() {
	// printf("%d\n", find(1));

	// printf("=============\n");
	// for(int i=1; i<=N; ++i)
		// printf("d[%d]=%d\n", i, d[find(i)]);

	int	ans = d[find(1)];
	for(int i=2; i<=N; ++i) {
		ans ^= d[find(i)];
	}
	printf("%d\n", ans);

}

int main() {
#ifdef Oj
	freopen("1002.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	int u, v, w;
	while(T--) {
		scanf("%d", &N);
		fill(d+1, d+1+N, 1);
		init();
		for(int i=1; i<N; ++i) {
			scanf("%d%d%d\n", &u, &v, &w);
			if(w==0) {
				// ++d[v];
				// ++d[u]; // 严重失误
				link(u, v);
			}
		}
		solve();
	}
	return 0;
}
