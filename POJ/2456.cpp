/*************************************************************************
	> File Name: 2456.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-21 一 14:53:34 CST
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

int N, C; // 牛的总数N，会攻击其他牛的数量C
int x[100004];
bool c(int d) {
	int last = 0;
	for(int i=1; i<C; ++i) {
		int crt = last + 1;
		while(crt < N && x[crt] - x[last] < d) ++crt;
		if(crt == N) return false;
		last = crt;
	}
	return true;
}

void solve() {
	sort(x, x+N);
	int lb = 0, ub = 1000000006;
	while(ub - lb > 1) {
		int mid = (ub + lb) >> 1;
		if(c(mid)) lb = mid; // 半闭半开区间[lb, ub)
		else ub = mid;
	}
	printf("%d\n", lb);
}

int main()
{
#ifdef Oj
	freopen("2456.in", "r", stdin);
#endif
	scanf("%d%d", &N, &C);
	for(int i=0; i<N; ++i) 	scanf("%d", &x[i]);
	solve();
	return 0;
}
