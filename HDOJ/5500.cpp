/*************************************************************************
	> File Name: 1002.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-10 六 19:30:48 CST
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
int T, n;
int data[20];
bool is_ok() {
	for(int i=1; i<=n; ++i) if(data[i] != i) return false;
	return true;
}

void solve() {
	int cur = n;
	int ans = 0;
	for(int i=n; i>=1; --i) {
		if(data[i] == cur) --cur;
		else ++ans;
	}
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("1002.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i=1; i<=n; ++i) cin >> data[i];
		solve();
	}
	return 0;
}
