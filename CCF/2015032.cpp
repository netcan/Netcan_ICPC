/*************************************************************************
	> File Name: 2015032.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-10 四 22:22:02 CST
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

struct Num {
	int x, times;
	bool operator<(const Num &b) const {
		if(times == b.times)
			return x < b.x;
		return times > b.times;
	}
}num[1002];
map<int,int> cnt;

void solve() {
	cin >> n;
	int x;
	for(int i=0; i<n; ++i) {
		cin >> x;
		++cnt[x];
	}
	int k = 0;
	for(map<int, int>::iterator p=cnt.begin(); p!=cnt.end(); ++p) {
		num[k].x = p->first;
		num[k].times = p->second;
		++k;
	}


	sort(num, num+k);
	for(int i=0; i<k; ++i)
		cout << num[i].x << " " << num[i].times << endl;

}

int main()
{
#ifdef Oj
	freopen("2015032.in", "r", stdin);
#endif
	solve();
	return 0;
}
