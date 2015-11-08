/*************************************************************************
	> File Name: 2236.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-08 日 21:56:17 CST
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

int par[1024];
int N, D; // 电脑数量，距离
int dist[1024][1024];

struct computer {
	int x, y;
} comp[1024];


// bool repaired[1024];
int repaired[1024];

void init_union_found() {
	for(int i=1; i<=N; ++i) par[i] = i;
}
int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}
bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x!=y) par[x] = y;
	return true;
}

int d(int i, int j) {
	return dist[i][j] == -1?dist[i][j]=(comp[i].x-comp[j].x)*(comp[i].x-comp[j].x) + (comp[i].y-comp[j].y)*(comp[i].y-comp[j].y):dist[i][j];
}

void solve() {
	init_union_found();
	char op;
	int s, t;
	int cur, cnt=0;
	// cout << D << endl;
	// cout << d(1, 2) << endl;

	while(cin >> op) {
		if(op == 'S') {
			cin >> s >> t;
			// 判断是否连通
			if(same(s, t)) cout << "SUCCESS" << endl;
			else cout << "FAIL" << endl;
		}
		else {
			cin >> cur;
			// 和之前修过的电脑连接
			for(int i=0; i<cnt; ++i)
				d(repaired[i], cur) <= D && unite(repaired[i], cur); // cur和cnt容易写错。。
			repaired[cnt++] = cur;

			// for(int i=1; i<=N; ++i)
				// if(i!=cur && repaired[i] && d(i, cur) <= D)
					// unite(i, cur);
			// repaired[cur] = true;
		}
	}

}

int main()
{
#ifdef Oj
	freopen("2236.in", "r", stdin);
#endif
	cin.sync_with_stdio(false); // 30万行数据
	cin >> N >> D;
	D*=D; // 这里之前写成D<<=1了。。。
	memset(dist, -1, sizeof(dist));
	for(int i=1;i<=N;++i)
		cin >> comp[i].x >> comp[i].y;

	solve();
	return 0;
}
