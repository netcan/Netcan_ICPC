/*************************************************************************
	> File Name: B.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-20 日 14:29:25 CST
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
string room[102];

void solve() {
	int ans = 0;
	for(int i=0; i<n; ++i) {
		int cur = 1;
		for(int j=1; j<n; ++j)
			if(room[i] == room[j] && i!=j) ++cur;
		ans = max(ans, cur);
	}
	cout << ans << endl;

}

int main()
{
#ifdef Oj
	freopen("B.in", "r", stdin);
#endif
	while(cin >> n) {
		for(int i=0; i<n; ++i) cin >> room[i];
		solve();
	}
	return 0;
}
