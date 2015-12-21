/*************************************************************************
	> File Name: 3641.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-21 一 08:52:02 CST
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

ll a, p;

ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n&1) res = (res*x) % mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

ll is_prime(ll x) {
	if(x < 2) return false;
	if(x == 2) return true;
	for(ll i=3; i*i<=x; i+=2) if(x%i==0) return false;
	return true;
}

void solve() {
	if(is_prime(p)) {
		cout << "no" << endl;
		return;
	}
	cout << (mod_pow(a, p, p) == a?"yes":"no") << endl;
}

int main()
{
#ifdef Oj
	freopen("3641.in", "r", stdin);
#endif
	while(cin >> p >> a) {
		if(a==0 && p == 0) break;
		solve();
	}
	return 0;
}
