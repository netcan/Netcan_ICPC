/*************************************************************************
	> File Name: 1065.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-05 一 17:14:27 CST
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
struct wood {
	int w, l;
	bool mark;
	bool operator<(const wood &b) const{
		if(l == b.l) return w < b.w;
		return l < b.l;
	}
} woods[5005];

void solve() {
	sort(woods, woods+n);
	int setup = 0;
	int pl ,pw;
	for(int i=0; i<n; ++i) {
		if(!woods[i].mark) {
			pl = woods[i].l;
			pw = woods[i].w;
			++setup;
			woods[i].mark = true;
		}
		for(int j=i+1; j<n; ++j) {
			if(woods[j].l >= pl && woods[j].w >= pw && !woods[j].mark) {
				woods[j].mark = true;
				pl = woods[j].l;
				pw = woods[j].w;
			}
		}
	}
	cout << setup << endl;
}

int main()
{
#ifdef Oj
	freopen("1065.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i=0; i<n; ++i) {
			cin >> woods[i].l >>woods[i].w;
			woods[i].mark = false;
		}
		solve();
	}
	return 0;
}
