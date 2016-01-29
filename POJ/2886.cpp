/*************************************************************************
	> File Name: 2886.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-29 五 10:31:27 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 500000 + 5;
int factors[MAXN];
int N, K;
int bit[MAXN]; // 维护下标

struct Kid{
	char name[15];
	int card;
} kid[MAXN];

void init_factors() { // 预处理因子数
	fill(factors+1, factors+MAXN, 1);
	for(int i=2; i<MAXN; ++i)
		if(factors[i] == 1)
			for(int j=i; j<MAXN; j+=i) {
				int k = 0;
				for(int m=j; m % i == 0; m/=i, ++k);
				factors[j] *= k+1;
			}
}

void add(int i, int x) {
	while(i <= N) {
		bit[i] += x;
		i+=i&-i;
	}
}

int sum(int i) {
	int res = 0;
	while(i>0) {
		res += bit[i];
		i-=i&-i;
	}
	return res;
}

int find(int x) { // 找出下标为x的小孩的编号
	int lb = 0, ub = N;
	while(ub - lb > 1) { // (lb, ub]
		int mid = (ub + lb) >> 1;
		if(sum(mid) >= x) ub = mid;
		else lb = mid;
	}
	return ub;
}

void solve() {
	int cnt = N, cur = K, curi = K; // 圈圈中剩余的孩子数量cnt，当前孩子编号cur，当前孩子下标curi
	int maxi = 0, maxf = 0;

	while(cnt > 1) {
		// printf("cur: %d", cur);
		if(factors[N-cnt+1] > maxf) {
			maxf = factors[N-cnt+1];
			maxi = cur;
		}
		add(cur, -1); // 当前孩子出队
		--cnt; // 剩余数少一
		if(kid[cur].card > 0) // 求出下一个出队的孩子的下标
			curi = (curi - 1 + kid[cur].card) % cnt;
		else
			curi = ((curi + kid[cur].card) % cnt + cnt) % cnt;
		if(curi == 0) curi = cnt;
		// printf(" curi: %d\n", curi);
		cur = find(curi); // 求出编号
	}
	// printf("cur: %d\n", cur);

	// 检查最后一个出队的孩子
	if(factors[N-cnt+1] > maxf) {
		maxf = factors[N-cnt+1];
		maxi = cur;
	}

	printf("%s %d\n", kid[maxi].name, maxf);
}

int main() {
#ifdef Oj
	freopen("2886.in", "r", stdin);
	// freopen("2886.out", "w",stdout);
#endif
	init_factors();
	while(scanf("%d%d", &N, &K) == 2) {
		memset(bit, 0, sizeof(bit));
		for(int i=1; i<=N; ++i) {
			scanf("%s%d", kid[i].name, &kid[i].card);
			add(i, 1);
		}
		solve();
	}
	return 0;
}
