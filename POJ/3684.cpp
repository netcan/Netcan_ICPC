/*************************************************************************
	> File Name: 3684.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-04 一 16:14:07 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int C;
int N, H, R, T;

const double g = 10; // 重力加速度10
double h[100+5];

double calc(int T) { // 计算T时刻小球的高度
	if(T<0) return H;
	double t = sqrt(2*H/g);
	int k = T/t;
	double d;
	if(k & 1) // 上升
		d = (k+1)*t - T;
	else // 下降
		d = T - k*t;
	return H-1/2.0*g*d*d;
}

void solve() {
	for (int i = 0; i < N; ++i) h[i] = calc(T-i);
	sort(h, h+N);
	for (int i = 0; i < N; ++i) printf("%.2f%c", h[i]+2*R*i/100.0, i==N-1?'\n':' ');
}

int main() {
#ifdef Oj
	freopen("3684.in", "r", stdin);
#endif
	cin >> C;
	while(C--) {
		cin >> N >> H >> R >> T;
		solve();
	}
	return 0;
}
