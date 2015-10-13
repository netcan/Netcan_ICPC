/*************************************************************************
	> File Name: 5501.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-13 二 19:33:42 CST
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

int T;
int t, n;
struct problem {
	int a, b, c;
	bool operator < (const problem &B) const {
		return c * B.b < B.c * b;
		// return c*1.0/b < B.c*1.0 / B.b;
	}
} problems[1002];

// const int INF = 0x3f3f3f3f;


void solve() {
	int dp[3005]; // 第i分钟得到的分数
	memset(dp, 0, sizeof(dp));
	sort(problems, problems+n);
	for(int i=0; i<problems[0].c; ++i) dp[i] = 0;
	dp[problems[0].c] = problems[0].a - problems[0].b*problems[0].c;
	for(int i=1; i<n; ++i)
		for(int j=t; j>=problems[i].c; --j)
			dp[j] = max(dp[j], dp[j-problems[i].c]+problems[i].a-j*problems[i].b);
	cout << *max_element(dp, dp+t+1) << endl;

}

int main()
{
#ifdef Oj
	freopen("5501.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> n >> t;
		for(int i=0; i<n; ++i) cin >> problems[i].a >> problems[i].b >> problems[i].c;
		solve();
	}
	return 0;
}
