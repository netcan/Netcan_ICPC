/*************************************************************************
	> File Name: 2155.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-27 三 08:31:01 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 5;

int bit0[MAXN][MAXN]; // 二维树状数组
int bit1[MAXN][MAXN];
int N, T; // 矩阵大小，操作数

// 树状数组部分
void add(int *bit, int i, int x) {
	while(i<=MAXN) {
		bit[i] += x;
		i+=i&-i;
	}
}
int sum(int *bit, int i) {
	int res = 0;
	while(i>0) {
		res += bit[i];
		i-=i&-i;
	}
	return res;
}

// 区间更新[l, r]，求区间和
void update(int l, int r, int y, int x) {
	add(bit0[y], l, -l*x + x);
	add(bit1[y], l, x);
	add(bit0[y], r, r*x);
	add(bit1[y], r, -x);
}

// (l, r]
int getsum(int l, int r, int y) {
	return (sum(bit0[y], r) + sum(bit1[y], r)*r)
		-  (sum(bit0[y], l) + sum(bit1[y], l)*l);
}


void solve() {
	char op;
	int x1, y1, x2, y2;
	while(T--) {
		getchar();
		scanf("%c", &op);
		if(op == 'C') {
			// cin >> x1 >> y1 >> x2 >> y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for(int y=y1; y<=y2; ++y)
				update(x1, x2, y, 1);
		}
		else {
			// cin >> x1 >> y1;
			scanf("%d%d", &x1, &y1);
			// printf("(%d, %d) %d\n", x1, y1, sum(bit0[y1], x1) + sum(bit1[y1], x1)*x1);
			// printf("(%d, %d) %d\n", x1, y1, sum(bit0[y1], x1-1) + sum(bit1[y1], x1-1)*(x1-1));
			// cout << getsum(x1-1, x1, y1)%2 << endl;
			printf("%d\n", getsum(x1-1, x1, y1) % 2);
		}
	}

}

int main() {
#ifdef Oj
	freopen("2155.in", "r", stdin);
	// freopen("2155.out", "w",stdout);
#endif
	int X;
	scanf("%d", &X);
	while(X--) {
		scanf("%d%d", &N, &T);
		solve();
	}
	return 0;
}
