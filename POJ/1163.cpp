/*************************************************************************
	> File Name: 1163.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-04 Tue 15:19:22 CST
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
int dp[105][105];
void solve() {
	cin.sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; ++i)
		for(int j=0; j<=i; ++j)
			cin >> dp[i][j];
	for(int i=N-2; i>=0; --i)
		for(int j=0; j<=i; ++j)
			dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
	cout << dp[0][0] << endl;
}

int main()
{
#ifdef Oj
	freopen("1163.in", "r", stdin);
#endif
	solve();
	return 0;
}
