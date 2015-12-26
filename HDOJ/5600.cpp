/*************************************************************************
	> File Name: 1001.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-26 六 18:53:59 CST
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

int T, N;
bool bulb[1000005];
void show_bulb() {
	for(int i=0; i<N; ++i) printf("%d ", bulb[i]);
	printf("\n");
}

void solve() {
	if(N==1) {
		if(bulb[0]) puts("YES");
		else puts("NO");
		return;
	}
	for(int i=0; i<N;) {
		//printf("pos(%d) ", i);
		//show_bulb();
		if(bulb[i] == true) {
			bulb[i] = false;
			++i;
		}
		else {
			++i;
			if(i<N) bulb[i] = !bulb[i];
			else bulb[i-1] = !bulb[i-1];
		}
	}
	if(bulb[N-1]) printf("NO\n");
	else printf("YES\n");
}

int main()
{
#ifdef Oj
	freopen("1001.in", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0; i<N; ++i) scanf("%d", &bulb[i]);
		solve();
	}
	return 0;
}
