/*************************************************************************
	> File Name: 1166_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-19 二 14:29:06 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int T,N;
int bit[50000+5]; // [1, N]

int sum(int i) {
	int s = 0;
	while(i > 0) {
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i, int x) {
	while(i <= N) {
		bit[i] += x;
		i+=i&-i;
	}
}

void solve() {
	char cmd[10];
	int a, b;
	while(scanf("%s", cmd) && cmd[0] != 'E') {
		scanf("%d%d", &a, &b);
		if(cmd[0] == 'Q') printf("%d\n",sum(b) - sum(a-1));
		else if(cmd[0] == 'A') add(a, b);
		else if(cmd[0] == 'S') add(a, -b);
	}
}

int main() {
#ifdef Oj
	freopen("1166.in", "r", stdin);
	// freopen("1166_2.out", "w",stdout);
#endif
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		memset(bit, 0, sizeof(bit));
		scanf("%d", &N);
		int d;
		for(int i=1; i<=N; ++i) {
			scanf("%d", &d);
			add(i, d);
		}
		printf("Case %d:\n", t+1);
		solve();
	}
	return 0;
}
