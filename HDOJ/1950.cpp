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

int find(int x) {
	int l=0, r=p;
	int mid;
	while(l+1 <= r) {
		// printf("(%d,%d), %d\n", l, r, x);
		mid = (l+r) >> 1;
		if(dp[mid] > x) r = mid;
		else if(dp[mid] < x) l = mid+1;
		else return mid;
	}
	return l;
}

void solve() {
	memset(dp,0x3f, sizeof(dp));
	for(int i=0; i<p; ++i)
		dp[find(data[i])] = data[i];
	int ans = 0;
	for(ans=0; dp[ans] != 0x3f3f3f3f; ++ans);
	cout << ans << endl;

}

int main()
{
#ifdef Oj
	freopen("1950.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		cin >> p;
		for (int i = 0; i < p; ++i) cin >> data[i];
		solve();
	}
	return 0;
}
