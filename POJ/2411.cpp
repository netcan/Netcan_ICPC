/*************************************************************************
	> File Name: 2411.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-09-07 三 09:11:39 CST
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

typedef long long ll;

ll dp[11][2<<11];
int h, w, allStatus;

bool testFirstLine(int status) {
	int j = 0;
	while(j < w) {
		if(status & (1<<j)) {
			if(j == w-1 || (status & (1<<(j+1))) == 0)
				return false;
			else j+=2;
		}
		else ++j;
	}
	return true;
}

bool canTransfer(int statusA, int statusB) { // 第i行状态A是否能由i-1行状态B转移过来
	int j = 0;
	while(j < w) { // 一位位获取
		if((statusA & (1<<j)) == 0) { // 0
			if((statusB & (1<<j)) == 0)
				return false;
			else ++j;
		}
		else { // 1
			if((statusB & (1<<j)) == 0) ++j;
			else if(j == w-1 || !((statusA & (1<<(j+1))) && (statusB & (1<<(j+1)))))
				return false;
			else j+=2;
		}
	}
	return true;
}


void solve() {
	memset(dp, 0, sizeof(dp));
	if(w > h) swap(w, h);
	allStatus = 1<<w; // ?

	for(int s=0; s<allStatus; ++s)
		if(testFirstLine(s)) dp[0][s] = 1;
	for(int i=1; i<h; ++i)
		for(int sa = 0; sa<allStatus; ++sa)
			for(int sb = 0; sb<allStatus; ++sb)
				if(canTransfer(sa, sb))
					dp[i][sa] += dp[i-1][sb];
	printf("%lld\n", dp[h-1][allStatus-1]);
}

int main() {
#ifdef Oj
	freopen("2411.in", "r", stdin);
#endif
	while(scanf("%d%d", &w, &h) == 2) {
		if(h == 0 && w == 0)
			break;
		solve();
	}
	return 0;
}
