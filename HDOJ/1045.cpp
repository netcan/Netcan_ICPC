////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-09 17:34:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1045.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-06-09 Tue 16:25:52 CST
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
char Map[4][4];

bool yes(char Map[4][4]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(Map[i][j] == '.')
				return false;
	return true;
}

int DFS(char t[4][4]) {
	int maxbh=0;
	if(yes(Map))
		return 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if(t[i][j] != '.')
				continue;
			char tt[4][4];
			memcpy(tt, t, sizeof(tt));
			for(int x=i; x<n && t[x][j]!='X' ; ++x)
				tt[x][j] = 'F';
			for(int x=i; x>=0 && t[x][j]!='X' ; --x)
				tt[x][j] = 'F';
			for(int y=j; y<n && t[i][y] != 'X'; ++y)
				tt[i][y] = 'F';
			for(int y=j; y>=0 && t[i][y] != 'X'; --y)
				tt[i][y] = 'F';
			int bh = DFS(tt) + 1;
			maxbh = max(maxbh, bh);
			// printf("%d %d\n", i, j);;
		}
	return maxbh;
}

int main()
{
#ifdef Oj
	freopen("1045.in", "r", stdin);
#endif
	while(cin >> n && n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> Map[i][j];
		char t[4][4];
		memcpy(t, Map, sizeof(Map));
		cout << DFS(t) << endl;
	}
	return 0;
}