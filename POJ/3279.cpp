/*************************************************************************
	> File Name: 3279.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-01 五 16:01:03 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int M, N;
bool tile[20][20]; // 输入棋盘状态，1为黑色，0为白色
bool flip[20][20]; // 翻转状态
bool opt[20][20]; // 最优解

// 邻接格子坐标
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

void show_tile(bool t[20][20]) {
	for(int i=0; i<M; ++i) {
		for(int j=0; j<N; ++j)
			printf("%d ", t[i][j]);
		printf("\n");
	}
}

bool get_color(int i, int j) { // 获得(i, j)格子的颜色，黑色返回1，白色返回0
	int c = tile[i][j];
	for(int d=0; d<5; ++d) {
		int nx = i+dx[d], ny = j+dy[d];
		if(nx >= 0 && nx < M && ny >=0 && ny < N) c+=flip[nx][ny];
	}
	return c&1;
}

int calc() { // 计算第一行确定后，所需要的步数，不存在返回-1
	for(int i=1; i<M; ++i)
		for(int j=0; j<N; ++j)
			if(get_color(i-1, j))  // 上一个格子为黑色的话，需要翻转
				flip[i][j] = 1;
	for(int j=0; j<N; ++j)  // 判断最后一行是否全为0
		if(get_color(M-1, j)) return -1;
	int res = 0;
	for(int i=0; i<M; ++i)
		for(int j=0; j<N; ++j) if(flip[i][j]) ++res;
	return res;
}

void solve() {
	int res = -1;
	for(int i=0; i<(1<<N); ++i) { // 枚举第一行所有翻转状态，有2^N种情况
		memset(flip, false, sizeof(flip));
		for(int j=0; j<N; ++j)
			flip[0][N-j-1] = (i >> j) & 1; // 这题字典序从右往左计算= =
		int num = calc();
		if(num >= 0 && (res < 0 || res > num)) {
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}
	}
	if(res == -1) puts("IMPOSSIBLE");
	else show_tile(opt);
}

int main() {
#ifdef Oj
	freopen("3279.in", "r", stdin);
#endif
	cin >> M >> N;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> tile[i][j];
	solve();
	return 0;
}
