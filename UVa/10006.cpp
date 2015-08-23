/*************************************************************************
	> File Name: 10006.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-23 日 15:23:03 CST
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
ll mod_pow(ll x, ll n, ll mod) {
	if(n == 0) return 1;
	ll res = mod_pow(x * x % mod, n/2, mod);
	if(n & 1) res = res * x % mod;
	return res;
}

void solve() {
	ll n;
	while(cin >> n && n) {
		ll a;
		bool flag = true;
		for(int i=2; i*i<=n; ++i) {
			if(n % i == 0) {
				flag =  false;
				break;
			}
		}
		if(flag) {
			printf("%lld is normal.\n", n);
			continue;
		}

		for(a = 2; a<n; ++a) {
			if(mod_pow(a, n, n) != a)
				break;
		}
		if(a >= n)
			printf("The number %lld is a Carmichael number.\n", n);
		else
			printf("%lld is normal.\n", n);

	}

}

int main()
{
#ifdef Oj
	freopen("10006.in", "r", stdin);
#endif
	solve();
	return 0;
}
