/*************************************************************************
	> File Name: 081AA.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-23 日 16:06:38 CST
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
// Minimum Scalar Product

typedef long long ll;
vector<ll> x, y;

void solve() {
	int T;
	int Case = 1;
	cin >> T;
	int n;
	while(cin >> n) {
		int num;
		for(int i=0; i<n; ++i) {
			cin >> num;
			x.push_back(num);
		}
		for(int i=0; i<n; ++i) {
			cin >> num;
			y.push_back(num);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		ll sp = 0;
		for(int i=0; i<n; ++i) {
			sp += x.at(i)*y.at(n-1-i);
		}
		printf("Case #%d: %lld\n", Case++, sp);
		x.clear();
		y.clear();
	}
}

int main()
{
#ifdef Oj
	freopen("081AA.in", "r", stdin);
#endif
	solve();
	return 0;
}
