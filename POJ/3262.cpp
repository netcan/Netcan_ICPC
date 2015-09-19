/*************************************************************************
	> File Name: 3262.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-19 六 21:04:14 CST
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

int N;
struct Cow {
	int T, D;
	double dt;
	bool operator<(const Cow &b) const {
		return dt > b.dt;
	}
} cow[100005];

void solve() {
	sort(cow, cow+N);
	long long res=0, tt=0;
	for(int i=0; i<N; ++i) {
		res += tt*cow[i].D;
		tt+=2*cow[i].T;
	}
	cout << res << endl;
}

int main()
{
#ifdef Oj
	freopen("3262.in", "r", stdin);
#endif
	// cin.sync_with_stdio(false);
	scanf("%d", &N);
	for(int i=0; i<N; ++i) {
		scanf("%d%d", &cow[i].T, &cow[i].D);
		cow[i].dt = cow[i].D*1.0/cow[i].T;
	}

	solve();
	return 0;
}
