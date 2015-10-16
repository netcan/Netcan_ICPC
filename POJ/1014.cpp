/*************************************************************************
	> File Name: 1014.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-16 五 20:11:19 CST
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

int a[7];
int Value;
int dp[20000*6 + 5];
int Case = 1;

void solve() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	printf("Collection #%d:\n", Case++);
	for(int i=1; i<=6; ++i) {
		for(int j=0; j<=Value; ++j) {
			if(dp[j] >= 0) dp[j] = a[i];
			else if(j < i || dp[j-i] <= 0) dp[j] = -1;
			else dp[j] = dp[j-i] - 1;
		}
	}
	if(Value & 1 || dp[Value/2] < 0) puts("Can't be divided.\n");
	else puts("Can be divided.\n");
}

int main()
{
#ifdef Oj
	freopen("1014.in", "r", stdin);
#endif
	while(1) {
		Value = 0;
		for(int i=1; i<=6; ++i) cin >> a[i];
		for(int i=1; i<=6; ++i) Value += a[i]*i;
		if(Value == 0) break;
		solve();
	}
	return 0;
}
