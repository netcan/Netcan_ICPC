////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-16 22:24:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1241
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1800KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1241.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 16 May 2015 09:48:55 PM CST
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

int m, n;
char Map[105][105];
void DFS(int i, int j) {
	if(i > m || i<1 || j>n || j<1)
		return;
	Map[i][j] = '*';
	for(int x=-1; x<=1; ++x)
		for(int y=-1; y<=1; ++y) {
			if(Map[i+x][j+y] =='@')
				DFS(i+x, j+y);
		}
	return;
}

int main()
{
#ifdef Oj
	freopen("1241.data", "r", stdin);
#endif
	while(cin >> m >> n && m) {
		for(int i=1; i<=m; ++i)
			for(int j=1; j<=n; ++j)
				cin >> Map[i][j];

		// for(int i=1; i<=m; ++i) {
			// for(int j=1; j<=n; ++j)
				// cout << Map[i][j];
			// cout << endl;
		// }
		// cout << endl;

		int counts = 0;
		for(int i=1; i<=m; ++i)
			for(int j=1; j<=n; ++j) {
				if(Map[i][j] == '@') {
					DFS(i, j);
					++counts;
				}
			}
		cout << counts << endl;
		// for(int i=1; i<=m; ++i) {
			// for(int j=1; j<=n; ++j)
				// cout << Map[i][j];
			// cout << endl;
		// }
		// cout << endl;
	 }

	return 0;
}