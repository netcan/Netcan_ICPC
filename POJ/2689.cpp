/*************************************************************************
	> File Name: 2689.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-22 六 15:19:27 CST
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
const int MAX_L = 1000005;
const int MAX_SQRT_B = 47000;
bool is_prime[MAX_L]; // is_prime[i-a] == true表示i是素数
bool is_prime_small[MAX_SQRT_B];

void segment_sieve(ll a, ll b) {
	memset(is_prime, true, sizeof(is_prime));
	memset(is_prime_small, true, sizeof(is_prime_small));
	if(a == 1) is_prime[0] = false;

	for(int i=2; (ll)i*i <= b; ++i) {
		if(is_prime_small[i]) {
			for(int j=2*i; (ll)j*j <= b; j+=i) is_prime_small[j] = false;
			for(ll j = max(2LL, (a+i-1)/i)*i; j<=b; j+=i) is_prime[j-a] = false;
		}
	}
}



void solve() {
	ll a, b;
	while(cin >> a >> b) {
		segment_sieve(a, b);
		ll minl = 1<<30, maxl = 0;
		ll mina = -1, minb = -1, maxa = -1, maxb = -1;
		ll lastprime = -1;

		for(ll i=a; i<=b; ++i) {
			if(is_prime[i-a]) {
				if(lastprime == -1) {
					lastprime = i;
					continue;
				}

				if(minl > i - lastprime) {
					mina = lastprime;
					minb = i;
					minl = i - lastprime;
				}
				if(maxl < i-lastprime) {
					maxl = i - lastprime;
					maxb = i;
					maxa = lastprime;
				}
				lastprime = i;
			}
		}
		if(mina == -1 || minb == -1 || maxa == -1 || maxb == -1)
			puts("There are no adjacent primes.");
		else
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", mina, minb, maxa, maxb);
	}
}

int main()
{
#ifdef Oj
	freopen("2689.in", "r", stdin);
#endif
	solve();
	return 0;
}
