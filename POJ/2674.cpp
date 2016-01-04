/*************************************************************************
	> File Name: 2674.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-04 一 17:27:45 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
float L, V;
struct inhabit {
	float pos;
	char name[255];
} inhabits[32000+5];

float maxL;
int maxI;


void solve() {
	int cnt=0; // 统计和最后掉下来那个居民相反方向的居民数量。
	if(inhabits[maxI].pos >= 0) { // 右边
		for(int i=maxI+1; i<N; ++i) if(inhabits[i].pos < 0) ++cnt;
	}
	else { // 左边
		for(int i=maxI-1; i>=0; --i) if(inhabits[i].pos > 0) --cnt;
	}

	printf("%13.2f %s\n", int(maxL/V*100.0)/100.0, inhabits[maxI+cnt].name);
}

int main() {
#ifdef Oj
	freopen("2674.in", "r", stdin);
#endif
	char p;
	while(scanf("%d", &N) == 1) {
		if(N == 0) break;
		maxL = -1;
		float l;
		scanf("%f%f", &L, &V);
		for(int i=0; i<N; ++i) {
			getchar();
			scanf("%c%f%s", &p, &inhabits[i].pos, inhabits[i].name);
			if(p=='n' || p=='N') {
				l = inhabits[i].pos;
				inhabits[i].pos = -inhabits[i].pos;
			}
			else l = L - inhabits[i].pos;

			if(maxL < 0 || maxL < l) {
				maxL = l;
				maxI = i;
			}
		}
		solve();
	}
	return 0;
}
