/*************************************************************************
	> File Name: 1087.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-30 Thu 14:22:38 CST
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
int N;
int data[1005];
int dp[1005];

void solve() {
	int n;
	while(cin >> n && n) {
		for (int i = 0; i < n; ++i)
			cin >> data[i];
		// for (int i = 0; i < n; ++i)
			// cout << data[i] << " ";
		// cout << endl;
		memset(dp, 0, sizeof(dp));
		dp[0] = data[0];
		int maxn = 0;
		for(int i=0; i<n; ++i) {
			maxn = 0;
			for(int j=0; j<i; ++j) {
				if(data[j] < data[i] && dp[j] > maxn) {
					maxn = dp[j];
				}
				dp[i] = maxn+data[i];
			}
		}
		maxn = 0;
		for(int i=0; i<n; ++i)
			maxn = max(maxn, dp[i]);
		cout << maxn << endl;
	}
}

int main()
{
#ifdef Oj
	freopen("1087.in", "r", stdin);
#endif
	solve();
	return 0;
}
