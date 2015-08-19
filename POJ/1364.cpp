/*************************************************************************
	> File Name: 1364.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-19 三 14:35:05 CST
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

struct edge{
	int u, v, cost;
} es[102];
int n, m;
int d[102];
bool Bellman_Ford(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j) {
			edge &e = es[j];
			d[e.v] = min(d[e.v], d[e.u] + e.cost);
		}
	for(int j=0; j<m; ++j) {
		edge &e = es[j];
		if(d[e.v] > d[e.u] + e.cost)
			return false;
	}
	return true;
}


void solve() {
	cin.sync_with_stdio(false);
	string op;
	int a,b,c;
	while(cin >> n && n) {
		cin >> m;
		for(int i=0; i<m; ++i) {
			cin >> a >> b >> op >> c;
			if(op == "gt") {
				es[i].u = a+b;
				es[i].v = a-1;
				es[i].cost = -(c+1);
			}
			else {
				es[i].u = a-1;
				es[i].v = a+b;
				es[i].cost = c-1;
			}
		}
		if(Bellman_Ford(0))
			cout << "lamentable kingdom" << endl;
		else
			cout << "successful conspiracy" << endl;

	}

}

int main()
{
#ifdef Oj
	freopen("1364.in", "r", stdin);
#endif
	solve();
	return 0;
}
