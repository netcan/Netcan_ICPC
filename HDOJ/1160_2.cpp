/*************************************************************************
	> File Name: 1160_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-29 Wed 16:43:46 CST
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
const int max_n = 1005;
struct mice {
	int w, s, id;
	friend bool operator<(const mice &a, const mice &b) {
		if(a.w!=b.w)
			return a.w>b.w;
		else
			return a.s<b.s;
	}
} mice[max_n];
int dp[max_n];
int mark[max_n];
int s[max_n], ss, t = 0;

void solve() {
	int n=1;
	while(cin >> mice[n].w >> mice[n].s) {
		mice[n].id = n;
		n++;
	}
	for(int i=0; i<max_n; ++i)
		s[i] = i;

	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	// for(int i=1; i<n; ++i)
		// cout << i << "." <<  mice[i].w << " " << mice[i].s << endl;
	sort(mice+1, mice+n);
	int maxn = 0;
	int marked;
	for(int i=1; i<n; ++i) {
		maxn = 0;
		for(int j=1; j<i; ++j)
			if(mice[j].w > mice[i].w && mice[j].s < mice[i].s) {
				if(maxn < dp[j]) {
					maxn = dp[j];
					marked = mice[j].id;
				}
			}
		if(maxn)
			s[mice[i].id] = marked;
		dp[i] = maxn+1;
		if(t < dp[i]) {
			t = dp[i];
			ss = mice[i].id;
		}
	}
	cout << t << endl;
	if(t == 1)
		cout << 1 << endl << 1 << endl;
	else {
		while(ss!=s[ss]) {
			cout << ss << endl;
			ss = s[ss];
		}
		cout << ss << endl;
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
