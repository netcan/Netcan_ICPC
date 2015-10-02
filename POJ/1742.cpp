/*************************************************************************
	> File Name: 1742.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-02 五 09:25:59 CST
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

int n, m;
int A[102], C[102];
int dp[100005];

void solve() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<=m; ++j) {
			if(dp[j] >= 0) dp[j] = C[i];
			else if(j < A[i] || dp[j-A[i]] <= 0) dp[j] = -1;
			else dp[j] = dp[j-A[i]] - 1;
		}
	}
	// cout << count_if(dp+1, dp + m+1, bind2nd(greater_equal<int>(), 0)) << endl;
	int ans = 0;
	for(int j=1; j<=m; ++j) if(dp[j] >= 0) ++ans;
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("1742.in", "r", stdin);
#endif
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		for(int i=0; i<n; ++i) cin >> A[i];
		for(int i=0; i<n; ++i) cin >> C[i];
		solve();
	}
	return 0;
}
