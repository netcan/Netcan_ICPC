/*************************************************************************
	> File Name: 1703.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-09 一 20:11:57 CST
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
int par[100005];
int opp[100005]; // 记录罪犯i的对立帮派

void init(){
	for(int i=1; i<=N; ++i) {
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
	memset(opp, 0, sizeof(opp));
	init();

	char op;
	int x, y;

	while(M--) {
		scanf("%c%d%d", &op, &x, &y);
		getchar();
		if(op == 'A') {
			if(same(x, y)) printf("In the same gang.\n"); // 同帮派
			else if(same(x, opp[y])) printf("In different gangs.\n"); // ｘ和y的对立面同一党派，那么x和y不同帮派
			else printf("Not sure yet.\n");
		}
		else {
			// 之前对立帮派
			if(opp[x]) unite(y, opp[x]); // 因为y和x对立，x和opp[x]对立，那么opp[x]和y则相同帮派
			if(opp[y]) unite(x, opp[y]);
			// 之后更新对立帮派
			opp[x] = y;
			opp[y] = x;
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
