////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-15 21:45:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1010_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 15 May 2015 20:16:10 PM CST
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

int N, M, T;
char Map[10][10];
int direct[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
bool yes = false;
struct Point{
	int i, j;
};
Point S, D;
void DFS(int i, int j, int cnt) {
	int temp;
	if(i>N || j>M || i<1 || j<1)
		return;
	if(cnt == T) {
		if(i==D.i && j==D.j)
			yes = true;
		return;
	}
	if(yes)
		return;
	temp = T - cnt - (abs(i-D.i) + abs(j-D.j));
	if(temp < 0 || temp & 1)
		return;
	for(int k=0; k<4; ++k) {
		if(Map[i+direct[k][0]][j+direct[k][1]] == '.' || Map[i+direct[k][0]][j+direct[k][1]] == 'D') {
			Map[i+direct[k][0]][j+direct[k][1]] = 'X';
			DFS(i+direct[k][0], j+direct[k][1], cnt+1);
			Map[i+direct[k][0]][j+direct[k][1]] = '.';
		}
	}
	return;
}

int main()
{
#ifdef OJ
	freopen("1010.data", "r", stdin);
#endif
	while(cin >> N >> M >> T) {
		if( N==0 && M==0 && T==0)
			break;
		int counts = 0;
		for(int i=1; i<=N; ++i) {
			for(int j=1; j<=M; ++j) {
				cin >> Map[i][j];
				if(Map[i][j] == 'S') {
					S.i = i;
					S.j = j;
				}
				else if(Map[i][j] == 'D') {
					D.i = i;
					D.j = j;
				}
				else if(Map[i][j] == 'X')
					++counts;
			}
		}
		// if(M*N - counts <= T) {
			// cout << "NO" << endl;
			// continue;
		// }
		yes = false;
		DFS(S.i, S.j, 0);
		if(yes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}