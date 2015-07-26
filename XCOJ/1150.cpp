/*************************************************************************
    > File Name: 1150.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/4/14 12:42:00
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct Tree {
	int a,b;
} tree[260];

bool cmp(const Tree &a, const Tree &b) {
	return a.b < b.b;
}
int main() {
	int T;
	int m,n;
	scanf("%d", &T);
	static int d[260][260];
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i)
			scanf("%d", &tree[i].a);
		for(int i=1; i<=n; ++i)
			scanf("%d", &tree[i].b);
		sort(tree+1, tree+n+1, cmp);
		memset(d, 0, sizeof(d));
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				d[i][j] = max(d[i-1][j], d[i-1][j-1]+tree[i].a+tree[i].b*(j-1));
		printf("%d\n", d[n][m]);
	}
	return 0;

}

