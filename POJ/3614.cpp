/*************************************************************************
	> File Name: 3614.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-24 六 16:13:53 CST
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

int C, L;
typedef pair<int, int> P;
P cows[2502], bots[2502]; // 羊, first->minspf, second->maxspf， 防晒瓶first->spf, second->covers

void solve() {
	sort(cows, cows+C);
	sort(bots, bots+L);
	priority_queue<int, vector<int>, greater<int> > que; // maxspf的最小堆
	int ans = 0;
	int j = 0;
	// for(int i=1; i<C; ++i) cout << cows[i].first << cows[i].second << endl;
	// for(int i=0; i<L; ++i) cout << bots[i].first << bots[i].second << endl;

	for(int i=0; i<L; ++i) {
		while(j<C && cows[j].first <= bots[i].first) {
			que.push(cows[j].second); // minspf小于当前防晒霜的maxspf的最小堆
			++j;
		}

		while(!que.empty() && bots[i].second > 0) {
			if(que.top() >= bots[i].first) {
				--bots[i].second;
				++ans;
			}
			que.pop(); // 去掉，若无法满足条件也去掉，因为后面的防晒霜spf更大，更加不满足
		}
	}
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("3614.in", "r", stdin);
#endif
	cin >> C >> L;
	for(int i=0; i<C; ++i) cin >> cows[i].first >> cows[i].second;
	for(int i=0; i<L; ++i) cin >> bots[i].first >> bots[i].second;
	solve();
	return 0;
}
