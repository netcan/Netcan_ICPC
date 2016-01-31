/*************************************************************************
	> File Name: 1201.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-31 日 21:33:21 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 50000+5;
struct Dat{
	int a, b, c;
	bool operator<(const Dat &B) const {
		return b < B.b;
	}
} dat[MAXN];
int N;
int bit[MAXN];
bool used[MAXN];

void add(int i, int x) {
	while(i <= MAXN) {
		bit[i] += x;
		i += i&-i;
	}
}

int sum(int i) {
	int res = 0;
	while(i > 0) {
		res += bit[i];
		i -= i&-i;
	}
	return res;
}

void solve() {
	sort(dat, dat+N);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		// printf("[%d, %d] %d\n", dat[i].a, dat[i].b, dat[i].c);
		int c = sum(dat[i].b) - sum(dat[i].a-1); // 该区间已经选择的数的个数
		if(c < dat[i].c) {
			// printf("remain: %d have: %d\n", dat[i].c-c, c);
			ans += dat[i].c - c; // 补上
			int s = dat[i].b; // 从尾部开始选
			while(c < dat[i].c) {
				if(!used[s]) { // 没选过
					// printf("%d ", s);
					used[s] = true; // 标记
					add(s, 1);
					c++;
				}
				--s;
			}
			// printf("\n");
		}
	}
	printf("%d\n", ans);
}

int main() {
#ifdef Oj
	freopen("1201.in", "r", stdin);
	// freopen("1201.out", "w",stdout);
#endif
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d%d%d", &dat[i].a, &dat[i].b, &dat[i].c);
	solve();
	return 0;
}
