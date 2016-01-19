/*************************************************************************
	> File Name: 1754.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-19 二 10:04:09 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;
const int MAXN = 2000000+5;
int data[MAXN];
int tree[MAXN << 1];
int N, M;
void build(int v, int l, int r) { // v树节点，[l, r)
	if(r - l == 1) {
		// printf("l:%d v:%d\n", l, v);
		tree[v] = data[l];
		return;
	}
	int chl = (v<<1)+1, chr = (v<<1)+2, m = (l+r) >> 1;
	build(chl, l, m);
	build(chr, m, r);
	tree[v] = max(tree[chl], tree[chr]);
}

void update(int v, int l, int r, int k, int a) { // 将k节点的数值更新为a
	// printf("v:%d l:%d r:%d k:%d a:%d\n", v, l, r, k, a);
	if(r - l == 1) {
		tree[v] = a;
	}
	else {
		int chl = (v<<1)+1, chr = (v<<1)+2, m = (l+r) >> 1;
		if(k < m) update(chl, l, m, k, a);
		else update(chr, m, r, k, a);
		tree[v] = max(tree[chl], tree[chr]);
	}
}

int query(int v, int l, int r, int L, int R) { // 查询[L, R)上的最大值
	if(L>=r || R<=l) return numeric_limits<int>::min();
	if(l>=L && r<=R) return tree[v];
	int chl = (v<<1)+1, chr = (v<<1)+2, m = (l+r) >> 1;
	int res = numeric_limits<int>::min();
	if(m>=L) res=max(res, query(chl, l, m, L, R)); // 左半部分还有
	if(m<=R) res=max(res, query(chr, m, r, L, R)); // 有半部分也有
	return res;
}


void solve() {
	build(0, 0, N);
	char op;
	int a, b;
	for(int i=0; i<M; ++i) {
		cin >> op >> a >> b;
		if(op == 'Q') cout << query(0, 0, N, a-1, b) << endl;
		if(op == 'U') update(0, 0, N, a-1, b);
	}

}

int main() {
#ifdef Oj
	freopen("1754.in", "r", stdin);
	// freopen("1754.out", "w",stdout);
#endif
	cin.sync_with_stdio(false);
	while(cin >> N >> M) {
		for (int i = 0; i < N; ++i) cin >> data[i];
		solve();
	}
	return 0;
}
