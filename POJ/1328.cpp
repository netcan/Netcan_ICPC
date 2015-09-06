/*************************************************************************
	> File Name: 1328.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-06 日 15:37:00 CST
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

// 把每个岛屿来当做雷达的圆心，半径为d，做圆，与x轴会产生两个交点L和R，这就是一个区间；
// 然后把重叠的区间去掉剩下的区间数即为最小雷达数

struct Land {
	int x, y;
	double L, R;
	bool operator < (const Land &b) const {
		if(L == b.L)
			return R < b.R;
		return L < b.L;
	}

} land[1010];
int n, d, ans;
int maxy;


void solve() {
	if(maxy > d || d<=0) { ans = -1; return;}

	sort(land, land+n);
	// for(int i=0; i<n; ++i)
		// printf("[%f, %f]\n", land[i].L, land[i].R);

	ans = 1;
	int j = 0;
	double r = land[j].R;
	double minl = land[j].L;
	while(minl == land[j].L) { r=land[j].R; ++j;}

	for(int i=j; i<n; ++i) {
		if(r >= land[i].L && r <= land[i].R) continue;
		if(r > land[i].R) {
			r = land[i].R;
			// ++ans;
		}
		else if(r < land[i].L) {
			++ans;
			r = land[i].R;

		}
	}
}

int main()
{
#ifdef Oj
	freopen("1328.in", "r", stdin);
#endif
	int Case = 1;
	while(cin >> n >> d) {
		maxy = 0;
		if(n==0 && d == 0)
			break;
		for(int i=0; i<n;++i) {
			scanf("%d%d", &land[i].x, &land[i].y);
			land[i].L = land[i].x-sqrt(d*d - land[i].y*land[i].y);
			land[i].R = land[i].x+sqrt(d*d - land[i].y*land[i].y);
			maxy = max(land[i].y, maxy);
		}
		solve();
		printf("Case %d: %d\n", Case++, ans);
	}
	return 0;
}
