/*************************************************************************
	> File Name: 1887.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-08 六 14:34:22 CST
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

vector<int> h;
int dp[1000000]; // 最长递减子序列, dp[i]存放以a[i]结尾的最大递增子序列长度

void solve() {
	int n;
	int Case = 1;
	while(cin >> n) {
		// cout<<h.size() << endl;
		if(n != -1)
			h.push_back(n);
		else {
			if(!h.size())
				break;
			// cout << "hello" << endl;
			memset(dp, 0, sizeof(dp));
			int Max = 0;
			for(int i=0; i<h.size(); ++i) {
				dp[i] = 1;
				for(int j=0; j<i; ++j) {
					if(h[j] > h[i]) {
						dp[i] = max(dp[i], dp[j]+1);
					}
				}
				Max = max(dp[i], Max);
			}
			h.clear();
			printf("Test #%d:\n", Case++);
			printf("  maximum possible interceptions: %d\n\n", Max);
		}
	}
}

int main()
{
#ifdef Oj
	freopen("1887.in", "r", stdin);
#endif
	solve();
	return 0;
}
