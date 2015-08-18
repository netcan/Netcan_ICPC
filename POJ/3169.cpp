/*************************************************************************
	> File Name: 3169.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-18 二 16:07:06 CST
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

int N, ML, MD;
const int INF = 0x3f3f3f3f;
int d[1005];
struct edge {
	int u, v, cost;
} es[21005];

bool Bellman(int s) {
	memset(d, 0x3f, sizeof(d));
	int L = ML + MD + N;
	d[s] = 0;
	for(int i=1; i<=N-1; ++i)
		for(int j=0; j<L; ++j) {
			edge & e = es[j];
			if(d[e.v] > d[e.u] + e.cost)
				d[e.v] = d[e.u] + e.cost;
		}

	for(int j=0; j<L; ++j)
		if(d[es[j].v] > d[es[j].u] + es[j].cost) {
			return false;
		}
	return true;
}

void solve() {
	cin.sync_with_stdio(false);
	cin >> N >> ML >> MD;
	for(int i=0; i<ML; ++i)
		cin >> es[i].u >> es[i].v >> es[i].cost;
	for(int i=0; i<MD; ++i) {
		cin >> es[i+ML].v >> es[i+ML].u >> es[i+ML].cost;
		es[i+ML].cost = -es[i+ML].cost;
	}
	for(int i=2; i<=N; ++i) {
		es[i+ML+MD].v = i-1;
		es[i+ML+MD].u = i;
		es[i+ML+MD].cost = 0;
	}

	if(Bellman(1)) {
		if(d[N] == INF)
			cout << -2 << endl;
		else
			cout << d[N] << endl;
	}
	else
		cout << -1 << endl;

}

int main()
{
#ifdef Oj
	freopen("3169.in", "r", stdin);
#endif
	solve();
	return 0;
}
