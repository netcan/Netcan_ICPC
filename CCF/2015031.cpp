/*************************************************************************
	> File Name: 2015031.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-10 四 21:59:36 CST
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
int img[1002][1002];
int newimg[1002][1002];
void solve() {
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> img[i][j];
	swap(m, n);
	for(int i=0; i<n; ++i)  // 行
		for(int j=0; j<m; ++j)  // 列
			newimg[i][j] = img[j][i];

	for(int i=0; i<n/2; ++i)
		for(int j=0; j<m; ++j)  // 列
			swap(newimg[i][j], newimg[n-i-1][j]);




	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j)
			cout << newimg[i][j] << " ";
		cout <<endl;
	}
}

int main()
{
#ifdef Oj
	freopen("2015031.in", "r", stdin);
#endif
	solve();
	return 0;
}
