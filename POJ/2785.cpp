/*************************************************************************
	> File Name: 2785.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-05 二 14:15:53 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 4000 + 5;
ll A[MAXN], B[MAXN], C[MAXN], D[MAXN];
ll sum[MAXN * MAXN];
int N;

void solve() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) sum[i*N + j] = A[i] + B[j];
	// for(int i=0; i<N*N; ++i) printf("%d: %lld\n", i, sum[i]);
	sort(sum, sum+N*N);
	ll res = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			int s = C[i] + D[j];
			res += upper_bound(sum, sum+N*N, -s) - lower_bound(sum, sum+N*N, -s); // 累加相同数字个数。
		}
	cout << res << endl;
}

int main() {
#ifdef Oj
	freopen("2785.in", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i] >> B[i] >> C[i] >> D[i];
	solve();
	return 0;
}
