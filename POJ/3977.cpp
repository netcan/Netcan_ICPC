/*************************************************************************
	> File Name: 3977.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-05 二 16:21:31 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits>

using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const int MAXN = 40;
const int INF = numeric_limits<int>::max();
int N;
ll data[MAXN];
P ps[1<<(MAXN>>1)];

ll Abs(ll x) {
	return x > 0 ? x : -x;
}

void solve() {
	// 枚举前半部分
	P ans(Abs(data[0]), 1);
	int n1 = N >> 1;
	for(int i=0; i<1<<n1; ++i) {
		ll sum = 0;
		int cnt = 0;
		for(int j=0; j<n1; ++j)
			if(i >> j & 1) {
				sum += data[j];
				++cnt;
			}
		ps[i] = P(sum, cnt);
		if(cnt > 0) ans = min(ans, P(Abs(sum), cnt));
	}
	sort(ps, ps+(1<<n1));
	// for(int i=0; i<1<<n1; ++i)
		// printf("(%lld, %d)\n", ps[i].first, ps[i].second);
	// printf("======\n");
	// 去掉多余元素
	int m = 1;
	for(int i=1; i<1<<n1; ++i)
		if(ps[m-1].first < ps[i].first) ps[m++] = ps[i];



	// printf("n1:%d\n", n1);
	for(int i=0; i<1<<(N-n1); ++i) { // 剩下部分
		ll sum = 0;
		int cnt = 0;
		for(int j=0; j<(N-n1); ++j) {
			if(i>>j & 1) {
				sum+= data[n1+j];
				++cnt;
			}
		}
		// printf("sum: %lld\n", sum);
		if(cnt > 0) ans = min(ans, P(Abs(sum), cnt));

		P *f = lower_bound(ps, ps+m, P(-sum, -1));
		if(f < ps+m)
		if(f->second + cnt > 0) ans = min(ans, P(Abs(f->first+sum), f->second+cnt));

		if(f > ps) {
			--f;
			if(f->second + cnt > 0) ans = min(ans, P(Abs(f->first+sum), f->second+cnt));
		}
	}
	printf("%lld %d\n", ans.first, ans.second);
}

int main() {
#ifdef Oj
	freopen("3977.in", "r", stdin);
	// freopen("3977.out", "w", stdout);
#endif
	while(scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++i) scanf("%lld", data+i);
		solve();
	}
	return 0;
}
