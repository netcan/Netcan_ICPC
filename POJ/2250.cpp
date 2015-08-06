/*************************************************************************
	> File Name: 2250.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-06 Thu 14:42:14 CST
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
#define leftup 0
#define left 1
#define up 2

string s1[101], s2[101];
int dp[101][101];
int op[101][101];
int ans[101];

void solve() {
	int l1, l2;
	while(!cin.eof()) {
		l1 = l2 = 0;
		while(cin >> s1[l1++] && s1[l1-1] != "#");
		while(cin >> s2[l2++] && s2[l2-1] != "#");

		--l1, --l2;
		// for(int i=0; i<l1; ++i)
			// cout << s1[i] << " ";
		// cout << endl;
		// for(int i=0; i<l2; ++i)
			// cout << s2[i] << " ";
		// cout << endl;

		memset(dp, 0, sizeof(dp));
		memset(op, -1, sizeof(op));
		for(int i=0; i<l1; ++i) {
			for(int j=0; j<l2; ++j) {
				if(s1[i] == s2[j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
					op[i][j] = leftup;
				}
				else if(dp[i][j+1] >= dp[i+1][j]) {
					dp[i+1][j+1] = dp[i][j+1]; // 指向大的, 所以箭头朝上
					op[i][j] = up;
				}
				else  {
					dp[i+1][j+1] = dp[i+1][j]; // 箭头朝左，左边大
					op[i][j] = left;
				}
			}
		}

		int i = l1-1, j = l2-1;
		int count = 0;
		// for(int i=1; i<=l1; ++i) {
			// for(int j=1; j<=l1; ++j) {
				// cout << op[i][j] << " ";
			// }
			// cout << endl;
		// }

		while(i>=0 && j>=0) {
			if(op[i][j] == leftup) {
				ans[count++] = i; // 保存到栈中
				--i;
				--j;
			}
			else if(op[i][j] == left)
				--j;
			else if(op[i][j] == up)
				--i;
		}

		--count;
		while(count >=0) {
			cout << s1[ans[count]];
			if(count)
				cout << " ";
			else cout << endl << endl;
			--count;
		}
	}
}

int main()
{
#ifdef Oj
	freopen("2250.in", "r", stdin);
#endif
	solve();
	return 0;
}
