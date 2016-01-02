/*************************************************************************
	> File Name: 1222.cpp
	  > Author: Netcan
	  > Blog: http://www.netcanMAX_NMAX_NMAX_N.com
	  > Mail: 14MAX_N97097MAX_M9@qq.com
	  > Created Time: 201MAX_N-01-02 六 14:31:32 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_M = 5;
const int MAX_N = 6;

bool light[MAX_M][MAX_N]; // 0表示熄灯，1表示亮灯，要求最终状态都为熄灯
bool flip[MAX_M][MAX_N]; // flip[i][j]表示是(1)否(0)按下(i, j)开关

int dx[] = {0, -1, 1, 0, 0}; // 邻接开关坐标
int dy[] = {0, 0, 0, 1, -1};
int T;

bool get_stat(int i, int j) { // 获取(i, j)灯泡的状态
	int res = light[i][j];
	for(int d=0; d<MAX_M; ++d) {
		int nx = i+dx[d];
		int ny = j+dy[d];
		if(nx >= 0 && nx < MAX_M && ny >= 0 && ny < MAX_N) res += flip[nx][ny];
	}
	return res & 1;
}

int calc() {
	for(int i=1; i<MAX_M; ++i)
		for(int j=0; j<MAX_N; ++j)
			if(get_stat(i-1, j)) flip[i][j] = 1;
	for(int j=0; j<MAX_N; ++j) // 最后一行
		if(get_stat(MAX_M-1, j)) return -1;

	int res = 0;
	for (int i = 0; i < MAX_M; ++i)
		for (int j = 0; j < MAX_N; ++j) res+=flip[i][j];
	return res;
}

void show_light(bool t[MAX_M][MAX_N]) {
	for(int i=0; i<MAX_M; ++i)
		for(int j=0; j<MAX_N; ++j)
			printf("%d%c", t[i][j], j==MAX_N-1?'\n':' ');
}

void solve() {
	// 枚举第一行所有状态。
	for(int i=0; i<(1<<MAX_N); ++i) {
		memset(flip, 0, sizeof(flip));
		for(int j=0; j<MAX_N; ++j) flip[0][j] = (i >> j) & 1;
		if(calc() >= 0) {
			show_light(flip);
			return;
		}
	}
}

int main() {
#ifdef Oj
	freopen("1222.in", "r", stdin);
#endif
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		for(int i=0; i<MAX_M; ++i)
			for (int j = 0; j < MAX_N; ++j) scanf("%d", &light[i][j]);
		printf("PUZZLE #%d\n", t);
		solve();
	}
	return 0;
}
