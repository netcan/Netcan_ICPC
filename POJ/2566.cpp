/*************************************************************************
	> File Name: 2566.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-29 二 19:34:57 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <algorithm>
using namespace std;

int N, K;
pair<int,int> sum[100005]; // index->presum, value->id;
int T;


void solve() {
	sort(sum, sum+1+N); // 排个序使sum单调

	for (int i = 0; i < K; ++i) {
		scanf("%d", &T);
		int s = 0, t = 1; // (s, t]
		int l = sum[s].second, u = sum[t].second; // 这里是巨坑啊。初始化不应该用0和1
		if(l > u) swap(l, u);
		int S = sum[t].first - sum[s].first; // a[1]
		int res = S;
		int delta = abs(S - T);
		for(;;) {
			// printf("S:%d l: %d u: %d\n", S, l, u);
			while(t < N && S < T) {
				S = sum[++t].first - sum[s].first;
				if(delta > abs(S - T)) {
					delta = abs(S-T);
					l = sum[s].second;
					u = sum[t].second;
					if(l > u) swap(l, u);
					res = S;
				}
			}
			if(S < T) break;


			if(t-s>1) {
				S = sum[t].first - sum[++s].first;
				if(delta > abs(S - T)) {
					delta = abs(S-T);
					l = sum[s].second;
					u = sum[t].second;
					if(l > u) swap(l, u);
					res = S;
				}
			}
			else S = numeric_limits<int>::min(); // 当t-s<=1的时候就应该轮到t前进了
		}
		printf("%d %d %d\n", res, l+1, u);
	}
}

int main() {
#ifdef Oj
	freopen("2566.in", "r", stdin);
#endif
	while(scanf("%d%d", &N, &K)==2) {
		if(N == K && K == 0) break;
		int d;
		sum[0] = make_pair<int, int>(0, 0);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &d);
			sum[i] = make_pair<int, int>(sum[i-1].first+d, i); // sum[k]=a[1]+a[2]+...+a[k]
		}
		solve();
	}
	return 0;
}
