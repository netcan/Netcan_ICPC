/*************************************************************************
	> File Name: 1285.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-12 四 21:46:38 CST
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
int N, M;

vector<int> G[505]; // 邻接表
vector<int> order;
int indegree[505];

void top_sort() {
	order.clear();
	priority_queue<int, vector<int>, greater<int> > que; // 最小堆，按照从小到大的顺序输出
	for(int u=1; u<=N; ++u) if(indegree[u] == 0) que.push(u);
	int u;
	while(!que.empty()) {
		u = que.top(); que.pop();
		order.push_back(u);
		for(int i = 0; i<G[u].size(); ++i) {
			--indegree[G[u][i]];
			if(indegree[G[u][i]] == 0) que.push(G[u][i]);
		}
	}
}

void solve() {
	cout << indegree[3] << endl;
	top_sort();

	for(int i=0; i<N; ++i)
		printf(i==0?"%d":" %d", order.at(i));
	puts("");
}

int main()
{
#ifdef Oj
	freopen("1285.in", "r", stdin);
#endif
	int u, v;
	while(cin >> N >> M) {
		memset(indegree, 0, sizeof(indegree));
		for(int i=1; i<=N; ++i) G[i].clear();

		for(int i=0; i<M; ++i) {
			cin >> u >> v;
			G[u].push_back(v);
			++indegree[v];
		}
		solve();
	}
	return 0;
}
