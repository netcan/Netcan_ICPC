/*************************************************************************
	> File Name: 1159.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-30 Thu 14:49:39 CST
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

char a[1000], b[1000];
int dp[1005][1005];

void solve() {
	cin.sync_with_stdio(false);
	while(cin >> a >> b) {
		memset(dp, 0, sizeof(dp));
		int la = strlen(a), lb = strlen(b);
		for(int i=0; i<la; ++i)
			for(int j=0; j<lb; ++j) {
				if(a[i] == b[j])
					dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i][j+1], dp[i+1][j]));
				else
					dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		cout << dp[strlen(a)][strlen(b)] << endl;
	}
}

int main()
{
#ifdef Oj
	freopen("1159.in", "r", stdin);
#endif
	solve();
	return 0;
}
