/*************************************************************************
	> File Name: 3176.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-20 日 14:50:54 CST
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
int	tri[351][351];
void solve() {
	// for(int i=0; i<n; ++i) {
		// for(int j=0; j<=i; ++j) cout << tri[i][j] <<  " ";
		// cout <<endl;
	// }

	for(int i=n-1; i>=1; --i)
		for(int j=0; j<=i; ++j) tri[i-1][j] += max(tri[i][j], tri[i][j+1]);
	cout << tri[0][0] << endl;
}

int main()
{
#ifdef Oj
	freopen("3176.in", "r", stdin);
#endif
	cin >> n;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<=i; ++j) {
			cin >> tri[i][j];
		}
	}
	solve();
	return 0;
}
