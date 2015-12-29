/*************************************************************************
	> File Name: 3061_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-29 二 11:06:09 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits>
using namespace std;

int N, S;
int a[100005];

void solve() {
	int s, t, sum;
	int ans = numeric_limits<int>::max();
	s = t = sum = 0;
	while(t < N) {
		sum += a[t++];
		// printf("sum: %d s=%d t=%d\n", sum, s, t);
		if(sum >= S) {
			while(sum >= S && s < t) {
				sum -= a[s++];
			// printf("sum: %d s=%d t=%d\n", sum, s, t);
			}
			if(s>0) sum+=a[--s];
		}

		if(sum >= S) ans = min(ans, t-s);
	}
	// cout << ans << endl;
	printf("%d\n", ans==numeric_limits<int>::max()?0:ans);

}

int main() {
#ifdef Oj
	freopen("3061.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N,&S);
		for (int i = 0; i < N; ++i)
			scanf("%d", a+i);
		solve();
	}
	return 0;
}
