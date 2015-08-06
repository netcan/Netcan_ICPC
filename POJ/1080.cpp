/*************************************************************************
	> File Name: 1080.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-06 Thu 17:16:09 CST
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

int t[5][5] = {
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,-1000}
};

int cov(char c) {
	switch(c) {
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
		case '-':
			return 4;
		default:
			return -1;
	}
}

int table(char a, char b) {
	return t[cov(a)][cov(b)];
}

int dp[101][101];
string s1, s2;

void solve() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N >> s1;
		cin >> N >> s2;
		// for(int i=0; i<s1.length(); ++i)
			// cout << s1[i];
		// cout << endl;
		dp[0][0] = 0;
		for(int i=0; i<s1.length(); ++i)
			dp[i+1][0] = dp[i][0] + table(s1[i], '-');
		for(int i=0; i<s2.length(); ++i)
			dp[0][i+1] = dp[0][i] + table('-', s2[i]);



		for(int i=0; i<s1.length(); ++i)
			for(int j=0; j<s2.length(); ++j)
				dp[i+1][j+1] = max(max(dp[i][j+1] + table(s1[i], '-'), dp[i+1][j]+table('-', s2[j])), dp[i][j] + table(s1[i], s2[j]));

		// for(int i=0; i<=s1.length(); ++i) {
			// for(int j=0; j<=s2.length(); ++j)
				// printf("%3d", dp[i][j]);
			// cout << endl;
		// }


		cout << dp[s1.length()][s2.length()] << endl;
	}

}

int main()
{
#ifdef Oj
	freopen("1080.in", "r", stdin);
#endif
	solve();
	return 0;
}
