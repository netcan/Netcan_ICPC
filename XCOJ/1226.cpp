#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, D;
const int MAX_V = 100005;
struct edge { // 顶点属性
	int to, val;
	edge(int t, int v): to(t), val(v){}
	bool operator<(const edge &b) const {
		return val > b.val;
	}
};
vector<edge> G[MAX_V]; // 邻接链表图
int d[MAX_V];
int V, E; // 顶点数V, 边数E
void dijkstra(int s) {
	priority_queue<edge> que;
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	que.push(edge(s, 0)); // 源点入队
	while(!que.empty()) {
		edge p = que.top(); que.pop();
		int v = p.to;
		if(d[v] < p.val) continue; // 当前最小值不是最短距离的话,丢弃
		for(int i=0; i<G[v].size(); ++i) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.val) {
				d[e.to] = d[v] + e.val;
				que.push(edge(e.to, d[e.to]));
			}
		}
	}
}

void solve() {
	dijkstra(0);
	int ans = 0;
	for(int i=0; i<N; ++i)
		if(d[i] > D) ++ans;
	cout << ans << endl;
}

int main()
{
	cin.sync_with_stdio(false);
	while(cin >> N >> D) {
		for(int i=0; i<N; ++i) G[i].clear();
		int a, b;
		for(int i=0; i<N-1; ++i) {
			cin >> a >> b;
			G[a].push_back(edge(b, 1));
			G[b].push_back(edge(a, 1));
		}
		solve();
	}
    return 0;
}
