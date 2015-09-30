/*************************************************************************
	> File Name: 1001.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-26 六 19:03:54 CST
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
string s;

void solve() {
	int ans = 0;
	int l = 0;
	for(int i=0; i<s.length(); ++i) {
		if(s[i] == '(') ++l;
		else
			if(l>0) --l, ++ans;
	}
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("1001.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> s;
		solve();
	}
	return 0;
}
