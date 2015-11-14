/*************************************************************************
	> File Name: 1002.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-14 六 19:08:00 CST
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

int T;
const double eps = 1e-4;
struct point {
	double x, y;
} ps[5];

int side(point &p1, point &p2, point &p3) { // 返回p3在直线p1p2哪侧
	double s = p1.x*p2.y + p3.x*p1.y + p2.x*p3.y
				- p3.x*p2.y - p2.x*p1.y - p1.x*p3.y;
	if(s>0) return 1;
	else if(s==0) return 0;
	else return -1;
}
double dist(point &p1, point &p2) { // 两点之间的距离
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y - p2.y));
}

bool equal(double a, double b) { // 是否相等
	return fabs(a-b) < eps;
}
bool same(point &p1, point &p2) { // 点是否相等
	return equal(p1.x, p2.x) && equal(p1.y, p2.y);
}

void solve() {
	int cnt = 0;
	bool flag = true;
	double l = 0.0;
	for(int i=1; i<5; ++i) { // 5个点是否相等
		if(!same(ps[0], ps[i])) flag = false;
	}
	if(flag) {
		printf("Yes\n");
		return;
	}
	flag = true;

	// 若为正五边形，则可以组成五角星
	for(int i=0; i<5; ++i) {
		if(!flag) break;
		for(int j=i+1; j<5; ++j) {
			int s = 0;
			for(int k=0; k<5; ++k)
	 			if(k!=i && k!=j)
					s+=side(ps[i], ps[j], ps[k]);

			if(abs(s) == 3) {
				++cnt;
				if(equal(l, 0.0)) l = dist(ps[i], ps[j]);
				else if(!equal(dist(ps[i],ps[j]), l)) {
					flag = false;
					break;
				}
			}
		}
	}

	printf(cnt == 5 && flag?"Yes\n":"No\n");
}

int main()
{
#ifdef Oj
	freopen("1002.in", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		for(int i=0; i<5; ++i) scanf("%lf%lf", &ps[i].x, &ps[i].y);
		solve();
	}
	return 0;
}
