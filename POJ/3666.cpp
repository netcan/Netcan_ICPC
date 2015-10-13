/*************************************************************************
	> File Name: 3666.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-13 二 21:07:39 CST
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
int n;
int data[2005];
int des[2005];
int dp[2005][2005]; // 前i个数变成单调且最后一个数是des[j]

void solve() {
	memcpy(des, data, sizeof(data));
	sort(des, des+n);
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; ++i) dp[0][i] = abs(data[0]-des[i]);

	for(int i=1; i<n; ++i) {
		int mincost = dp[i][0];
		for(int j=0; j<n; ++j) {
			mincost = min(mincost, dp[i][j]);
			dp[i+1][j] = mincost + abs(data[i]-des[j]);
		}
	}
	cout << *min_element(dp[n], dp[n]+n) << endl;

}

int main()
{
#ifdef Oj
	freopen("3666.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; ++i) cin >> data[i];
	solve();
	return 0;
}
