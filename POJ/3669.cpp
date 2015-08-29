/*************************************************************************
	> File Name: 3669.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-29 六 19:10:35 CST
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

const int INF = 0x3f3f3f3f;
int M;
struct meteor {
	int x, y, t;
	meteor(int x=0, int y=0,int t=0) : x(x), y(y), t(t) {}
};

bool visited[310][310]; // 标记已访问点
int T[310][310];  // 标记流星掉落时间点

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs() {
	memset(visited, 0, sizeof(visited));

	int time = -1; // 初始不可达
	visited[0][0] = true; // 标记起点
	queue<meteor> que;
	que.push(meteor(0, 0, 0));

	while(!que.empty()) {
		meteor p = que.front(); que.pop();
		 if(T[p.x][p.y] == INF) { // 这块是安全的
			time = p.t;
			break;
		}
		 else if(T[p.x][p.y] !=INF && p.t < T[p.x][p.y]) {
			for(int k=0; k<4; ++k) {
				meteor q(p.x+dx[k], p.y+dy[k], p.t + 1);
				if(!visited[q.x][q.y] && q.x >=0 && q.x <= 302 && q.y >=0 && q.y <= 302) {
					que.push(q);
					visited[q.x][q.y] = true;
				}
			}
		}
	}
	return time;
}

void solve() {
	scanf("%d", &M);
	int x, y, t;
	memset(T, 0x3f, sizeof(T));

	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &x, &y, &t);
		if(T[x][y] > t) // 这里有坑。。。时间更新问题，好大的坑。。
			T[x][y] = t;
		for(int k=0; k<4; ++k) {
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx >=0 && nx<=301 && ny >= 0 && ny <= 301 && T[nx][ny] > t)
				T[nx][ny] = t;
		}

	}

	// for(int i=0; i<=10; ++i) {
		// for(int j=0; j<=10; ++j) {
			// if(T[i][j] == INF) printf("-1 ");
			// else printf("%3d", T[i][j]);
		// }
		// puts("");
	// }

	cout << bfs() << endl;
}

int main()
{
#ifdef Oj
	freopen("3669.in", "r", stdin);
#endif
	solve();
	return 0;
}
