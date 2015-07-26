////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-16 23:22:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2952
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2380KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2952.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 16 May 2015 11:15:46 PM CST
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

int H,W;
char Map[105][105];
int direct[][2] = {{-1,0}, {1,0}, {0,-1}, {0, 1}};

void DFS(int i, int j) {
	if(i<1 || i>H || j<1 || j>W)
		return;
	Map[i][j] = '.';
	for(int k=0; k<4; ++k)
		if(Map[i+direct[k][0]][j+direct[k][1]] == '#')
			DFS(i+direct[k][0], j+direct[k][1]);
}

int main()
{
#ifdef Oj
	freopen("2952.data", "r", stdin);
#endif
	int T;
	cin >> T;
	while(cin >> H >> W) {
		for(int i=1; i<=H; ++i)
			for(int j=1; j<=W; ++j)
				cin >> Map[i][j];
		int counts = 0;
		for(int i=1; i<=H; ++i)
			for(int j=1; j<=W; ++j)
				if(Map[i][j] == '#') {
					DFS(i, j);
					++counts;
				}
		cout << counts << endl;
	}

	return 0;
}