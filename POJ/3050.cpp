/*************************************************************************
	> File Name: 3050.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-31 一 08:33:05 CST
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

int Map[10][10];
map<int, bool> s;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void dfs(int i, int j, int data, int deep) { // 关键在于状态的构造。。之前是搜索到顶才计算data，超时，改成边搜索边计算效率大大提高了。
	if(deep == 6) { // 到顶
		if(s.count(data) == 0) s[data] =true;
		return;
	}
	data = data*10 + Map[i][j]; // 计算, 这题前导０并不影响

	for(int k=0; k<4; ++k) { // 四个方向搜索
		int nx = i+dx[k];
		int ny = j+dy[k];
		if(nx >=0 && nx < 5 && ny>=0 && ny < 5)
			dfs(nx, ny, data, deep+1);
	}
}

void solve() {
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j)
			dfs(i,j,0,0);
	cout << s.size() << endl;
}

int main()
{
#ifdef Oj
	freopen("3050.in", "r", stdin);
#endif
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j)
			scanf("%d", &Map[i][j]);
	solve();
	return 0;
}
