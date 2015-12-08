/*************************************************************************
	> File Name: 1930.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-08 二 20:43:29 CST
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
#include <limits>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b==0?a:gcd(b, a%b);
}
ll pow_10(int n) {
	ll s=1;
	for(int i=0; i<n; ++i) s*=10;
	return s;
}

string n;
void solve() {
	n.erase(0, 2);
	n.erase(n.length()-3, 3);
	if(atoi(n.c_str()) == 0) {
		puts("0/1");
		return;
	}

	ll x=0, y=1;
	ll min_x = 0, min_y = numeric_limits<ll>::max();
	// cout << string("2333").substr(0, 2) << endl;

	for(int i=n.length(); i>=1; --i) {
		x = atoi(n.c_str()) - atoi(n.substr(0, i-1).c_str());
		y = ll(pow_10(n.length())) - ll(pow_10(i-1));
		// printf("%lld/%lld\n", x, y);
		ll Gcd = gcd(x, y);
		x/=Gcd;
		y/=Gcd;
		if(y<min_y) {
			min_y = y;
			min_x = x;
		}
	}
	printf("%lld/%lld\n", min_x, min_y);
}

int main()
{
#ifdef Oj
	freopen("1930.in", "r", stdin);
#endif
	while(cin >> n) {
		if(n=="0") break;
		solve();
	}
	return 0;
}
