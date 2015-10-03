/*************************************************************************
	> File Name: 3181.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-03 六 16:14:09 CST
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

const int MAX_N = 1005;
const int MAX_K = 105;
int N, K;
long long int dp[MAX_K][MAX_N][2]; // 前K个数组成n的个数
const long long Mod = 100000000000000000;

void solve() {
	dp[0][0][1] = 1;
	for(int i=1; i<=K; ++i) {
		for(int j=0; j<=N; ++j) {
			for(int k=0; k*i <= j; ++k) {
				dp[i][j][0] += dp[i-1][j-k*i][0];
				dp[i][j][1] += dp[i-1][j-k*i][1];
				dp[i][j][0] += dp[i][j][1]/Mod;
				dp[i][j][1] %= Mod;
			}
		}
	}
	if(dp[K][N][0]) cout << dp[K][N][0];
	cout << dp[K][N][1] << endl;
}

int main()
{
#ifdef Oj
	freopen("3181.in", "r", stdin);
#endif
	cin >> N >> K;
	solve();
	return 0;
}
