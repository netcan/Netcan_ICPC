/*************************************************************************
	> File Name: 1166.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-18 一 15:11:49 CST
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
const int MAXN = 50000+5;
int T, N;
int data[MAXN];
int tree[MAXN<<1];

void build(int v, int l, int r) { // [l, r)，建树
	if(r - l == 1) {
		// printf("l: %d r: %d v:%d\n", l, r, v);
		tree[v] = data[l];
	}
	else {
		int chl = (v<<1)+1, chr = (v<<1)+2, m = (l + r) >> 1;
		build(chl, l, m);
		build(chr, m, r);
		tree[v] = tree[chl] + tree[chr];
	}
}

void update(int v, int l, int r, int k, int a) { // 第k个数据增加a，[l, r)
	if(k<l || k>=r) return;

	if(r-l == 1) { // 叶子节点
		tree[v] += a;
	}
	else {
		int chl = (v<<1)+1, chr = (v<<1)+2, m = (l + r) >> 1;
		if(k<m) update(chl, l, m, k, a);
		else update(chr, m, r, k, a);
		tree[v] = tree[chl] + tree[chr];
	}
}

int query(int v, int l, int r, int s, int e) { // 求第[s, e)的和，[l, r)
	if(l>=e || r<=s) return 0;
	if(l >= s && r <= e) return tree[v];
	int chl = (v<<1)+1, chr = (v<<1)+2, m = (l + r) >> 1;
	// printf("l: %d m:%d r: %d v:%d s:%d e: %d\n", l, m, r, v, s, e);
	int ans = 0;
	if(m >= s) ans += query(chl, l, m, s, e);
	if(m < e) ans += query(chr, m, r, s, e);
	return ans;
}

void solve() {
	// memset(tree, 0, sizeof(tree));
	build(0, 0, N);
	// cout << query(0, 0, N, 1, 3) << endl;

	char cmd[10];
	int a, b;
	while(scanf("%s", cmd) && cmd[0] != 'E') {
		// cout << cmd << endl;
		scanf("%d%d", &a, &b);
		if(cmd[0] == 'A')
			update(0, 0, N, a-1, b);
		else if(cmd[0] == 'S')
			update(0, 0, N, a-1, -b);
		else if(cmd[0] == 'Q')
			printf("%d\n", query(0, 0, N, a-1, b));
	}
}

int main()
{
#ifdef Oj
	freopen("1166.in", "r", stdin);
#endif
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		scanf("%d", &N);
		for(int i=0; i<N; ++i) scanf("%d", data+i);
		printf("Case %d:\n", t+1);
		solve();
	}
	return 0;
}
