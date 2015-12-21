/*************************************************************************
	> File Name: 1064.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-21 一 11:05:45 CST
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

int N, K;
double length[10000+5];
const double EPS = 1e-6; // EPS取得太小会死循环

bool C(double x) {
	int count = 0;
	for(int i=0; i<N; ++i) count += int(length[i] / x);
	if(count >= K) return true;
	return false;
}

void solve() {
	double lb = 0.0, ub = 100000000.0;

	// while(ub - lb > EPS) { // 精度不好控制
	for(int i=0; i<100; ++i) { // 精度(1/2)^100=10e-30，lb几乎等于ub
		double mid = (lb + ub) / 2.0;
		if(C(mid)) lb = mid; // 半闭半开区间[lb, ub)
		else ub = mid;
	}
	printf("%.2f\n", floor(lb*100)/100); // .2f会四舍五入所以要先*100取整以截取
}

int main()
{
#ifdef Oj
	freopen("1064.in", "r", stdin);
#endif
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; ++i) scanf("%lf", &length[i]);
	solve();
	return 0;
}
