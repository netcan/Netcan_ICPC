/*************************************************************************
	> File Name: 2192_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-07 Fri 14:24:01 CST
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

bool dp[202][202];
/*
 * 动态规划，dp[i][j]表示a的前i个字符和b的前i个字符能否组成c的前i+j个字符。
 */

void solve() {
	int T;
	cin >> T;
	string a, b, c;
	int Case = 1;
	while(T--) {
		memset(dp, 0, sizeof(dp));
		cin >> a >> b >> c;
		dp[0][0] = true;

		for(int i=0; i<a.length(); ++i)
			if(a[i] == c[i] && dp[i][0])
				dp[i+1][0] = true;
		for(int i=0; i<b.length(); ++i)
			if(b[i] == c[i] && dp[0][i])
				dp[0][i+1] = true;

		for(int i=0; i<a.length(); ++i)
			for(int j=0; j<b.length(); ++j) {
				if((dp[i][j+1] && a[i] == c[i+j+1]) || (dp[i+1][j] && b[j] == c[i+j+1]))
					dp[i+1][j+1] = true;
			}
		printf("Data set %d: ", Case++);
		if(dp[a.length()][b.length()])
			printf("yes\n");
		else
			printf("no\n");
	}

}

int main()
{
#ifdef Oj
	freopen("2192.in", "r", stdin);
#endif
	solve();
	return 0;
}
