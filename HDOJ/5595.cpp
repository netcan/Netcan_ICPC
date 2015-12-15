/*************************************************************************
	> File Name: 1001.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-12 六 18:59:23 CST
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

int a, b, c, l, r;

int f(int x) {
	return a*x*x+b*x+c;
}

void solve() {
	int Min=f(l), Max=f(l);
	for(int x=l; x<=r; ++x) {
		Min = min(Min, f(x));
		Max = max(Max, f(x));
	}
	printf("%d %d\n", Max, Min);

}

int main()
{
#ifdef Oj
	freopen("1001.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d%d", &a, &b, &c, &l, &r);
		solve();
	}
	return 0;
}
