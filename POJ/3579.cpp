/*************************************************************************
    > File Name: 3579.cpp
      > Author: Netcan
      > Blog: http://www.netcan666.com
      > Mail: 1469709759@qq.com
      > Created Time: 2015-12-27 日 11:37:15 CST
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

int N;
int CN2 = 0;
int X[100005];

bool C(int x) { // 验证x作为中位数 x = X[j] - X[i] 是否太小
    int cnt = 0;
    for(int i=0; i<N; ++i) {
		cnt += N- (lower_bound(X+i, X+N, X[i]+x) - X); // 统计差值>=x的个数
		// printf("%d\n", lower_bound(X+i, X+N, X[i]+x) - (X));
	}
	// cout << cnt << endl;
    return cnt > CN2>>1;
}

void solve() {
    sort(X, X+N);
	CN2 = N*(N-1) >> 1;
	// C(8);

	int lb = 0, ub = 1000000001;
	while(ub - lb > 1) {
		int mid = (ub + lb) >> 1;
		if(C(mid)) lb = mid; // 中位数过小，半闭半开区间[lb, ub)
		else ub = mid;
	}
	printf("%d\n", lb);
}

int main()
{
#ifdef Oj
    freopen("3579.in", "r", stdin);
#endif
    while(scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++i) scanf("%d", X+i);
        solve();
    }
    return 0;
}
