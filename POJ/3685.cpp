/*************************************************************************
	> File Name: 3685.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-27 日 14:28:01 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MAX = 1e15;
ll T;
ll N, M;
ll f(ll i, ll j) {
	return i*i + 100000*(i-j) + i*j + j*j;
}

bool C(ll x) { // 验证x是否过小。。。。这里写成int x调了好久= =
	ll cnt = 0; // cnt 为<x的个数
	for(int j=1; j<=N; ++j) {
		int lb = 0, ub = N+1; // (lb, ub)
		while(ub - lb > 1) {
			int mid = (lb + ub) >> 1;
			if(f(mid, j) < x) lb = mid; // 半闭半开区间[lb, ub)
			else ub = mid;
		 }
		// printf("%d\n", lb);
		cnt += lb;
	}
	// printf("%d\n", cnt);
	return cnt < M;
	// return cnt;
}

void solve() {
	ll lb  = f(0, N), ub = f(N,0)+1;
	while(ub - lb > 1) {
		ll mid = (ub + lb) >> 1;
		// printf("f(%lld)= ", mid);
		if(C(mid)) lb = mid; // 半闭半开区间[lb, ub)
		else ub = mid;
	}
	cout << lb << endl;
}

int main() {
#ifdef Oj
	freopen("3685.in", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		cin >> N >> M;
		solve();
	}
	return 0;
}
