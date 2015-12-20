/*************************************************************************
	> File Name: 1001.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-20 日 13:56:49 CST
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

int n, m;
int A[55], B[55];
bool c(int x) {
	double a_cov=0, b_cov=0;
	double cur_a_cov=0, cur_b_cov=0;
	for(int i=0; i<n-1; ++i)	a_cov += A[i];
	cur_a_cov = a_cov / (n-1);
	a_cov += x;
	a_cov /= n;
	for(int i=0; i<m; ++i) b_cov += B[i];
	cur_b_cov = (b_cov+x)/(m+1);
	b_cov /= m;
	if(cur_a_cov > a_cov && cur_b_cov > b_cov) return true;
	else return false;
}

void solve() {
	int mins=200, maxs=-1;
	for(int i=0; i<=100; ++i)
		if(c(i)) {
			mins = min(mins, i);
			maxs = max(maxs, i);
		}
	printf("%d %d\n", mins==200?-1:mins, maxs==-1?-1:maxs);
}

int main()
{
#ifdef Oj
	freopen("1001.in", "r", stdin);
#endif
	while(cin >> n >> m) {
		for(int i=0; i<n-1; ++i) cin >> A[i];
		for(int i=0; i<m; ++i) cin >> B[i];
		solve();
	}
	return 0;
}
