/*************************************************************************
	> File Name: 3009.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-25 二 18:48:31 CST
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

int w, h;
struct stat {
	int x, y;
	stat(int x=0, int y=0) : x(x), y(y) {}
} s(-1, -1);
int Map[21][21];
int steps;
int dx[] = {1, 0, -1, 0}; // 下, 左, 上, 右
int dy[] = {0, -1, 0, 1};

void dfs(const stat &s, int step) {
	if(step + 1 < steps) // 剪枝
		for(int i=0; i<4; ++i) {
			stat stop(s.x+dx[i], s.y+dy[i]); // 往某个方向抛出

			if(stop.x >=0 && stop.x<h && stop.y>=0 && stop.y < w && Map[stop.x][stop.y] != 1) { // 立即抛出不是墙壁
				while(stop.x >=0 && stop.x<h && stop.y>=0 && stop.y < w && Map[stop.x][stop.y] != 1) { // 直到撞墙为止
					if(Map[stop.x][stop.y] == 3 && step + 1 < steps) steps = step + 1; // 途中经过终点
					stop.x += dx[i]; // 继续前进
					stop.y += dy[i];
					// printf("(%d, %d)\n", stop.x, stop.y);
				}
				// printf("-----\n");

				if(stop.x >=0 && stop.x<h && stop.y>=0 && stop.y < w && Map[stop.x][stop.y] == 1)  { // 撞墙
					Map[stop.x][stop.y] = 0; // 墙没了
					stat pos(stop.x-dx[i], stop.y-dy[i]); // 此时冰球的位置
					dfs(pos, step+1);  // 继续抛出
					Map[stop.x][stop.y] = 1; // 状态还原
				}
			}
		}
}

void solve() {
	steps = 11;
	dfs(s, 0);
	if(steps >= 11)
		printf("-1\n");
	else
		printf("%d\n", steps);
}

int main()
{
#ifdef Oj
	freopen("3009.in", "r", stdin);
#endif
	while(scanf("%d%d", &w, &h) && w + h) {
		for(int i=0; i<h; ++i) {
			for(int j=0; j<w; ++j) {
				scanf("%d", &Map[i][j]);
				if(Map[i][j] == 2) {
					s.x = i;
					s.y = j;
					Map[i][j] = 0;
				}
			}
		}
		// for(int i=0; i<h; ++i) {
			// for(int j=0; j<w; ++j)
				// printf("%2d", Map[i][j]);
			// cout << endl;
		// }

		solve();
	}
	return 0;
}
