/*************************************************************************
	> File Name: 3264.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-31 日 14:43:42 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN =  50000+25;
const int B = 200; // 每个桶的大小为200个元素
int height[MAXN];
vector<int> bucket[MAXN/B];
int N, Q;

void solve() {
	for (int i = 0; i < N/B; ++i) // 对每个桶进行排序
		sort(bucket[i].begin(), bucket[i].end());
	for (int i = 0; i < Q; ++i) {
		int l, r;
		int maxh = 0, minh = 1<<30;
		scanf("%d%d", &l, &r); --l;
		// [l, r)，逐个求出不包含部分的最值
		while(l < r && l%B != 0) {
			maxh = max(height[l], maxh);
			minh = min(height[l], minh);
			++l;
		}
		while(l < r && r%B != 0) {
			--r;
			maxh = max(height[r], maxh);
			minh = min(height[r], minh);
		}
		// 剩下的是完全包含部分
		while(l < r) {
			maxh = max(*(bucket[l/B].end()-1), maxh);
			minh = min(*(bucket[l/B].begin()), minh);
			l += B;
		}
		printf("%d\n", maxh - minh);
	}

}

int main() {
#ifdef Oj
	freopen("3264.in", "r", stdin);
	// freopen("3264.out", "w",stdout);
#endif
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		scanf("%d", height+i);
		bucket[i/B].push_back(height[i]);
	}
	solve();
	return 0;
}
