/*************************************************************************
	> File Name: 1759.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-28 一 14:49:14 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
double A;
double H[1005];
const double eps = 1e-6;

double h(int i, double x) { // 已知h(2) = x
	if(i==1) return H[1] = A;
	else if(i==2) return H[2] = x;
	else return H[i] = 2.0*H[i-1] - H[i-2] + 2.0;
}

bool C(double x) { // 判断第二个灯笼的高度为x，是否合适。
	for(int i=1; i<=N; ++i)
		if(h(i, x) < eps) return false;
	return true;
}

void solve() {
	double lb = 0, ub = 10000.0;
	for (int i = 0; i < 100; ++i) { // 二分求出第二个灯笼到底该多低
		double mid = (ub + lb) / 2.0;
		if(C(mid)) ub = mid; // (lb, ub]
		else lb = mid;
	}
	printf("%.2f\n", H[N]); // 最后一个灯笼的高度
}

int main() {
#ifdef Oj
	freopen("1759.in", "r", stdin);
#endif
	while(cin >> N >> A) {
		solve();
	}
	return 0;
}
