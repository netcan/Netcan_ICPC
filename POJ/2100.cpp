/*************************************************************************
	> File Name: 2100.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-31 四 15:17:01 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
ll N;
struct grave {
	int l, r;
	grave(int l, int r) : l(l), r(r) {}
	bool operator<(const grave & b) const {
		return r - l > b.r - b.l;
	}
};
vector<grave> graves;

void solve() {
	int s, t;
	ll sum = 0;
	ll sq = 0;
	s = t = 0;
	graves.clear();
	for(;;) {
		while(ll(t)*t <= N && sum < N) {
			++t;
			sum += ll(t)*t;
		}
		if(sum < N || sq > N) break;

		if(sum == N) graves.push_back(grave(s, t));
		++s;
		sum -= ll(s)*s;
	}

	sort(graves.begin(), graves.end());
	printf("%lu\n", graves.size());
	for(int i=0; i<graves.size(); ++i) {
		int s = graves[i].l;
		int t = graves[i].r;
		printf("%d", t-s);
		for(int j=0; j<t-s; ++j) printf(" %d", s+j+1);
		printf("\n");
	}
}

int main() {
#ifdef Oj
	// freopen("2100.in", "r", stdin);
#endif
	while(scanf("%lld", &N) == 1) solve();
	return 0;
}
