/*************************************************************************
	> File Name: 1159.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-06 Thu 16:33:51 CST
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

string s1, s2;
unsigned short dp[5001][5001];

void solve() {
	int N;
	cin >> N;
	cin >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<s1.length(); ++i)
		for(int j=0; j<s2.length(); ++j) {
			if(s1[i] == s2[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		}
	cout << N-dp[N][N] << endl;
}

int main()
{
#ifdef Oj
	freopen("1159.in", "r", stdin);
#endif
	solve();
	return 0;
}
