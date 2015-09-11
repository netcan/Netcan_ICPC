/*************************************************************************
	> File Name: 2015033.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-11 五 21:18:46 CST
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

const int year[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
						{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
bool isleap(int y) {
	return (y%400 == 0 || (y%4==0 && y%100!=0)) ? true:false;
}

int dp[201]; // 存放1850+x年前的闰年个数

int weekday(int y, int m, int d) {
	int count = (y-1850)*365+ dp[y-1850] - isleap(y);

	for(int i=1; i<m; ++i)
		count += year[isleap(y)][i];
	count += d;

	// printf("cnt:%d\n", count);
	int wkd = (count+1) % 7;
	return wkd == 0?7:wkd;
}


void solve() {
	for(int x=0; x<=200; ++x) {
		if(isleap(1850+x)) {
			dp[x] = x-1>=0?dp[x-1]+1:1;
			// cout << 1850+x << endl;
			// cout << dp[1852-1850] << endl;
		}
		else
			dp[x] = x-1>=0?dp[x-1]:0;
	}
	int a, b, c, y1, y2; // a月的第b个星期c
	// weekday(1852, 3, 1);

	cin >> a >> b >> c >> y1 >> y2;

	for(int y=y1; y<=y2; ++y) {
		int iw = 1; // 第几个星期
		bool flag = false;
		for(int d=1; d<=year[isleap(y)][a]; ++d) {
			if(iw == b && weekday(y, a, d) == c) {
				printf("%4d/%02d/%02d\n", y, a, d);
				flag = true;
			}
			if(weekday(y, a, d) == c) ++iw;
			if(flag)
				break;
		}
		if(!flag) {
			printf("none\n");
		}

	}

	// cout << weekday(2051, 12, 29) << endl;
}

int main()
{
#ifdef Oj
	freopen("2015033.in", "r", stdin);
#endif
	solve();
	return 0;
}
