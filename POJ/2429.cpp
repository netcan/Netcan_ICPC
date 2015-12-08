/*************************************************************************
	> File Name: 2429.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-07 一 21:11:13 CST
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
ll GCD, LCM;

ll mod_mult(ll a, ll b, ll mod) { // return	a*b%mod
	ll s = 0;
	while(b) {
		if(b&1) s=(s+a)%mod;
		a<<=1, b>>=1;
		if(a > mod) a -= mod;
	}
	return s;
}

ll mod_pow(ll x, ll n, ll mod) { // return a^b%mod
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
map<ll, int> factors; // 质因数分解结果（无序，每个质因子的n次方）

inline ll gcd(ll a, ll b) {
    return b==0?a:gcd(b, a%b);
}

ll Pollard_rho(ll n, ll c) { // 伪随机函数f(x)=x^2+c，c为随机数
    ll i=1, k=2;
    ll x=rand()%n;
    ll y = x;
    while(1) {
        ++i;
        x=(mod_mult(x, x, n)+c)%n; // 伪随机数
        ll d = gcd(y-x+n, n); // gcd注意负数
        if(d!=1 && d!=n) return d;
        if(y==x) return n; // 遇环退出
        if(i==k) {y=x; k<<=1;}
    }
}

// 对n进行递归素因子分解
void findfac(ll n) {
    if(Miller_Rabin(n, 20)) { // 素数
		++factors[n]; // 储存素因子，用map后面方便处理
        return;
    }
    ll p = n;
    while(p>=n) p = Pollard_rho(p, rand()%(n-1)+1); // 找出当前合数的一个素因子
    findfac(p);
    findfac(n/p);
}

void dfs(const vector<ll> &nf,const ll d, int i, ll& sum,  ll x, ll &a) { // 搜索最小的a+b，x为当前搜索的a，sum为储存最小和，a为最终答案
	if(i >= nf.size()) return;
	if(sum > d/x+x) { // 更新最小和
		a=x;
		sum = d/x+x;
	}
	dfs(nf, d, i+1, sum, x, a); // 不选nf[i]并搜索
	x*=nf[i]; // 选择nf[i]并搜索
	if(sum > d/x+x) { // 更新最小和
		a = x;
		sum = d/x+x;
	}
	dfs(nf, d, i+1, sum, x, a); // 这是选择nf[i]的情况
}

void solve() {
	factors.clear();
	vector<ll> nfactors; // 最终因子
	ll d = LCM/GCD; // (a/gcd)(b/gcd)=lcm/gcd，然后分解d，求出最终的(a/gcd), (b/gcd)
	if(d==1) {
		printf("%lld %lld\n", GCD, LCM);
		return;
	}
	findfac(d);

	for(map<ll, int>::iterator i = factors.begin(); i!=factors.end(); ++i)
		nfactors.push_back(mod_pow(i->first, i->second, (1ll<<63)-1)); // 对相同的质因子进行合并

	// for(vector<ll>::iterator i=nfactors.begin(); i!=nfactors.end(); ++i) {
		// printf("%lld ", *i);
	// }
	// cout << endl;
	ll a = 1;
	ll sum = a+d/a;
	dfs(nfactors, d, 0, sum, a, a);

	// for(int i=0; i<(1<<nfactors.size()); ++i) {
		// ll aa = 1;
		// for(int j=0; j<nfactors.size(); ++j) // 神奇的搜索。。。
			// if(i & (1<<j)) aa*=nfactors[j];

		// if(d/aa + aa < min_sum) {
			// min_sum = d/aa + aa;
			// a = aa;
		// }
	// }
	a = min(a, d/a);

	printf("%lld %lld\n", a*GCD, d/a*GCD);
}

int main()
{
#ifdef Oj
	freopen("2429.in", "r", stdin);
#endif
	while(cin >> GCD >> LCM) {
		solve();
	}
	return 0;
}
