/*************************************************************************
	> File Name: 1176.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-30 Thu 15:45:51 CST
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
int dp[100005][11];


void solve() {
	int n;
	while(scanf("%d", &n) == 1 && n) {
		memset(dp, 0, sizeof(dp));
		int x, t, maxt = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &x, &t);
			++dp[t][x];
			maxt = max(maxt, t);
		}
		for(int t=maxt-1; t>=0; --t) // 时间t
			for(int x=0; x<=10; ++x) // 位置x
				if(x==0)
					dp[t][x] += max(dp[t+1][1], dp[t+1][0]);
				else if(x==10)
					dp[t][x] += max(dp[t+1][10], dp[t+1][9]);
				else
					dp[t][x] += max(max(dp[t+1][x], dp[t+1][x-1]), dp[t+1][x+1]);
		cout << dp[0][5] << endl;

	}

}

int main()
{
#ifdef Oj
	freopen("1176.in", "r", stdin);
#endif
	solve();
	return 0;
}
