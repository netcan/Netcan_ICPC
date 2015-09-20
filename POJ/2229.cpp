/*************************************************************************
	> File Name: 2229.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-20 日 15:42:21 CST
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
int a[1000005];

void solve() {
	a[1] = 1;
	a[2] = 2;
	for(int i=3; i<=N; ++i)
		a[i] = (a[i-1] + (i%2==0 ? a[i/2] : 0)) % 1000000000;
	cout << a[N] << endl;
}

int main()
{
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> N;
	solve();
	return 0;
}
