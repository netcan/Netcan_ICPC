/*************************************************************************
	> File Name: 0531.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-11 一 20:39:44 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int w, h, n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
bool fld[1003*6][1003*6];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> P;

// 对坐标x1, x2离散化，并返回离散化后的宽度
int compress(int *x1, int *x2, int w) {
	vector<int> xs;
	for(int i=0; i<n; ++i) {
		for(int d=-1; d<=1; ++d) {
			int tx1 = x1[i] + d;
			int tx2 = x2[i] + d;
			if(0<=tx1 && tx1 <w) xs.push_back(tx1);
			if(0<=tx2 && tx2 <w) xs.push_back(tx2);
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for(int i=0; i<n; ++i) {
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}

void bfs(int x, int y) {
	queue<P> que;
	que.push(P(x, y));
	while(!que.empty()) {
		P q = que.front(); que.pop();
		fld[q.second][q.first] = true;
		for(int d=0; d<4; ++d) {
			int tx = q.first + dx[d];
			int ty = q.second + dy[d];
			if(tx < 0 || tx >= w || ty< 0 || ty >= h) continue;
			if(fld[ty][tx]) continue;
			que.push(P(tx, ty));
			fld[ty][tx] = true;
		}
	}
}

void solve() {
	w = compress(x1, x2, w);
	h = compress(y1, y2, h);

	memset(fld, 0, sizeof(fld));
	for(int i=0; i<n; ++i)
		for(int y=y1[i]; y<=y2[i]; ++y)
			for(int x=x1[i]; x<=x2[i]; ++x)
				fld[y][x] = true;
	// printf("w:%d h:%d n:%d\n", w, h, n);
	int ans = 0;
	for(int y=0; y<h; ++y) {
		for(int x=0; x<w; ++x) {
			if(fld[y][x]) continue;
			++ans;
			bfs(x, y);
		}
	}
	cout << ans <<endl;

	// for(int y=0; y<h; ++y) {
		// for(int x=0; x<w; ++x)
			// printf("%c", fld[y][x]?'1':'0');
		// printf("\n");
	// }
}


int main() {
#ifdef Oj
	freopen("0531.in", "r", stdin);
	// freopen("0531.out", "w", stdout);
#endif
	while(cin >> w >> h) {
		if(w==h && w==0) break;
		cin >> n;
		for(int i=0; i<n; ++i) {
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			--x2[i];
			--y2[i];
		}
		solve();
	}
	return 0;
}
