/*************************************************************************
	> File Name: 2184.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-20 二 20:41:56 CST
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
int s[102], f[102];
const int zero = 100000;
const int MAX_S = 200000;
int dp[MAX_S+1]; // 以s和为状态求最大f，即dp[s] = f; s范围[-100000, 100000], 以zero=100000为零点
int max_s;
int min_s;

void solve() {
	for(int i=0;i<=max_s; ++i) dp[i+zero] = -0x3f3f3f3f;
	dp[zero] = 0;

	for(int i=0; i<N; ++i) {
		if(s[i] >= 0)
			for(int j=max_s; j-s[i]>=min_s; --j) dp[j+zero] = max(dp[j+zero], dp[j+zero-s[i]]+f[i]);
		else
			for(int j=min_s; j-s[i]<=max_s; ++j) dp[j+zero] = max(dp[j+zero], dp[j+zero-s[i]]+f[i]);
	}

	int ans = 0;

	for(int i=0; i<=max_s; ++i) {
		if(dp[i+zero] >=0)
			ans = max(ans, dp[i+zero] + i);
	}

	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("2184.in", "r", stdin);
#endif
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> s[i] >> f[i];
		if(s[i] >= 0) max_s += s[i];
		else min_s += s[i];
	}
	solve();
	return 0;
}
