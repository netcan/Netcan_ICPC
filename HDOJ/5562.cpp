/*************************************************************************
	> File Name: 1001.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-14 六 19:02:19 CST
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
int T;
int n, V;
int klk[100005];
// 这么水的题目都能挂掉。。

void solve() {
	sort(klk, klk+n);
	long long sum = 0;
	int ans = 0;
	for(int i=0; i<n; ++i)
		if(sum <= V) {
			sum += klk[i];
			++ans;
		}
	printf("%d\n", ans-1);
}

int main()
{
#ifdef Oj
	freopen("5562.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &V);
		for(int i=0; i<n; ++i) scanf("%d", &klk[i]);
		solve();
	}
	return 0;
}
