/*************************************************************************
	> File Name: 2602.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-15 四 19:16:45 CST
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

int T, N, V;
int dp[1002];
int value[1002];
int volume[1002];

void solve() {
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<N; ++i)
		for(int j=V; j>=volume[i]; --j)
			dp[j] = max(dp[j], dp[j-volume[i]] + value[i]);
	cout << dp[V] << endl;
}

int main()
{
#ifdef Oj
	freopen("2602.in", "r", stdin);
#endif
	cin >> T;
	while(T--) {
		cin >> N >> V;
		for(int i=0; i<N; ++i) cin >> value[i];
		for(int i=0; i<N; ++i) cin >> volume[i];
		solve();
	}
	return 0;
}
