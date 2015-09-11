/*************************************************************************
	> File Name: 1.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-10 四 20:48:01 CST
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
int a[1005];
map<int, int> num;
void solve() {
	cin >> n;
	int maxn;
	int maxc = 0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		num[a[i]]++;
		if(num[a[i]] > maxc) {
			maxc = num[a[i]];
			maxn = a[i];
		}
	}
	cout << maxn << endl;
}

int main()
{
#ifdef Oj
	freopen("1.in", "r", stdin);
#endif
	solve();
	return 0;
}
