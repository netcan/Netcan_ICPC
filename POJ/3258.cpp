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
	int lst = 0; // 从第一个石头开始试
	for(int i=1; i<N-M; ++i) { // 保留N-M个石头
		int crt = lst + 1;
		while(crt < N && D[crt] - D[lst] < d) ++crt;
		if(crt == N) return false;
		lst = crt;
	}
	return true;
}

void solve() {
	sort(D, D+N);
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
	D[0] = 0, D[N+1] = L;
	N+=2;
	solve();
	return 0;
}
