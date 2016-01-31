/*************************************************************************
	> File Name: 2104_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-31 日 10:42:03 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 23;
vector<int> tree[MAXN<<2]; // 线段树每个节点保存一个数列，归并树
int A[MAXN];
int N, M;

void build(int k, int l, int r) {
	if(r - l == 1)  // 叶子节点
		tree[k].push_back(A[l]);
	else {
		int chl = (k<<1) + 1, chr = (k<<1) + 2, m = (l+r) >> 1;
		build(chl, l, m);
		build(chr, m, r);
		tree[k].resize(r - l);
		merge(tree[chl].begin(), tree[chl].end(), tree[chr].begin(), tree[chr].end(), tree[k].begin()); // STL::merge()大法好，归并函数
	}
}

int query(int k, int l, int r, int L, int R, int x) { // 查询[L, R)上<=x的个数
	if(R<=l || L>=r) return 0; // 无交集
	else if(L<=l && R>=r) // 完全包含
		return upper_bound(tree[k].begin(), tree[k].end(), x) - tree[k].begin();
	else {
		int chl = (k<<1) + 1, chr = (k<<1) + 2, m = (l+r) >> 1;
		return query(chl, l, m, L, R, x) + query(chr, m, r, L, R, x);
	}
}

void solve() {
	build(0, 0, N);
	sort(A, A+N);
	for (int i = 0; i < M; ++i) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		int lb = -1, ub = N-1; // (lb, ub]
		while(ub - lb > 1) {
			int mid = (lb + ub) >> 1;
			if(query(0, 0, N, l-1, r, A[mid]) >= k) ub = mid;
			else lb = mid;
		}
		printf("%d\n", A[ub]);
	}
}

int main() {
#ifdef Oj
	freopen("2104.in", "r", stdin);
	// freopen("2104_2.out", "w",stdout);
#endif
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", A+i);
	solve();
	return 0;
}
