/*************************************************************************
	> File Name: 2104.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-31 日 09:31:55 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;
const int B = 1200;
int N, M;
int A[MAXN]; // 数据
vector<int> bucket[MAXN/B]; // 桶
int Asort[MAXN]; // 排序后的数据

void solve() {
	for(int i=0; i<N; ++i) {
		bucket[i/B].push_back(A[i]);
		Asort[i] = A[i];
	}
	sort(Asort, Asort+N);
	for(int i=0; i<N/B; ++i) sort(bucket[i].begin(), bucket[i].end()); // 每个桶进行排序
	int l, r, k;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &l, &r, &k);
		int lb = -1, ub = N - 1; // (lb, ub]
		while(ub - lb > 1) {
			int mid = (ub + lb) >> 1, x = Asort[mid];
			int tl = l-1, tr = r, c = 0; // 左右边界tl, tr，<=x的个数c
			// 以下用函数调用会超时= =
			while(tl < tr && tl % B != 0) if(A[tl++] <= x) ++c;
			while(tl < tr && tr % B != 0) if(A[--tr] <= x) ++c;
			while(tl < tr) {
				int b = tl / B;
				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
				tl += B;
			}
			if(c<k) lb = mid;
			else ub = mid;
		}
		printf("%d\n", Asort[ub]);
	}
}

int main() {
#ifdef Oj
	freopen("2104.in", "r", stdin);
	// freopen("2104.out", "w",stdout);
#endif
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	solve();
	return 0;
}
