/*************************************************************************
	> File Name: 3185.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-02 六 13:38:55 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool bowls[20+5]; // 目标全部翻转为0
bool flip[20+5]; // flip[i]表示i是否需要翻转

bool get_stat(int i) { // 第i个碗的状态
	int res = bowls[i];
	for(int d=-1; d<=1; ++d) {
		int nd = i + d;
		if(nd >= 0 && nd < 20) res += flip[nd];
	}
	return res & 1;
}

int calc() {
	for(int i=1; i<20; ++i)
		if(get_stat(i-1)) flip[i] = true;
	if(get_stat(19)) return -1;
	int res = 0;
	for(int i=0; i<20; ++i) if(flip[i]) ++res;
	return res;
}

void solve() {
	int ans = -1;
	for(int i=0; i<(1<<1); ++i) {// 第一个碗有两种状态
		memset(flip, 0, sizeof(flip));
		for(int j=0; j<1; ++j) flip[0] = (i >> j) & 1;
		int step = calc();
		if(step >= 0 && (ans < 0 || ans > step)) ans = step;
	}
	cout << ans << endl;
}

int main() {
#ifdef Oj
	freopen("3185.in", "r", stdin);
#endif
	for(int i=0; i<20; ++i) cin >> bowls[i];
	solve();
	return 0;
}
