/*************************************************************************
	> File Name: 3616.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-23 三 16:49:19 CST
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

int dp[1005];
int M, N, R;
struct Interval {
	int start, end, eff;
	bool operator<(const Interval & b) const {
		return start < b.start;
	}
} I[1005];

void solve() {
	sort(I, I+M);
	for(int i=0; i<M; ++i) {
		dp[i] = I[i].eff;
		for(int j=0; j<i; ++j) {
			if(I[j].end <= I[i].start && dp[i] <= dp[j] + I[i].eff)  dp[i] = dp[j] + I[i].eff;
			// if(I[j].end <= I[i].start) dp[i] = max(dp[i], dp[j]+I[i].eff);
		}
	}
	cout << *max_element(dp, dp+M) << endl;
}

int main()
{
#ifdef Oj
	freopen("3616.in", "r", stdin);
#endif
	cin >> N >> M >> R;
	for(int i=0; i<M; ++i) {
		cin >> I[i].start >> I[i].end >> I[i].eff;
		I[i].end += R;
	}
	solve();
	return 0;
}
