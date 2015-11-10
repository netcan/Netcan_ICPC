/*************************************************************************
	> File Name: 1703_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-10 一 20:11:57 CST
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
int T, N, M;
int par[100005*2]; // i-x表示i属于x，x={Gang Dragon, Gang Snake}

void init(){
	for(int i=1; i<=N*2; ++i) {
		par[i] = i;
	}
}

int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]); // 这里可能爆栈233
}
int same(int x, int y) {
	return find(x) == find(y);
}
void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if(x == y) return;
	par[x] = y;
}

void solve() {
	init();

	char op;
	int x, y;

	while(M--) {
		scanf("%c%d%d", &op, &x, &y);
		getchar();
		if(op == 'A') {
			if(same(x, y))
				printf("In the same gang.\n");
			else if(same(x, y+N))
				printf("In different gangs.\n");
			else
				printf("Not sure yet.\n");
		}
		else {
			unite(x, y+N);
			unite(x+N, y);
		}
	}

}

int main()
{
#ifdef Oj
	freopen("1703.in", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		getchar();
		solve();
	}
	return 0;
}
