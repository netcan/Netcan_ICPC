/*************************************************************************
	> File Name: 2549_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-10 日 20:11:06 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int N;
int data[1024];

struct ds {
	int v, i, j; // 记录两个数i, j的和或者差。
	ds(int v, int i, int j):v(v), i(i), j(j) {}
	bool operator<(const ds &b) const{
		return v < b.v;
	}
};

// 计算前半部分a+b的和，以及后半部分d-c，最后求出a+b==d-c时最大的d

vector<ds> sum; // a+b
vector<ds> diff; // d-c

void solve() {
	sum.clear();
	diff.clear();
	for(int a=0; a<N; ++a)
		for(int b=a+1; b<N; ++b) sum.push_back(ds(data[a]+data[b], a, b));
	for(int c=0; c<N; ++c)
		for(int d=c+1; d<N; ++d) {
			diff.push_back(ds(data[d]-data[c], d, c));
			diff.push_back(ds(data[c]-data[d], c, d));
		}

	int ans = numeric_limits<int>::min(); // 因为最大值可能为负数

	sort(diff.begin(), diff.end());

	for(vector<ds>::iterator i=sum.begin(); i!=sum.end(); ++i) { // a+b
		vector<ds>::iterator lb = lower_bound(diff.begin(), diff.end(), ds(i->v, 0, 0)); // d-c
		vector<ds>::iterator rb = upper_bound(diff.begin(), diff.end(), ds(i->v, 0, 0)); // d-c
		for(;lb!=rb; ++lb) {// 因为可能有多组相同的d-c
			if(lb->i != i->i && lb->j != i->i && lb->i != i->j && lb->j != i->j) {
				ans = max(ans, data[lb->i]);
			}
		}
	}
	if(ans == numeric_limits<int>::min()) puts("no solution");
	else cout << ans << endl;
}

int main() {
#ifdef Oj
	freopen("2549.in", "r", stdin);
	// freopen("2549_2.out", "w", stdout);
#endif
	while(cin >> N && N) {
		for (int i = 0; i < N; ++i) cin >> data[i];
		solve();
	}
	return 0;
}
