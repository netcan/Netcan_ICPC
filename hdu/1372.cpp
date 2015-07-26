////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-20 12:10:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1372
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1372.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 20 May 2015 11:46:21 AM CST
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

struct point {
	int i, j, step;
	point(int i, int j, int step): i(i), j(j), step(step) {}
	point() {}
	friend bool operator<(const point &a, const point &b) {
		return a.step > b.step;
	}
};
point s, e;
int direct[][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1},
					{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
bool visited[10][10];

int bfs() {
	priority_queue<point> que;
	memset(visited, 0, sizeof(visited));
	que.push(point(s.i, s.j, 0));
	while(que.size()) {
		point p = que.top();
		que.pop();
		if(p.i == e.i && p.j == e.j)
			return p.step;
		for(int k=0; k<8; ++k) {
			int nx = p.i + direct[k][0];
			int ny = p.j + direct[k][1];
			if(nx >=1 && nx<=8 && ny>=1 && ny<=8 && !visited[nx][ny] ) {
				que.push(point(nx, ny, p.step + 1));
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main()
{
#ifdef Oj
	freopen("1372.data", "r", stdin);
#endif
	string a, b;
	while(cin >> a >> b) {
		s.i = a[0]-'a' + 1;
		s.j = a[1]-'0';
		e.i = b[0]-'a' + 1;
		e.j = b[1]-'0';
		printf("To get from %s to %s takes %d knight moves.\n", a.c_str(), b.c_str(), bfs());
	}


	return 0;
}