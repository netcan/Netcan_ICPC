/*************************************************************************
	> File Name: 1007.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 28 May 2015 08:37:42 PM CST
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

int board[25];
int destboard[25]={0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 8, 0, 4, 0, 0, 7, 6, 5, 0, 0, 0, 0, 0, 0};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
map<int, bool> mark;

int loc(int i, int j) {
	return i*5 + j;
}

struct Stat{
	int step;
	int board[25];
	Stat(int *b, int s=0) {
		memcpy(this->board, b, sizeof(int)*25);
		step = s;
	}
	// Stat(int *b, int s, int i, int j) {
		// memcpy(this->board, b, sizeof(int)*25);
		// step = s;
		// zi = i;
		// zj = j;
	// }
};

bool ok(int *b) {
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=3; ++j) {
			if(b[loc(i, j)] != destboard[loc(i, j)])
				return false;
		}
	return true;
}

int BFS() {
	queue<Stat> que;
	que.push(Stat(board, 0));
	while(que.size()) {
		int m=0, mk=1;
		Stat p = que.front();
		que.pop();

		// for(int i=1; i<=3; ++i)
			// for(int j=1; j<=3; ++j) {
				// cout << p.board[loc(i, j)] << " ";
			// }
		// cout << endl;

		if(ok(p.board)) {
			return p.step;
		}
		for(int i=1; i<=3; ++i)
			for(int j=1; j<=3; ++j) {
				m+=p.board[loc(i, j)]*mk;
				mk*=10;
			}
		if(!mark.count(m))
			mark[m] = true;

		for(int k=0; k<4; ++k) {
			Stat n(p.board, p.step+1);
			int zx, zy;

			for(int i=1; i<=3; ++i)
				for(int j=1; j<=3; ++j) {
					if(p.board[loc(i,j)]==0) {
						zx = i;
						zy = j;
						break;
					}
					if(p.board[loc(i,j)]==0)
						break;
				}
			int nx = zx+dx[k];
			int ny = zy+dy[k];
			m = 0;
			mk = 1;
			swap(n.board[loc(nx, ny)], n.board[loc(zx, zy)]);
			for(int i=1; i<=3; ++i)
				for(int j=1; j<=3; ++j) {
					m+=n.board[loc(i, j)]*mk;
					mk*=10;
				}
			if(!mark.count(m)) {
				mark[m] = true;
				que.push(n);
			}
		}
	}
	return -1;
}


int main()
{
#ifdef Oj
	 freopen("1007.data/14.in", "r", stdin);
	 freopen("1007.data/14.out", "w", stdout);
#endif
	memset(board, 0, sizeof(board));
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=3; ++j)
			scanf("%1d", &board[loc(i, j)]);

	mark.clear();
	cout << BFS() << endl;
	return 0;
}
