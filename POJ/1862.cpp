/*************************************************************************
	> File Name: 1862.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-19 六 20:39:09 CST
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
int w[10005];

void solve() {
	sort(w, w+N);
	double m = w[N-1];
	for(int i=N-2; i>=0; --i)
		m = 2*sqrt(m*w[i]);
	printf("%.3f\n", m);
}

int main()
{
#ifdef Oj
	freopen("1862.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; ++i) cin >> w[i];
	solve();
	return 0;
}
