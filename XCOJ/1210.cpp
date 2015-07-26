/*************************************************************************
	> File Name: 1210_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 02 Jun 2015 11:03:04 PM CST
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

int main()
{
#ifdef Oj
	freopen("1210.in", "r", stdin);
#endif
	int T;
	cin >> T;
	int n, K;
	int a[105];
	int m[105];
	static int dp[100005];
	while(T--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> m[i];
		cin >> K;
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= K; ++j) {
				if(dp[j] >=0 )
					dp[j] = m[i];
				else if(j < a[i] || dp[j-a[i]] <= 0)
					dp[j] = -1;
				else
					dp[j] = dp[j-a[i]]-1;
			}
		}
		if(dp[K]>=0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
