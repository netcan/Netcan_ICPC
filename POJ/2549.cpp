/*************************************************************************
	> File Name: 2549.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-10 日 17:02:24 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int N;
int data[1024];

void solve() {
	sort(data, data+N);
	int n = unique(data, data+N) - data; // 去重
	int ans = 0;
	for(int d=n-1; d>=0; --d) { // d从大到小枚举
		for(int i=0; i<n-3; ++i) { // 开始枚举
			int s = i + 1;
			int t = n - 1;
			while(s < t) {
				int sum = data[i] + data[s] + data[t];
				if(sum < data[d]) ++s;
				else if(sum > data[d]) --t;
				else {
					if(i==d || s==d || t == d) break; // 后面的没必要枚举了。因为已经有等于d的值存在
					else {
						printf("%d\n", data[d]);
						return;
					}
				}
			}
		}
	}

	puts("no solution");
}

int main() {
#ifdef Oj
	freopen("2549.in", "r", stdin);
	// freopen("2549.out", "w", stdout);
#endif
	while(scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++i) scanf("%d", &data[i]);
		solve();
	}
	return 0;
}
