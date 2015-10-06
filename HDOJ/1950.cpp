/*************************************************************************
	> File Name: 1950.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-06 二 16:47:30 CST
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

int dp[40005]; // dp[i]表示前i-1个最长递增子序列的最小值
int p;
int data[40005];

void solve() {
	memset(dp,0x3f, sizeof(dp));
	for(int i=0; i<p; ++i)
		*lower_bound(dp, dp+p, data[i]) = data[i];
	cout << lower_bound(dp, dp+p, 0x3f3f3f3f) - dp << endl;

}

int main()
{
#ifdef Oj
	freopen("1950.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		cin >> p;
		for (int i = 0; i < p; ++i) cin >> data[i];
		solve();
	}
	return 0;
}
