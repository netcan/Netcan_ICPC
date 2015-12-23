/*************************************************************************
	> File Name: 3111.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-23 三 20:12:00 CST
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

const double EPS = 1e-6;

int n, k;
int v[100000+5], w[100000+5];
struct Remian{
	double c;
	int id;
	bool operator<(const Remian&b) const {
		return c > b.c;
	}
} remain[100000+5];

bool C(double x) {
	for(int i=0; i<n; ++i) {
		remain[i].c = v[i] - w[i]*x;
		remain[i].id = i+1; // 记录宝珠编号
	}
	sort(remain, remain+n);
	double sum = 0.0;
	for(int i=0; i<k; ++i) sum+=remain[i].c;
	return sum >= 0;
}

void solve() {
	double lb = 0.0, ub = 1000000000000000.0;
	while(ub - lb > EPS) {
	// for(int i=0; i<80; ++i) { // 精度10e-30
		double mid = (lb + ub) / 2.0;
		if(C(mid)) lb = mid; // 半闭半开区间[lb, ub)
		else ub = mid;
	}
	for(int i=0; i<k; ++i)	printf(i==0?"%d":" %d", remain[i].id);
	printf("\n");
}

int main()
{
#ifdef Oj
	freopen("3111.in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; ++i) scanf("%d%d", &v[i], &w[i]);
	solve();
	return 0;
}
