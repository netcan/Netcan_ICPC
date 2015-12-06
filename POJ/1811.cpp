/*************************************************************************
	> File Name: 1811.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-05 六 14:27:28 CST
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

ll mod_mult(ll a, ll b, ll mod) { //return a*b%mod
	ll s = 0;
	while(b) {
		if(b&1) s=(s+a)%mod;
		a<<=1, b>>=1;
		if(a > mod) a %= mod;
	}
	return s;
}

ll mod_pow(ll x, ll n, ll mod) {  // a^b%mod
	ll res = 1;
	while(n) {
		if(n&1) res = mod_mult(res, x, mod);
		x=mod_mult(x, x, mod);
		n>>=1;
	}
	return res;
}

//以a为基,n-1=u*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool witness(ll a, ll n, ll u, ll t) { // a随机数，u, t于外部计算
	ll ret = mod_pow(a, u, n);
	ll last = ret;
	for(int i=1; i<=t; ++i) {
		ret = mod_mult(ret, ret, n);
		if(ret == 1 && last != 1 && last != n-1) return true;
		last = ret;
	}
	if(ret!=1) return true; // a^(n-1)!=1(mod n)
	return false;
}

// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小，P=(1/2)^s)
//合数返回false;
// s:挑选s个随机数
bool Miller_Rabin(ll n, int s) {
	if(n==2) return true;
	if(n < 2 || !(n&1)) return false;
	ll u=n-1;
	ll t=0;
	while(!(u&1)) {u>>=1; ++t;} // 2^t*u = n-1
	for(int i=0; i<s; ++i) {
		ll a=rand()%(n-1)+1; // 若n为合数，证据为a的概率至少为1/2
		if(witness(a, n, u, t)) return false; // 合数
	}
	return true;
}

//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
vector<ll> factors; // 质因数分解结果（无序）

inline ll gcd(ll a, ll b) {
	return b==0?a:gcd(b, a%b);
}

ll Pollard_rho(ll n, ll c) {
	ll i=1, k=2;
	ll x=rand()%n;
	ll y = x;
	while(1) {
		++i;
		x=(mod_mult(x, x, n)+c)%n; // 伪随机数
		ll d = gcd(y-x+n, n); // gcd注意负数
		if(d!=1 && d!=n) return d;
		if(y==x) return n;
		if(i==k) {y=x; k<<=1;}
	}
}

// 对n进行素因子分解
void findfac(ll n) {
	if(Miller_Rabin(n, 20)) { // 素数
		factors.push_back(n);
		return;
	}
	ll p = n;
	while(p>=n) p = Pollard_rho(p, rand()%(n-1)+1);
	findfac(p);
	findfac(n/p);
}



int T;
ll N;

void solve() {
	if(Miller_Rabin(N, 20)) {
		cout << "Prime" << endl;
	}
	else {
		factors.clear();
		findfac(N);
		cout << *min_element(factors.begin(), factors.end()) << endl;
	}
	// cout << "因子：\n";
	// for(vector<ll>::iterator i=factors.begin(); i!=factors.end(); ++i) {
		// printf("%lld ", *i);
	// }
	// cout <<endl;
}

int main()
{
#ifdef Oj
	freopen("1811.in", "r", stdin);
#endif
	cin >> T;
	while(T--) {
		cin >> N;
		solve();
	}
	return 0;
}
