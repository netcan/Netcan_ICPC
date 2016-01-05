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
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const int MAXN = 40;
const int INF = numeric_limits<int>::max();
int N;
ll data[MAXN];
map<ll, int> ps;

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
		if(ps.find(sum) != ps.end())
			ps[sum] = min(ps[sum], cnt);
		else ps[sum] = cnt;
		if(cnt != 0) ans = min(ans, P(Abs(sum), cnt));
	}

	// for(int i=0; i<m; ++i)
		// printf("(%lld, %d)\n", ps[i].first, ps[i].second);


	// printf("n1:%d\n", n1);
	for(int i=0; i<1<<(N-n1); ++i) { // 剩下部分
		ll sum = 0;
		int cnt = 0;
		P res(0, 0);
		for(int j=0; j<(N-n1); ++j) {
			if(i>>j & 1) {
				sum+= data[n1+j];
				++cnt;
			}
		}
		// printf("sum: %lld\n", sum);
		res = P(Abs(sum), cnt);
		if(ans > res && res.second != 0) ans = res;
		map<ll, int>::iterator f = ps.lower_bound(-sum);
		if(f!=ps.end()) {
			res = P(Abs(sum + f->first), f->second + cnt);
			if(ans > res && res.second != 0) ans = res;
		}
		if(f!=ps.begin()) {
			--f;
			res = P(Abs(sum + f->first), f->second + cnt);
			if(ans > res && res.second != 0) ans = res;
		}
	}
	cout << ans.first << ' ' << ans.second << endl;
}

int main() {
#ifdef Oj
	freopen("3977.in", "r", stdin);
	// freopen("3977.out", "w", stdout);
#endif
	while(cin >> N && N) {
		ps.clear();
		for (int i = 0; i < N; ++i) cin >> data[i];
		solve();
	}
	return 0;
}
