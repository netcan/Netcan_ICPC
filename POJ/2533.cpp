/*************************************************************************
	> File Name: 2533.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-09 日 15:31:55 CST
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
#define INF 0x3f3f3f3f
int dp[1002];
int a[1002];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	memset(dp, 0x3f, sizeof(dp));

	for (int i = 0; i < n; ++i)
		*lower_bound(dp, dp+n, a[i]) = a[i];

	cout << lower_bound(dp, dp+n, INF) - dp << endl;
}

int main()
{
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	solve();
	return 0;
}
