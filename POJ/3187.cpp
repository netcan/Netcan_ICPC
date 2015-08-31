/*************************************************************************
	> File Name: 3187.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-31 一 08:11:57 CST
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

int N, SUM;
int data[12][12];
int ans[12];
bool visited[12];
bool flag;

int cal() {
	for(int i=1; i<N; ++i)  // 层
		for(int j=0; j<N-i; ++j) //　列
			data[i][j] = data[i-1][j] + data[i-1][j+1];
	return data[N-1][0];
}

void dfs(int i) {
	if(flag) return;
	if(i >= N) {
		// 计算
		// for(int i=0; i<N; ++i) cout << data[0][i] << " ";
		if(cal() == SUM) {
			flag = true;
			memcpy(ans, data[0], sizeof(data[0])); // 因为是从1-N枚举，所以最开始的那个字典序最小
		}
		return;
	}
	for(int k=1; k<=N; ++k) {
		if(!visited[k]) {
			data[0][i] = k;
			visited[k] = true;
			dfs(i+1);
			visited[k] = false;
		}
	}

}

void solve() {
	memset(visited, 0, sizeof(visited));
	// memset(data, 0, sizeof(data));
	flag = false;
	dfs(0);
	for(int i=0; i<N; ++i) {
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");

}

int main()
{
#ifdef Oj
	freopen("3187.in", "r", stdin);
#endif
	cin >> N >> SUM;
	solve();
	return 0;
}
