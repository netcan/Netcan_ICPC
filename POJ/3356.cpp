/*************************************************************************
	> File Name: 3356.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-07 Fri 15:08:49 CST
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

int dp[1002][1002]; // a到b的最小步骤
void solve() {
	int N;
	string a, b;
	cin >> N >> a;
	cin >> N >> b;
	dp[0][0] = 0;
	for(int i=0; i<a.length(); ++i)
		dp[i+1][0] = i+1;
	for(int i=0; i<b.length(); ++i)
		dp[0][i+1] = i+1;
	for(int i=0; i<a.length(); ++i) {
		for(int j=0; j<b.length(); ++j) {
			if(a[i] == b[j])
				dp[i+1][j+1] = min(min(dp[i][j+1] + 1, dp[i+1][j] + 1), dp[i][j]);
			else
				dp[i+1][j+1] = min(min(dp[i][j+1]+1, dp[i+1][j]+1), dp[i][j]+1);
		}
	}
	cout << dp[a.length()][b.length()];
}

int main()
{
#ifdef Oj
	freopen("3356.in", "r", stdin);
#endif
	solve();
	return 0;
}
