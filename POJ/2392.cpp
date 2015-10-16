/*************************************************************************
	> File Name: 2392.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-15 四 16:09:51 CST
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

int K;
struct block {
	int h, a, c; // 高度，海拔，个数
	bool operator<(const block &b) const {
		return a < b.a;
	}
} blocks[402];

// int dp[402]; // dp[i]前i个砖块的最大高度
bool visited[40025]; // visited[i]标记能堆成高度i
int sum[40025];


void solve() {
	sort(blocks, blocks+K);
	memset(visited, 0, sizeof(visited));
	visited[0] = true;
	int ans = 0;
	for(int i=0; i<K; ++i) {
		memset(sum, 0, sizeof(sum));
		for(int j=blocks[i].h; j<=blocks[i].a; ++j) {
			if(!visited[j] && visited[j-blocks[i].h] && sum[j-blocks[i].h] < blocks[i].c) {
				visited[j] = true;
				sum[j] = sum[j-blocks[i].h] + 1;
				ans = max(j, ans);
			}
		}
	}
	cout << ans << endl;

	// dp[1] = blocks[0].c * blocks[0].h;
	// int max_c;
	// for(int i=1; i<K; ++i) {
		// max_c = min((blocks[i].a - dp[i]) / blocks[i].h, blocks[i].c);
		// dp[i+1] = dp[i] + max_c * blocks[i].h;
		// int cur_cnt = blocks[i].c - max_c;
		// int height = dp[i+1];
		// for(int j=0; j<blocks[i-1].c && cur_cnt > 0; ++j) {
			// height -= blocks[i-1].h;
			// if(height + blocks[i].h <= blocks[i].a && cur_cnt > 0 && height + blocks[i].h > dp[i+1]) {
				// dp[i+1]  = height + blocks[i].h;
				// height = dp[i+1];
				// --cur_cnt;
			// }
		// }
	// }
	// cout << *max_element(dp+1, dp+1+K) << endl;
}

int main()
{
#ifdef Oj
	freopen("2392.in", "r", stdin);
#endif
	cin >> K;
	for(int i=0; i<K; ++i) {
		cin >> blocks[i].h >> blocks[i].a >> blocks[i].c;
	}
	solve();
	return 0;
}
