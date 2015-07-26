////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-21 10:04:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1312
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1640KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1312.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 21 May 2015 09:50:12 AM CST
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

int W, H;
char Map[25][25];
bool visited[25][25];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void DFS(int si, int sj) {
	visited[si][sj] = true;
	for(int k=0; k<4; ++k) {
		int nx = si + dx[k];
		int ny = sj + dy[k];
		if(nx >=0 && nx<H && ny>=0 && ny<W && !visited[nx][ny] && Map[nx][ny] != '#')
	 		DFS(nx, ny);
	}
}


int main()
{
#ifdef Oj
	freopen("1312.data", "r", stdin);
#endif
	int si, sj;
	while(cin >> W >> H && W && H) {
		for(int i=0; i<H; ++i)
			for(int j=0; j<W; ++j) {
				cin >> Map[i][j];
				if(Map[i][j] == '@') {
					si = i;
					sj = j;
					Map[i][j] = '.';
				}
			}

		// for(int i=0; i<H; ++i) {
			// for(int j=0; j<W; ++j)
				// cout << Map[i][j];
			// cout << endl;
		// }
		memset(visited, 0, sizeof(visited));
		DFS(si, sj);
		int counts = 0;
		for(int i=0; i<H; ++i)
			for(int j=0; j<W; ++j)
				if(visited[i][j])
					++counts;
		cout << counts << endl;
	}

	return 0;
}