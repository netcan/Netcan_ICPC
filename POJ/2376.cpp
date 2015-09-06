/*************************************************************************
	> File Name: 2376.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-02 三 09:25:34 CST
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

struct interval {
	int s, e;
	bool operator<(const interval &b) const {
		if(s == b.s)
			return e < b.e; //　终点从小到大
		return s < b.s; // 起点从小到大
	}
} I[25010];
int N, T;

void solve() {
	scanf("%d%d", &N, &T);
	int maxe = 0, mins = 1<<30;
	for(int i=0; i<N; ++i) {
		scanf("%d%d", &I[i].s, &I[i].e);
		maxe = max(maxe, I[i].e);
		mins = min(mins, I[i].s);
	}
	if(maxe < T || mins > 1) {
		printf("-1\n");
		return;
	}
	sort(I, I+N);
	int j = 0;
	int t = I[j].e;
	while(I[j].s == 1) {
		t = I[j].e;
		++j;
	}
	int ans = 1;
	int maxt = -1;

	for(int i=j; i<N; ++i) {
		if(t >= T) break; // 覆盖完成
		if( I[i].s > t+1) {
			ans = -1;
			break;
		}

		if(maxt == -1) maxt = I[i].e;
		if(i+1 < N && I[i+1].s <= t+1) {
			maxt = max(maxt, I[i+1].e);
			continue;
		}
		else  {
			t = maxt;
			maxt = -1;
			++ans;
		}
	}
	if(t < T)
		ans = -1;

	cout << ans << endl;

}

int main()
{
#ifdef Oj
	freopen("2376.in", "r", stdin);
#endif
	solve();
	return 0;
}
