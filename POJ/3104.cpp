/*************************************************************************
	> File Name: 3104.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-22 二 10:52:13 CST
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

int n;
int a[100000+5], k;
bool C(ll x) { // <=x分钟能否烘干所有衣服
	ll minute = 0; // 烘干机最少烘干的时间
	for(int i=1; i<=n; ++i) {
		int cura = a[i] - x; // 假设总共需要x分钟，那么减去x滴风干的水分，即可求得最少烘干机分钟
		if(cura > 0) minute += ceil(cura*1.0/(k-1)); // 若风干x滴水还剩水的话，用烘干机烘干，统计烘干机时间，除以k-1，是因为烘干过程中不会自然风干，所以k-1，加上前面x分钟的某一分钟，k-1+1=k可看做在烘干机中烘干而不是风干
		if(minute > x) return false; // 若烘干机最少烘干时间都大于总时间的话，即无法完成
	}
	return true;
}

void solve() {
	// cout << C(5) << endl;
	if(k == 1) { // 特殊情况
		printf("%d\n",*max_element(a+1, a+1+n));
		return;
	}

	ll lb = 0, ub = *max_element(a+1, a+1+n);
	while(ub - lb > 1) {
		ll mid = (ub + lb) >> 1;
		if(C(mid)) ub = mid; // 半闭半开区间，(lb, ub]
		else lb = mid;
	}
	printf("%lld\n", ub);
}

int main()
{
#ifdef Oj
	freopen("3104.in", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
	scanf("%d", &k);
	solve();
	return 0;
}
