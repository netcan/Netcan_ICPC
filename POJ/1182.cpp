/*************************************************************************
	> File Name: 1182.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-10 二 17:58:44 CST
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
int par[50000*3+10]; // 分为x-A, x-B, x-C三组，分别表示x属于A, B, C
// 并查集每一个组里的所有元素代表的情况都同时发生或者不发生。

void init(int N) {
	for(int i=1; i<=3*N; ++i) par[i] = i;
}
int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}
bool same(int x, int y) {
	return find(x) == find(y);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x!=y)
		par[x] = y;
}


int main()
{
#ifdef Oj
	freopen("1182.in", "r", stdin);
#endif
	int N, K; // 动物编号， 条件数量
	scanf("%d%d",&N,&K); // 被cin/cout卡死了。。
	init(N);
	int pre, x, y;
	int ans = 0;
	while(K--) {
		scanf("%d%d%d", &pre, &x, &y);
		if(x<1 || x>N || y<1 || y>N) { // 范围错误
			++ans;
			continue;
		}
		if(pre == 1) {
			if(same(x, y+N) || same(x, y+2*N)) // 当x属于A, 则y属于B或C都是异类，无需考虑x属于B或者C，因为下面合并的时候将x属于A, B, C都考虑进去了
				++ans;
			else {
				// 以下考虑了三种情况，当x分别属于A, B, C时，将y分别和x放在一起
				unite(x, y);
				unite(x+N, y+N);
				unite(x+2*N, y+2*N);
			}
		}
		else {
			if(same(x, y) || same(x,y+2*N)) ++ans; // 当x, y同类，或者属于A的x吃了C的y，则为假话
			else {
				unite(x, y+N); // A的x吃B的y
				unite(x+N, y+2*N); // B的x吃C的y
				unite(x+2*N, y); // C的x吃A的y
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
