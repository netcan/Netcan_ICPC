/*************************************************************************
	> File Name: 1874.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-11 Tue 16:12:20 CST
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
const int MAX_N = 205;
const int MAX_M = 1004;
const int INF = 0x3f3f3f3f;
int N, M, S, T; // 城镇数量， 道路数量， 起点， 终点
int d[MAX_N];
struct Edge{
	int from, to, cost;
} edge[MAX_M];

bool bellman_ford(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	Edge e;
	for(int i=0; i<N-1; ++i)
		for(int j=0; j<M*2; ++j) {
			e = edge[j];
			d[e.to] = min(d[e.to], d[e.from] + e.cost);
		}
	bool flag = true;
	for(int j=0; j<M*2; ++j)
		if(d[edge[j].to] > d[edge[j].from] + edge[j].cost) {
			flag = false;
			break;
		}
	return flag;
}

void solve() {
	cin.sync_with_stdio(false);
	while(cin >> N >> M) {
		int A, B, C;
		for(int i=0; i<M; ++i) {
			cin >> A >> B >> C;
			edge[i].from = edge[i+M].to = A;
			edge[i].to = edge[i+M].from = B;
			edge[i].cost = edge[i+M].cost = C;
		}
		cin >> S >> T;
		bellman_ford(S);
		if(d[T] == INF)
			cout << -1 << endl;
		else
			cout << d[T] << endl;
	}
}

int main()
{
#ifdef Oj
	freopen("1874.in", "r", stdin);
#endif
	solve();
	return 0;
}
