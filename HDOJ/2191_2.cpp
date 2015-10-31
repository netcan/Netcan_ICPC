/*************************************************************************
	> File Name: 2191.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-15 四 19:56:34 CST
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

int C;
int n, m; // 经费，种类
int p[102], h[102], c[102]; // 价格，重量，袋数
// int dp[102][102]; // 前i个到达不超过加个j时达到的最大重量
int dp[102]; // 前i个价格不超过j时的最大重量

void solve() {
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<m; ++i) {
		int num = c[i];
		for(int j=1; j<=num; j<<=1) {
			for(int k=n; k>=j*p[i]; --k)
				dp[k] = max(dp[k], dp[k-j*p[i]] + j*h[i]);
			num-=j;
		}
		if(num)
			for(int k=n; k>=num*p[i]; --k)
				dp[k] = max(dp[k], dp[k-num*p[i]] + num*h[i]);
	}
	cout << dp[n] << endl;

}

int main()
{
#ifdef Oj
	freopen("2191.in", "r", stdin);
#endif
	cin >> C;
	while(C--) {
		cin >> n >> m;
		for(int i=0; i<m; ++i) cin >> p[i] >> h[i] >> c[i];
		solve();
	}
	return 0;
}
