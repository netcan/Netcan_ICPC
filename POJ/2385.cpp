/*************************************************************************
	> File Name: 2385.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-23 三 15:12:04 CST
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

int T, W;
int dp[1005][35]; // 前T分钟内W步能拿到苹果数量
int a[1005];

void solve() {
	for(int i=1; i<=T; ++i)
		cin >> a[i];

	int maxa = 0;
	for(int t=1; t<=T; ++t) {
		dp[t][0] = dp[t-1][0] + (a[t] == 1);
		for(int w=1; w<=W; ++w) // 奇数在tree2，偶数在tree1
			// if(w & 1) dp[t][w] = max(dp[t-1][w-1], dp[t-1][w]) + (a[t] == 2); // 在tree2
			// else dp[t][w] = max(dp[t-1][w-1], dp[t-1][w]) + (a[t] == 1); // 在tree1
			dp[t][w] = max(dp[t-1][w-1], dp[t-1][w]) + (a[t] == w%2 + 1); // 当前w步是由w-1步移过来的或者原地不动
	}
	for(int i=0; i<=W; ++i) maxa = max(dp[T][i], maxa);
	cout << maxa << endl;

}

int main()
{
#ifdef Oj
	freopen("2385.in", "r", stdin);
#endif
	cin >> T >> W;
	solve();
	return 0;
}
