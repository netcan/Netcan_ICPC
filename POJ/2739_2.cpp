/*************************************************************************
	> File Name: 2739.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-31 四 14:16:15 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> prime_sum;

void solve() {
	int s=0, t=0, sum = 0, ans = 0;
	for(int i=0; prime_sum[i] - prime_sum[i-1>0?i-1:0] <= N; ++i) {
		int j = lower_bound(prime_sum.begin(), prime_sum.end(), prime_sum[i] + N) - (prime_sum.begin());
		// printf("i:%d j:%d\n", i, j);
		if(j > i && prime_sum[j] - prime_sum[i] == N) ++ans;
	}

	printf("%d\n", ans);
}

int main() {
#ifdef Oj
	freopen("2739.in", "r", stdin);
#endif
	prime_sum.push_back(0);
	for(int i=2; i<=10000; ++i) {
		int j;
		for (j = 2;  j * j <= i; j++) if(i%j == 0) break;
		if(j * j > i) prime_sum.push_back(prime_sum.back()+i);
	}

	while(scanf("%d", &N) == 1 && N)
		solve();
	return 0;
}
