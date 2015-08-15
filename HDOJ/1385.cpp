/*************************************************************************
	> File Name: 1385.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-14 Fri 15:35:02 CST
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
int N;
int d[500][500];
int tax[500];
int path[500][500];
int des[500][2];
int des_cnt;

void floyd() {
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=N; ++j)
			path[i][j] = j;

	for(int k=1; k<=N; ++k)
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j) {
				int tmp = d[i][k] + d[k][j] + tax[k];
				if(d[i][j] > tmp) {
					d[i][j] = tmp;
					path[i][j] = path[i][k];
				}
				else if(d[i][j] == tmp)
					path[i][j] = min(path[i][j], path[i][k]);
			}
}

void get_path(int s, int t) {
	printf("%d", s);
	while(s!=t) {
		printf("-->%d", path[s][t]);
		s = path[s][t];
	}
}


void solve() {
	while(cin >> N && N) {
		int cost;
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j) {
				cin >> cost;
				if(cost == -1)
					d[i][j] = INF;
				else
					d[i][j] = cost;
			}
		for(int i=1; i<=N; ++i)
			cin >> tax[i];
		int s, t;
		des_cnt = 0;
		while(cin >> s >> t) {
			if(s == t && s == -1)
				break;
			des[des_cnt][0] = s;
			des[des_cnt][1] = t;
			++des_cnt;
		}
		floyd();
		vector<int> path;

		for(int i=0; i<des_cnt; ++i) {
			printf("From %d to %d :\n", des[i][0], des[i][1]);
			printf("Path: ");
			get_path(des[i][0], des[i][1]);
			printf("\nTotal cost : %d\n\n", d[des[i][0]][des[i][1]]);
		}

	}

}

int main()
{
#ifdef Oj
	freopen("1385.in", "r", stdin);
#endif
	solve();
	return 0;
}
