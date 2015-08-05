/*************************************************************************
	> File Name: 1953.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-05 Wed 15:34:29 CST
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
long long int dp[50];

void solve() {
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 3;
	for(int n=3; n<=45; ++n)
		dp[n] = dp[n-1] + dp[n-2];
	int T;
	cin >> T;
	int n;
	int Case = 1;
	while(T--) {
		cin >> n;
		printf("Scenario #%d:\n%lld\n\n", Case++, dp[n]);
	}
}

int main()
{
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	solve();
	return 0;
}
