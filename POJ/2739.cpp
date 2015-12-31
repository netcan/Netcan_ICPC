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
using namespace std;

int N;
vector<int> prime_sum;

void solve() {
	// for(int i=1; i<5; ++i) printf("%d: %d\n", i, prime_sum[i]);

	int s=0, t=0, sum = 0, ans = 0;
	// printf("prime_sum[%d]:%d prime_sum[%d]:%d sum:%d\n", s, prime_sum[s], t, prime_sum[t], sum);
	// cout << sum << endl;

	for(;;) {
		while(t+1<prime_sum.size() && sum < N)
			sum = prime_sum[++t] - prime_sum[s];

		// printf("prime_sum[%d]:%d prime_sum[%d]:%d sum:%d\n", s, prime_sum[s], t, prime_sum[t], sum);

		if(sum < N) break;
		if(sum == N) ++ans;
		sum = prime_sum[t] - prime_sum[++s];
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
