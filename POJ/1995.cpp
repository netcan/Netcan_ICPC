/*************************************************************************
	> File Name: 1995.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-21 一 09:23:08 CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <stack>
#include <set>
#include <numeric>
#include <utility>
#include <cstring>
using namespace std;

typedef long long ll;
int H, M;
ll A[45005], B[45005];

ll mod_pow(ll x, ll n, ll mod) {
	ll ret = 1;
	while(n) {
		if(n & 1)  ret = (ret * x) % mod;
		x = x*x%mod;
		n >>= 1;
	}
	return ret;
}

void solve() {
	ll ans = 0;
	for(int i=0; i<H; ++i) ans += mod_pow(A[i], B[i], M);
	ans %= M;
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("1995.in", "r", stdin);
#endif
	int Z;
	cin >> Z;
	while(Z--) {
		cin >> M >> H;
		for(int i=0; i<H; ++i)
			cin >> A[i] >> B[i];
		solve();
	}
	return 0;
}
