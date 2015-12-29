/*************************************************************************
	> File Name: 3061.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-29 二 10:04:43 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

int N, S;
int num[100005];
int sum[100005]; // sum[s]=num[0]+num[1]+...+num[s]


void solve() {

	int ans = numeric_limits<int>::max();
	for(int i=0; i<N; ++i) {
		// printf("i=%d, j=%ld\n", i, lower_bound(sum+i, sum+N, sum[i]+S)-sum);
		// int j = lower_bound(sum+i, sum+N, sum[i]+S) - sum; // 求出最小的j
		int lb = -1, ub = N; // [0, ub)
		while(ub - lb > 1) {
			int mid = (ub + lb) >> 1;
			if(sum[mid] >= sum[i]+S) ub = mid; // (lb, ub]
			else lb = mid;
		}
		// printf("j=%d, ub=%d\n", j , ub);

		if(ub < N && ub > i) ans = min<int>(ans, lower_bound(sum+i, sum+N, sum[i]+S)-sum-i); // 枚举求出最小的j-i
	}
	printf("%d\n", ans==numeric_limits<int>::max()?0:ans);
}

int main() {
#ifdef Oj
	freopen("3061.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &S);
		sum[0] = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", num+i);
			sum[i] = sum[i-1>=0?i-1:0] + num[i];
		}
		solve();
	}
	return 0;
}
