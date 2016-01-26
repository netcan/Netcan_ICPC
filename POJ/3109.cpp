/*************************************************************************
	> File Name: 3109.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-26 二 16:34:56 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100000+30;
typedef long long ll;

int N;
int x[MAXN], y[MAXN];
bool visited[MAXN];

ll bit0[MAXN], bit1[MAXN]; // 负责维护原始值和增量的树状数组，用来记录区间内黑点数量。

// 树状数组部分
void add(ll *bit, int i, ll x) {
	while(i<=MAXN) {
		bit[i] += x;
		i += i&-i;
	}
}

ll sum(ll *bit, int i) {
	ll res = 0;
	while(i>0) {
		res += bit[i];
		i -= i&-i;
	}
	return res;
}

// 区间和，更新区间值[l, r)
ll getsum(int i) {
	return sum(bit0, i) + sum(bit1, i)*i;
}


void update(int l, int r, int x) {
	add(bit0, l, -x*(l-1));
	add(bit1, l, x);
	add(bit1, r, -x);
	add(bit0, r, r*x);
}

// 坐标离散化
int compress(int *x) {
	vector<int> xs;
	for (int i = 0; i < N; ++i)
		xs.push_back(x[i]);
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	for (int i = 0; i < N; ++i)
		x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
	return xs.size();
}


void solve() {
	compress(x); // 离散化
	int h = compress(y);
	vector<int> line[MAXN];
	for(int i=0; i<N; ++i) line[y[i]].push_back(x[i]);
	ll ans = N;
	for(int y=1; y<=h; ++y) {
		vector<int> &xs = line[y];
		sort(xs.begin(), xs.end());
		for(vector<int>::iterator i = xs.begin(); i!=xs.end(); ++i) { // 从左往右遍历每个黑点
			int X = *i;
			ll s = getsum(X) - getsum(X-1); // 当前坐标的黑点数
			if(visited[X]) ans += s; // 前面已经标记过x轴的话
			visited[X] = true;
			update(X, X, -s);
			if(i+1 < xs.end() && X+1 <= (*(i+1)-1))
				update(X+1, *(i+1)-1, 1);
		}
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef Oj
	freopen("3109.in", "r", stdin);
	// freopen("3109.out", "w",stdout);
#endif
	// cin >> N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d%d", x+i, y+i);
	solve();
	return 0;
}
