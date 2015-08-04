/*************************************************************************
	> File Name: 2081.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-04 Tue 16:40:21 CST
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

int dp[500005];
bool vis[5000005];

void solve() {
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	dp[0] = 0;
	for(int k= 1; k <= 500000; ++k) {
		dp[k] = dp[k-1] - k;
		if(dp[k] <=0 || vis[dp[k]])
			dp[k] = dp[k-1] + k;
		vis[dp[k]] = true;
	}
	int k;
	// for(int i=0; i<=10; ++i)
		// printf("%d ", dp[i]);
	// cout << endl;
	while(cin >> k && k!=-1)
		cout << dp[k] << endl;

}

int main()
{
#ifdef Oj
	freopen("2081.in", "r", stdin);
#endif
	solve();
	return 0;
}
