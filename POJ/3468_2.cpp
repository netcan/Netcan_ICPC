/*************************************************************************
	> File Name: 3468_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-24 日 09:48:20 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000+5;
const int DAT_SIZE = (1<<18) - 1;
int N, Q;
int A[MAXN];
ll data[MAXN << 2], datb [MAXN<<2]; // 增量data，除去data外的和datb

void add(int v, int l, int r, int L, int R, int a) { // 对区间[L,R)同时加上a
	if(R<=l || L>=r) return;
	else if(l>=L && r <= R) data[v] += a; // 包含，增量
	else { // 交集
		datb[v] += (min(R, r) - max(L, l))*a; // datb
		int chl = (v<<1)+1, chr=(v<<1)+2, m = (l+r)>>1;
		add(chl, l, m, L, R, a);
		add(chr, m, r, L, R, a);
	}

}

ll query(int v, int l, int r, int L, int R) { // 查询[L, R)上的和
	if(R<=l || L>=r) return 0;
	else if(l>=L && r<=R) return datb[v]+(r-l)*data[v]; // datb+增量
	else {
		ll res = (min(R, r) - max(L, l))*data[v]; // 增量
		int chl = (v<<1)+1, chr=(v<<1)+2, m = (l+r)>>1;
		res += query(chl, l, m, L, R);
		res += query(chr, m, r, L, R);
		return res;
	}
}


void solve() {
	char op;
	int a, b, c;
	for(int i=0; i<N; ++i) add(0, 0, N, i, i+1, A[i]);

	for(int i=0; i<Q; ++i) {
		getchar();
		scanf("%c%d%d", &op, &a, &b);
		if(op == 'Q') printf("%lld\n", query(0, 0, N, a-1, b));
		else {
			scanf("%d", &c);
			add(0, 0, N, a-1, b, c);
		}
	}

}

int main() {
#ifdef Oj
	freopen("3468.in", "r", stdin);
	// freopen("3468_2.out", "w",stdout);
#endif
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	solve();
	return 0;
}
