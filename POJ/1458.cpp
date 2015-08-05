/*************************************************************************
	> File Name: 1458.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-05 Wed 15:51:01 CST
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
int dp[1000][1000];

void solve() {
	string a, b;
	while(cin >> a >> b) {
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<a.length(); ++i)  // a
			for(int j=0; j<b.length(); ++j) { // b
				if(a[i] == b[j])
					dp[i+1][j+1] = dp[i][j] + 1;
				else
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		cout << dp[a.length()][b.length()] << endl;
	}

}

int main()
{
#ifdef Oj
	freopen("1458.in", "r", stdin);
#endif
	solve();
	return 0;
}
