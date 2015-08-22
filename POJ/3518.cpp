/*************************************************************************
	> File Name: 3518.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-22 六 14:55:57 CST
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

bool is_prime[1299759];
int prime[100055];

int sieve(int n) {
	int p=0;
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i=2; i<=n; ++i) {
		if(is_prime[i]) {
			prime[p++] = i;
			for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
		}
	}
	return p;
}


void solve() {
	int n;
	sieve(1299709);
	while(cin >> n && n) {
		if(is_prime[n]) {
			cout << 0 << endl;
			continue;
		}
		int l, r;
		for(l=n; !is_prime[l]; --l);
		for(r=n; !is_prime[r]; ++r);
		cout << r-l << endl;

	}

}

int main()
{
#ifdef Oj
	freopen("3518.in", "r", stdin);
#endif
	solve();
	return 0;
}
