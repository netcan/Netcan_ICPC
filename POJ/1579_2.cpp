/*************************************************************************
	> File Name: 1579_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-04 Tue 16:05:27 CST
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

int dp[21][21][21];
void solve() {
	int a, b, c;
	for(int i=0; i<=20; ++i)
		for(int j=0; j<=20; ++j)
			for(int k=0; k<=20; ++k) {
				if(i==0 || j==0 || k == 0)
					dp[i][j][k] = 1;
				else if(i < j && j < k)
					dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
				else
					dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
			}

	while(cin >> a >> b >> c) {
		if(a == b && b == c && c == -1)
			break;

		if(a <=0 || b <=0 || c<= 0)
			printf("w(%d, %d, %d) = 1\n", a, b, c );
		else
			printf("w(%d, %d, %d) = %d\n", a, b, c, dp[a>20?20:a][b>20?20:b][c>20?20:c]);

	}

}

int main()
{
#ifdef Oj
	freopen("1579.in", "r", stdin);
#endif
	solve();
	return 0;
}
