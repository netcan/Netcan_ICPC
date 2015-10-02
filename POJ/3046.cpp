/*************************************************************************
	> File Name: 3046.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-02 五 20:10:48 CST
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

const int MOD = 1000000;
int An[1005];
int T, A, S, B;
const int MAX_T = 1000 + 5;
const int MAX_M = 10000 + 5;
int dp[MAX_T][MAX_M]; // dp[i+1][j]从前i种物品中取出j个的组合总数


void solve() {
	for(int i=1; i<=T+1; ++i) dp[i][0] = 1; // 一个都不取
	for(int i=1; i<=T; ++i) {
		for(int j=1; j<=B; ++j) {
			if(j-1-An[i] >= 0)
				dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-An[i]] + MOD) % MOD;
			else
				dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % MOD;
		}
	}
	int ans = 0;
	for(int i=S; i<=B; ++i) ans = (ans + dp[T+1][i]) % MOD;
	cout << ans << endl;

}

int main()
{
#ifdef Oj
	freopen("3046.in", "r", stdin);
#endif
	cin >> T >> A >> S >> B;
	int n;
	for(int i=0; i<A; ++i) {
		cin >> n;
		++An[n];
	}
	solve();
	return 0;
}
