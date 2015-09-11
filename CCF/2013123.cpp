/*************************************************************************
	> File Name: 3.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-10 四 21:05:08 CST
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

int n;
int high[1002];
bool cmp(int a, int b) {
	return a < b;
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> high[i];
	// for(int i=0; i<n; ++i)
		// cout << high[i] << endl;
	// cout << "---" << endl;
	int maxs = 0;

	for(int i=0; i<n; ++i) {
		int cnt = high[i];
		for(int j=i+1; j<n; ++j) {
			if(high[j] < high[i]) break;
			cnt+=high[i];
			// printf("%d %d %d\n", i, j, cnt);
		}
		for(int j=i-1; j>=0; --j) {
			if(high[j] < high[i]) break;
			cnt+=high[i];
		}
		maxs = max(maxs, cnt);
	}

	cout << maxs << endl;

}

int main()
{
#ifdef Oj
	freopen("3.in", "r", stdin);
#endif
	solve();
	return 0;
}
