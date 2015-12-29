/*************************************************************************
	> File Name: 3320.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-29 二 14:58:10 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int P;
int id[1000000+50];
map<int, int> cnt;

void solve() {
	int s = 0, t = 0;
	int ans = P;
	int lstsum = 0, crtsum = 0;
	while(t < P) {
		if(cnt[id[t++]]++ == 0) ++crtsum;

		if(crtsum > lstsum) {
			ans = t - s;
			lstsum  = crtsum;
			// printf("%d\n", ans);
		}

		while(s < t && cnt[id[s]] > 1) {
			cnt[id[s++]]--;
		}
		ans = min(ans, t-s);

	}
	cout << ans << endl;
}

int main() {
#ifdef Oj
	freopen("3320.in", "r", stdin);
#endif
	scanf("%d", &P);
	for (int i = 0; i < P; ++i) scanf("%d", &id[i]);
	solve();
	return 0;
}
