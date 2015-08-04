/*************************************************************************
	> File Name: 1579.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-04 Tue 15:32:43 CST
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
int w(int a, int b, int c) {
	if(dp[a][b][c] != -1 && a>=0 && b>=0 && c>=0)
		return dp[a][b][c];

	if(a <= 0 || b<=0 || c<=0)
		return dp[0][0][0]=1;
	else if(a>20 || b>20 || c>20)
		return dp[20][20][20] = w(20, 20, 20);
	else if(a<b && b<c)
		return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

void solve() {
	int a, b, c;
	memset(dp, -1, sizeof(dp));
	while(cin >> a >> b >> c) {
		if(a==b && b==c && c==-1)
			break;
		printf("w(%d, %d, %d) = ", a, b, c);
		if(a <=0 || b<=0 || c<=0)
			printf("1\n");
		else if(a > 20 || b>20 || c>20)
			printf("%d\n",w(20, 20, 20));
		else
			printf("%d\n", w(a, b, c));
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
