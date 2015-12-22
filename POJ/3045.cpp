/*************************************************************************
	> File Name: 3045.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-22 二 17:38:43 CST
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
int Wsum = 0;
struct cow {
	int W, S;
	bool operator<(const cow &b) const {
		return W - b.S > b.W - S; // W-S从大到小排序
	}
} cows[50005];

void solve() {
	sort(cows, cows+N);
	int risk = -1000000002; // 因为risk可能为负数
	for(int i=0; i<N; ++i)
		printf("w:%d s:%d\n", cows[i].W, cows[i].S);

	for(int i=0; i<N; ++i) {
		// printf("%d\n", cows[i].W);
		Wsum -= cows[i].W;
		risk = max(risk, Wsum - cows[i].S);
	}
	cout << risk << endl;
}

int main()
{
#ifdef Oj
	freopen("3045.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> cows[i].W >> cows[i].S;
		Wsum += cows[i].W;
	}
	solve();
	return 0;
}
