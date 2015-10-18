/*************************************************************************
	> File Name: 2844_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-18 日 20:39:58 CST
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

int dp[100000+5]; // 小于dp[j]的最大价值
int A[102];
int C[102];
int n, m;

void solve() {
	memset(dp, 0, sizeof(dp));

	// for(int i=0; i<n; ++i) {
		// for(int j=0; j<C[i]; ++j)
			// for(int k=m; k>=A[i]; --k)
				// dp[k] = max(dp[k], dp[k-A[i]]+A[i]);
	// }

	for(int i=0; i<n; ++i) {
		int num = C[i];
		for(int j=1; j<=num; j*=2) {
			for(int k=m; k>=j*A[i]; --k)
				dp[k] = max(dp[k], dp[k-j*A[i]] + j*A[i]);
			num -= j;
		}
		if(num)
			for(int k=m; k>=num*A[i]; --k)
				dp[k] = max(dp[k], dp[k-num*A[i]] + num*A[i]);

	}

	int ans = 0;
	for(int i=1; i<=m; ++i) {
		if(dp[i] == i) ++ans;
	}

	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("2844.in", "r", stdin);
#endif
	while(scanf("%d%d", &n, &m) == 2) {
		if(n == m && m == 0) break;
		for(int i=0; i<n; ++i) scanf("%d", &A[i]);
		for(int i=0; i<n; ++i) scanf("%d", &C[i]);
		solve();
	}
	return 0;
}
