/*************************************************************************
	> File Name: 1160.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-29 Wed 15:02:52 CST
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

struct mice {
	int w, s, id;
	friend bool operator<(const mice &a, const mice &b) {
		if(a.w != b.w)
			return a.w > b.w;
		return a.s < b.s;
	}
} Mice[1005];

int dp[1005];
int vis[1005];

void solve() {
	int n=1;
	while(cin >> Mice[n].w >> Mice[n].s) {
		Mice[n].id = n;
		n++;
	}
	for(int i=0; i<1005; ++i)
		vis[i] = i;

	// for(int i=1; i<n; ++i)
		// cout << Mice[i].w << " " << Mice[i].s << " " << Mice[i].id << endl;

	sort(Mice+1, Mice+n);
	memset(dp, 0, sizeof(dp));
	// for(int i=0; i<n; ++i)
		// cout << Mice[i].w << " " << Mice[i].s << endl;
	int maxn, mark, m=0, t;
	for(int i=1; i<n; ++i) {
		maxn = 0;
		for(int j=1; j<i; ++j)
			if(Mice[j].w > Mice[i].w && Mice[j].s < Mice[i].s) {
				if(maxn < dp[j])  {
					maxn = dp[j];
					mark = Mice[j].id;
				}
			}
		if(maxn)
			vis[Mice[i].id] = mark;
		dp[i] = maxn+1;
		if(m<dp[i]) {
			m = dp[i];
			t = Mice[i].id;
		}
	}

	if(m==1)
		cout << 1 << endl << 1 << endl;
	else {
		cout << m << endl;
		while(vis[t]!=t) {
			cout << t << endl;
			t = vis[t];
		}
		cout << t << endl;
	}
}

int main()
{
#ifdef Oj
	 freopen("1160.in", "r", stdin);
#endif
	solve();
	return 0;
}
