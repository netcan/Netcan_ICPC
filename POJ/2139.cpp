/*************************************************************************
	> File Name: 2139.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-11 三 16:05:46 CST
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
int N, M; // 牛数量，电影数量
int d[305][305];
void floyd() {
	for(int k=1; k<=N; ++k)
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]); // 求出各个牛的最小分隔度
	return;
}

void solve() {
	floyd();
	double min_av_deg = 9999999.0;
	for(int i=1; i<=N; ++i) {
		int sum = 0;
		for(int j=1; j<=N; ++j) {
			sum+=d[i][j];
		}
		min_av_deg = min(min_av_deg, sum*1.0/(N-1)*1.0);
	}
	cout << int(min_av_deg*100) << endl;
}

int main()
{
#ifdef Oj
	freopen("2139.in", "r", stdin);
#endif

	cin >> N >> M;
	memset(d, 0x3f, sizeof(d));
	for(int i=1; i<=N; ++i) d[i][i] = 0;
	int cows[302];
	int c;
	for(int i=0; i<M; ++i) {
		cin >> c;
		for(int i=0; i<c; ++i) cin >> cows[i];
		for(int i=0; i<c; ++i)
			for(int j=i+1; j<c; ++j) d[cows[i]][cows[j]] = d[cows[j]][cows[i]] = 1; //　分隔度为1
	}
	solve();
	return 0;
}
