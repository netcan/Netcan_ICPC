/*************************************************************************
	> File Name: 3468_3.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-24 日 11:12:19 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100000+5;
typedef long long ll;
int A[MAXN];
ll bit0[MAXN], bit1[MAXN];
int N, Q;

void add(ll *bit, int i, int x) {
	while(i<=N) {
		bit[i] += x;
		i += i&-i;
	}
}

ll sum(ll *bit, int i) {
	ll res = 0;
	while(i) {
		res += bit[i];
		i -= i&-i;
	}
	return res;
}


void solve() {
	for (int i = 1; i <= N; ++i) add(bit0, i, A[i]);
	char op;
	int a, b, c;
	for (int i = 0; i < Q; ++i) {
		getchar();
		scanf("%c%d%d", &op, &a, &b);
		if(op == 'C') { // [a,b]区间+c
			scanf("%d", &c);
			add(bit0, a, -c*(a-1));
			add(bit1, a, c); // c*a-c*(a-1) = +c
			add(bit0, b+1, c*b);
			add(bit1, b+1, -c);
		}
		else {
			ll ans = (sum(bit0, b) + b*sum(bit1, b)) - (sum(bit0, a-1) + (a-1)*sum(bit1, a-1));
			printf("%lld\n", ans);
		}
	}

}

int main() {
#ifdef Oj
	freopen("3468.in", "r", stdin);
	// freopen("3468_3.out", "w",stdout);
#endif
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	solve();
	return 0;
}
