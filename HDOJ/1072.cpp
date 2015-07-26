////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-20 21:55:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1644KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1072.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 20 May 2015 08:51:02 PM CST
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
int N, M;
int Map[10][10];
struct point {
	int i, j;
	int t;
	int totaltime;
	friend bool operator< (const point &a, const point &b) {
		return a.t < b.t;
	}
	point(int i=0, int j=0, int t=6,int totaltime = 0): i(i), j(j), t(t), totaltime(totaltime) {}
};
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
point s,e;

int BFS() {
	queue<point> que;
	que.push(s);
	while(que.size()) {
		point p = que.front();
		que.pop();
		if(p.i == e.i && p.j == e.j && p.t > 0)
			return p.totaltime;
		if(p.t == 1) continue;

		for(int k=0; k<4; ++k) {
			int nx = p.i + dx[k];
			int ny = p.j + dy[k];
			if(nx >=0 && nx<N && ny>=0 && ny<M && Map[nx][ny]!=0 && p.t - 1 > 0) {
				if(Map[nx][ny] == 1)
					que.push(point(nx, ny, p.t-1, p.totaltime+1));
				else if(Map[nx][ny] == 4) {
					que.push(point(nx, ny, 6, p.totaltime+1));
					Map[nx][ny] = 0;
				}
			}
		}
	}

	return -1;
}

int main()
{
#ifdef Oj
	freopen("1072.data", "r", stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j) {
				cin >> Map[i][j];
				if(Map[i][j] == 2) {
					s.i = i;
					s.j = j;
					Map[i][j] = 0;
				}
				else if(Map[i][j] == 3) {
					e.i = i;
					e.j = j;
					Map[i][j] = 1;
				}
			}
		cout << BFS() << endl;

	}


	return 0;
}