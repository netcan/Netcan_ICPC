/*************************************************************************
	> File Name: 3280.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-24 四 16:18:54 CST
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

int N, M; // 费用个数N， 字符串长度M
string s;
int cost[30];
int dp[2048][2048]; // i到j变成回文的最小花费

void solve() {
	for(int i=M-1; i>=0; --i) {
		for(int j=i+1; j<M; ++j) {
			dp[i][j] = min(dp[i+1][j]+cost[s[i]-'a'], dp[i][j-1]+cost[s[j]-'a']);
			if(s[i] == s[j]) dp[i][j] = min(dp[i+1][j-1], dp[i][j]);
		}
	}

	cout << dp[0][M-1] << endl;
}

int main()
{
#ifdef Oj
	freopen("3280.in", "r", stdin);
#endif
	cin >> N >> M;
	cin >> s;
	char a;
	int b, c;
	for(int i=0; i<N; ++i) {
		cin >> a >> b >> c;
		cost[a-'a'] = min(b, c);
	}

	solve();
	return 0;
}
