/*************************************************************************
	> File Name: 2991.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-14 Thu 17:38:50 HKT
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int ST=1<<17;
const int MAXN = 10000 + 5;
const int MAXC = 10000 + 5;
const double PI = acos(-1);

int N, C;
int L[MAXN]; // 长度
int S[MAXC], A[MAXC]; // 操作线段，旋转角度

double vx[ST], vy[ST], angle[ST];
double prva[MAXN];

void init(int k, int l, int r) { // k节点编号，[l, r)
	angle[k] = vx[k] = 0;
	if(r - l == 1) vy[k] = L[l];
	else {
		int chl = (k<<1)+1, chr = (k<<1)+2, m = (l + r) >> 1;
		init(chl, l, m);
		init(chr, m, r);
		vy[k] = vy[chl] + vy[chr];
	}
}

void modify(int s, double a, int v, int l, int r) { // 后序
	if(s <= l) return;
	else if(s < r) {
		int chl = (v<<1)+1, chr = (v<<1)+2, m = (l + r) >> 1;
		modify(s, a, chl, l, m);
		modify(s, a, chr, m, r);
		if(s<=m) angle[v] += a;

		double sins = sin(angle[v]), coss = cos(angle[v]);
		vx[v] = vx[chl] + coss * vx[chr] - sins * vy[chr];
		vy[v] = vy[chl] + sins * vx[chr] + coss * vy[chr];
	}
}

void solve() {
	init(0, 0, N);
	// for(int i=0; i<N+1; ++i) printf("vy[%d]=%f\n", i, vy[i]);

	for(int i=1; i<N; ++i) prva[i] = PI;
	for(int i=0; i<C; ++i) {
		int s = S[i];
		double a = A[i] * PI / 180.0;
		// printf("s=%d a=%f\n", s, a);
		modify(s, a-prva[s], 0, 0, N);
		prva[s] = a;
		printf("%.2f %.2f\n", vx[0], vy[0]); // [0,N)
	}

}

int main() {
#ifdef Oj
	freopen("2991.in", "r", stdin);
	// freopen("2991.out", "w", stdout);
#endif
	cin.sync_with_stdio(false);
	while(cin >> N >> C) {
		for(int i=0; i<N; ++i) cin >> L[i];
		for(int i=0; i<C; ++i) cin >> S[i] >> A[i];
		solve();
		printf("\n");
	}
	return 0;
}
