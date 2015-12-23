/*************************************************************************
	> File Name: 2976.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-23 三 18:23:16 CST
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
int n, k;
ll a[1000+4], b[1000+4];
double c[1000+4];

bool C(double x) { // 检验取出的n-k个数的累计平均值是否能>=x
	for(int i=0; i<n; ++i)	c[i] = a[i]*100 - x*b[i];
	sort(c, c+n);
	double sum = 0;
	for(int i=0; i<n-k; ++i) sum+=c[n-i-1];
	// printf("sum: %f\n", sum);
	return sum >= 0;
}

void solve() {
	double lb = 0, ub=1000000000000000.0;
	for(int i=0; i<100; ++i) { // 精度10e-30
		double mid = (ub + lb) /2.0;
		if(C(mid)) lb = mid; // 半闭半开区间[lb, ub)
		else ub = mid;
	}
	printf("%.f\n", floor(lb+0.5)); // 四舍五入
}

int main()
{
#ifdef Oj
	freopen("2976.in", "r", stdin);
#endif
	while(cin >> n >> k) {
		if(n==k && n==0) break;
		for(int i=0; i<n; ++i) cin >> a[i];
		for(int i=0; i<n; ++i) cin >> b[i];
		solve();
	}
	return 0;
}
