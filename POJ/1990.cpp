/*************************************************************************
	> File Name: 1990.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-24 日 18:35:43 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 20000+5;
typedef long long ll;
int N;
pair<int, int> cows[MAXN]; // first:v, second:x
ll cnt[MAXN], X[MAXN]; // 下标为坐标，分别维护牛左右两边的数量和坐标。

void add(ll *bit, int i, int x) {
	while(i<=MAXN) {
		bit[i] += x;
		i += i&-i;
	}
}
ll sum(ll *bit, int i) {
	ll res = 0;
	while(i > 0) {
		res += bit[i];
		i -= i&-i;
	}
	return res;
}

void solve() {
	sort(cows, cows+N, less<pair<int,int> >()); // 按照v从小到大的顺序处理，这样每次的v就是最大的了。
	ll ans = 0;
	for(int i=0; i<N; ++i) {
		int v = cows[i].first, x = cows[i].second; // 从第一头牛开始处理
		int lcnt = sum(cnt, x) - sum(cnt, 0); // 左边[1, x]范围内的牛的数量
		int rcnt = sum(cnt, MAXN-1) - sum(cnt, x); // 右边(x, MAXN)范围的牛的数量
		ll lx = sum(X, x) - sum(X, 0); // 左边[1,x]范围的牛的累计坐标
		ll rx = sum(X, MAXN-1) - sum(X, x); // 右边(x, MAXN)范围的牛的累计坐标
		// printf("lcnt:%d rcnt:%d lx:%lld rx:%lld v:%d x:%d ", lcnt, rcnt, lx, rx, v, x);
		// printf("lxs:%lld rxx:%lld\n", x*lcnt - lx, rx - x*rcnt);
		ans += v*(x*lcnt - lx + rx - x*rcnt);
		add(cnt, x, 1); // 标记当前牛，以计数用
		add(X, x, x); // 标记当前牛位置，统计距离用
	}
	cout << ans << endl;
}

int main() {
#ifdef Oj
	freopen("1990.in", "r", stdin);
	// freopen("1990.out", "w",stdout);
#endif
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> cows[i].first >> cows[i].second; //v, x
	solve();
	return 0;
}
