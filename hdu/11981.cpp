////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-05 19:21:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1198
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1198_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-05 Sun 17:09:25 CST
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

const int _max = 50*50+1;
bool pipes[11][4] = { // 上0左1右2下3
	1,1,0,0,
    1,0,1,0,
    0,1,0,1,
    0,0,1,1,
    1,0,0,1,
    0,1,1,0,
    1,1,1,0,
    1,1,0,1,
    0,1,1,1,
    1,0,1,1,
    1,1,1,1
};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0}; // 上0 左1 右2 下3
int Set[_max];
char Map[51][51];
bool visited[51][51];
int n, m;
int find(int x) {
	return x==Set[x]?x:Set[x]=find(Set[x]);
}
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(a!=b)
		Set[a] = b;
}

// void DFS(int i, int j) {
	// if(i<1 || i>m || j<1 || j>n)
		// return;
	// visited[i][j] = true;
	// for(int k=0; k<4; ++k) { // 上0左1右2下3
		// int nx = i+dx[k];
		// int ny = j+dy[k];
		// if(nx>=1 && nx<=m && ny>=1 && ny<=n&&!visited[nx][ny]) {
			// if(pipes[Map[i][j]-'A'][k] && pipes[Map[nx][ny]-'A'][3-k]) {
				// unite((i-1)*n+j, (nx-1)*n+ny);
			// }
			// DFS(nx, ny);
			// visited[nx][ny] = false;
		// }
	// }
// }

void BFS(int i, int j) {
	struct pos{
		int x, y;
		pos(int x, int y): x(x),y (y){}
	};
	queue<pos> q;
	q.push(pos(i, j));
	visited[i][j] = true;
	while(q.size()) {
		pos s = q.front();
		q.pop();
		if(s.x == m && s.y==n)
			break;
		for(int k=0; k<4; ++k) {
			int nx = s.x+dx[k];
			int ny = s.y+dy[k];
			if(nx >=1 && nx<=m && ny>=1 && ny<=n) {
				if(pipes[Map[nx][ny]-'A'][3-k] && pipes[Map[s.x][s.y]-'A'][k])
					unite((s.x-1)*n+s.y, (nx-1)*n+ny);
				if(!visited[nx][ny]) {
					q.push(pos(nx,ny));
					visited[nx][ny] = true;
				}
			}
		}
	}

}

int main()
{
#ifdef Oj
	freopen("1198.in", "r", stdin);
#endif
	while(scanf("%d%d", &m, &n) == 2 && (n>=0 && m>=0)) {
		getchar();
		for(int i=m*n; i>=1; --i)
			Set[i] = i;
		memset(visited, 0, sizeof(visited));
		for(int i=1; i<=m; ++i) {
			for(int j=1; j<=n; ++j)
				Map[i][j]=getchar();
			getchar();
		}

		// for(int i=1; i<=m; ++i) {
			// for(int j=1; j<=n; ++j)
				// printf("%c", Map[i][j]);
			// puts("");
		// }

		BFS(1, 1);
		int ans = 0;
		// for(int i=1; i<=m*n; ++i)
			// printf("Set[%d] = %d\n", i, Set[i]);
		for(int i=m*n; i>=1; --i)
			if(Set[i]==i)
				++ans;
		printf("%d\n", ans);
	}
	return 0;
}