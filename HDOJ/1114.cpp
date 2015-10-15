/*************************************************************************
	> File Name: 1114.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-15 四 19:39:07 CST
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

int T, N;
int E, F;
int p[502], w[502];
int dp[10005];


void solve() {
	int W = F-E;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i=0; i<N; ++i)
		for(int j=w[i]; j<=W; ++j)
			dp[j] = min(dp[j], dp[j-w[i]] + p[i]);
	if(dp[W] != 0x3f3f3f3f)
		printf("The minimum amount of money in the piggy-bank is %d.\n", dp[W]);
	else
		printf("This is impossible.\n");
}

int main()
{
#ifdef Oj
	freopen("1114.in", "r", stdin);
#endif
	cin >> T;
	while(T--) {
		cin >> E >> F;
		cin >> N;
		for(int i=0; i<N; ++i) cin >> p[i] >> w[i];
		solve();
	}
	return 0;
}
