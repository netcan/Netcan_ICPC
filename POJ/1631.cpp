/*************************************************************************
	> File Name: 1631.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-10 Mon 14:27:25 CST
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

int dp[40002];
int num[40002];
void solve() {
	cin.sync_with_stdio(false);
	int T;
	cin >> T;
	int n;
	while(T--) {
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> num[i];
		memset(dp, 0x3f, sizeof(dp));
		for(int i=0; i<n; ++i)
			*lower_bound(dp, dp+n, num[i]) = num[i];
		cout << lower_bound(dp, dp+n, INF) - dp << endl;
	}
}

int main()
{
#ifdef Oj
	freopen("1631.in", "r", stdin);
#endif
	solve();
	return 0;
}
