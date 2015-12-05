/*************************************************************************
	> File Name: 0005.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-05 六 10:01:22 CST
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

inline int gcd(int a, int b) {
	return b==0?a:gcd(b, a%b);
}
inline int lcm(int a, int b) {
	return a/gcd(a, b) * b;
}

int a, b;
void solve() {
	printf("%d %d\n", gcd(a, b), lcm(a, b));
}

int main()
{
#ifdef Oj
	freopen("0005.in", "r", stdin);
#endif
	while(cin >> a >> b) {
		solve();
	}
	return 0;
}
