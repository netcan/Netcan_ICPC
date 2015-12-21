/*************************************************************************
	> File Name: 3258.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-21 一 15:28:36 CST
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

int L, N, M;
int D[50005];

bool C(int d) {
	// 这里从第一块石头开始选取，表示第一块是必须保留的，然而终点石头无需考虑，因为能够保留N-M块石头的话，且间距>=d块的石头，那么最后一块可以随意选择，可看做选择保留最后一块即可。
	int lst = 0; // 从第一个石头开始试
	for(int i=1; i<N-M; ++i) { // 保留N-M个石头
		int crt = lst + 1;
		while(crt < N && D[crt] - D[lst] < d) ++crt; // 选取下一个保留的石头
		if(crt == N) return false; // 没有更多符合间距>=d的石头了
		lst = crt;
	}
	return true; // 能够保留N-M块石头
}

void solve() {
	sort(D, D+N); // 按距离排序
	// for(int i=0; i<N; ++i) printf("%d ", D[i]);
	int lb = 0, ub = 1000000005;
	while(ub - lb > 1) {
		int mid=(lb + ub) >> 1;
		if(C(mid)) lb = mid; // 半闭半开区间[lb, ub)
		else ub = mid;
	}
	printf("%d\n", lb);
}

int main()
{
#ifdef Oj
	freopen("3258.in", "r", stdin);
#endif
	scanf("%d%d%d", &L, &N, &M);
	for(int i=1; i<=N; ++i) scanf("%d", &D[i]);
	// 这里将起始石头和终点石头都算进去了，方便后面计算距离，以选取保留的石头
	D[0] = 0, D[N+1] = L;
	N+=2;
	solve();
	return 0;
}
