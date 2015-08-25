/*************************************************************************
	> File Name: 1979.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-25 二 14:15:44 CST
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
// #include <unistd.h>
using namespace std;

struct stat {
	int x, y;
	stat(int x, int y) : x(x), y(y) {}
} s(-1, -1);

int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1}; // 右， 上， 下， 左
char Map[30][30];
int W, H;
int ans = 0;

void dfs(int i, int j) {
	if(i < 0 || i >= H || j < 0 || j >= W)
		return;
	for(int k=0; k<4; ++k) {
		stat n(i+dx[k], j+dy[k]);
		if(Map[n.x][n.y] == '.' && n.x >=0 && n.x<H && n.y>=0 && n.y<W) { // 这里不能忘了边界条件！！！
			Map[n.x][n.y] = 'o';
			++ans;
			// system("clear");
			// printf("(%d, %d) ans = %d\n", n.x, n.y, ans);
			// for(int i=0; i<H; ++i) {
				// for(int j=0; j<W; ++j)
					// printf("\%c", Map[i][j]);
				// cout << endl;
			// }
			// usleep(100000);
			dfs(n.x, n.y);
		}
	}
}

void solve() {
	while(cin >> W >> H && W + H) {
		for(int i=0; i<H; ++i) {
			getchar();
			for(int j=0; j<W; ++j) {
				Map[i][j] = getchar();
				if(Map[i][j] == '@') {
					s.x = i;
					s.y = j;
					Map[i][j] = '#';
				}
			}
		}
		// for(int i=0; i<H; ++i) {
			// for(int j=0; j<W; ++j)
				// printf("%c", Map[i][j]);
			// cout << endl;
		// }
		ans = 0;
		dfs(s.x, s.y);
		cout << ans+1 << endl;
	}
}

int main()
{
#ifdef Oj
	freopen("1979.in", "r", stdin);
#endif
	solve();
	return 0;
}
