/*************************************************************************
	> File Name: 3421.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-13 日 17:10:30 CST
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

ll mod_mult(ll a, ll b, ll mod) {
	ll s=0;
	while(b) {
		if(b&1) s = (s+a) % mod;
		a <<= 1, b>>=1;
		if(a > mod) a-=mod;
	}
	return s;
}

ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n&1) res = mod_mult(res, x, mod);
		x = mod_mult(x, x, mod);
		n >>= 1;
	}
	return res;
}

bool witness(ll a, ll n, ll u, ll t) {
	ll ret = mod_pow(a, u, n);
	ll last = ret;
	for(int i=1; i<=t; ++i) {
		ret = mod_mult(ret, ret, n);
		if(ret == 1 && last != 1 && last != n-1) return true;
		last = ret;
	}
	if(ret != 1) return true;
	return false;
}

bool Miller_Rabin(ll n, int s) {
	if(n == 2) return true;
	if(n<2 || !(n&1)) return false;
	ll u = n-1;
	ll t=0;
	while(!(u&1)) { u >>=1; ++t;}
	for(int i=0; i<s; ++i) {
		ll a=rand()%(n-1)+1;
		if(witness(a, n, u, t)) return false;
	}
	return true;
}

map<ll, int> factors;

ll gcd(ll a, ll b) {
	return b==0?a:gcd(b, a%b);
}

ll Pollard_rho(ll n, ll c) {
	ll i=1, k=2;
	ll x=rand()%n;
	ll y=x;
	while(1) {
		++i;
		x=(mod_mult(x, x, n)+c)%n;
		ll d=gcd(y-x+n, n);
		if(d!=1 && d!=n) return d;
		if(y==x) return n;
		if(i == k) {y=x; k<<=1;}
	}
}

void findfac(ll n) {
	if(Miller_Rabin(n, 5)) {
		// factors.push_back(n);
		++factors[n];
		return;
	}
	ll p = n;
	while(p >= n) p=Pollard_rho(p, rand()%(n-1)+1);
	findfac(p);
	findfac(n/p);
}

ll N;
ll factorial[22];

void solve() {
	factors.clear();
	findfac(N); // Pollard_rho分解质因数
	// for(map<ll,int>::iterator i=factors.begin(); i!=factors.end(); ++i)
		// printf("%lld^%d ", i->first, i->second);
	// cout << endl;
	int n = 0;
	ll c = 1;
	for(map<ll,int>::iterator i=factors.begin(); i!=factors.end(); ++i) {
		n+=i->second;
		c*=factorial[i->second];
	}
	printf("%d %lld\n", n, factorial[n]/c); // 总素因子个数，以及总素因子个数的阶乘除以各个素因子个数的阶乘就是答案
}

int main()
{
#ifdef Oj
	freopen("3421.in", "r", stdin);
#endif
	factorial[1] = 1;
	factorial[0] = 1;
	for(int i=2; i<=20; ++i) factorial[i] = factorial[i-1]*i;
	while(cin >> N) {
		solve();
	}
	return 0;
}
