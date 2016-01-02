/*************************************************************************
	> File Name: 1001.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-02 六 19:03:16 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T;
struct Point {
	int x, y;
	Point(int x, int y):x(x), y(y){}
};

Point P(0, 0);
double d(Point p1, Point p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
void solve() {
	int B = P.x+P.y;
	printf("%.f\n", d(P, Point(B,0)) * d(P, Point(0, B)));
}

int main() {
#ifdef Oj
	freopen("1001.in", "r", stdin);
#endif
	cin >> T;
	while(T--) {
		cin >> P.x >> P.y;
		solve();
	}
	return 0;
}
