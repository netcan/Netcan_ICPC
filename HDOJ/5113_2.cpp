/*************************************************************************
	> File Name: 5113.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-03 Mon 15:15:44 CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <stack>
#include <set>
#include <numeric>
#include <utility>
#include <cstring>
using namespace std;

int N, M, K;
int Map[7][7];
int c[30];


bool DFS(int x, int y) {
	if(y == M)
		return DFS(x+1, 0);
	if(x == N)
		return true;
	for(int k=1; k<=K; ++k) { // 1到K枚举
		if(c[k] <= 0) continue;
		if(x && Map[x-1][y] == k) continue;
		if(y && Map[x][y-1] == k) continue;
		--c[k];
		Map[x][y] = k;
		if(DFS(x, y+1)) return true;
		++c[k];
	}
	return false;
}

void solve() {
	int T, Case = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &N, &M, &K);
		int maxn = 0;
		for(int i=1; i<=K; ++i) { // 注意这里从1到K，以防DFS颜色枚举数量出错！！！！
			scanf("%d", &c[i]);
			maxn = max(maxn, c[i]);
		}
		if(maxn > M*N/2 + M*N%2)  {
			printf("Case #%d:\nNO\n", Case++);
			continue;
		}
		memset(Map, -1, sizeof(Map));
		if(DFS(0, 0)) {
			printf("Case #%d:\nYES\n", Case++);
			for(int i=0; i<N; ++i) {
				for(int j=0; j<M; ++j) {
					if(j) putchar(' ');
					printf("%d", Map[i][j]);
				}
				puts("");
			}
		}
		else
			printf("Case #%d:\nNO\n", Case++);

	}
}

int main()
{
#ifdef Oj
	freopen("5113.in", "r", stdin);
#endif
	solve();
	return 0;
}
