/*************************************************************************
	> File Name: 5112.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-02 Sun 14:40:20 CST
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
struct d {
	int t, x;
	friend bool operator < (const d &a, const d &b) {
		return a.t < b.t;
	}
} d[10005];
int N;

void solve() {
	double maxspeed;
	int Cased = 1;
	cin.sync_with_stdio(false);
	cin  >> T;
	while(T--) {
		cin >> N;
		for(int i=0; i<N; ++i)
			cin >> d[i].t >> d[i].x;
		sort(d, d+N);
		maxspeed = 0.0;
		for(int i=1; i<N; ++i) {
			double s = (fabs(d[i].x - d[i-1].x*1.0)) / (d[i].t - d[i-1].t*1.0);
			// printf("%f\n", s);
			if(maxspeed < s)
				maxspeed = s;
		}
		printf("Case #%d: %.2f\n", Cased++, maxspeed);
	}
}

int main()
{
#ifdef Oj
	freopen("5112.in", "r", stdin);
#endif
	solve();
	return 0;
}
