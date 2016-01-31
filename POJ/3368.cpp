/*************************************************************************
	> File Name: 3368.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-31 日 16:34:55 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100000+5;
int tree[MAXN*3];
vector<int> pos;
int N, Q;
void build(int v, int l, int r) { // [l, r)
	if(r - l == 1) {
		tree[v] = pos[r] - pos[l];
		// printf("tree[%d] num: %d\n", v, pos[r]-pos[l]);
	}
	else {
		int chl = (v<<1) + 1, chr = (v<<1) + 2, m = (l+r) >> 1;
		build(chl, l, m);
		build(chr, m, r);
		tree[v] = max(tree[chl], tree[chr]);
	}
}

int query(int v, int l, int r, int L, int R) { // [l, r)
	// printf("l:%d r:%d L:%d R:%d\n", l, r, L, R);
	if(L >= r || R <= l) return 0;
	else if(L<=l && r <= R)
		return tree[v];
	else {
		int chl = (v<<1) + 1, chr = (v<<1) + 2, m = (l+r) >> 1;
		return max(query(chl, l, m, L, R), query(chr, m, r, L, R));
	}
}

void solve() {
	build(0, 0, pos.size() - 1);
	for (int i = 0; i < Q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r); --l;
		int lp = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
		int rp = lower_bound(pos.begin(), pos.end(), r) - pos.begin();
		// printf("pos[%d] = %d pos[%d]=%d\n", lp, pos[lp], rp, pos[rp]);
		if(pos[lp] == l && pos[rp] == r) {
			if(lp == rp) printf("%d\n", r - l);
			else printf("%d\n", query(0, 0, pos.size()-1, lp, rp));
		}
		else if(pos[lp] == l && pos[rp] != r) {
			if(lp + 1 == rp) printf("%d\n", r - l);
			else printf("%d\n", max(query(0, 0, pos.size()-1, lp, rp-1), r-pos[rp-1]));
		}
		else if(pos[lp] != l && pos[rp] == r) {
			if(lp == rp) printf("%d\n", pos[lp] - l);
			else printf("%d\n", max(query(0, 0, pos.size()-1, lp, rp), pos[lp] - l));
		}
		else {
			if(lp == rp) printf("%d\n", r - l);
			else if(lp + 1 == rp) printf("%d\n", max(pos[lp]-l, r-pos[rp-1]));
			else printf("%d\n", max(r-pos[rp-1], max(query(0, 0, pos.size()-1, lp, rp-1), pos[lp] - l)));
		}
	}

}

int main() {
#ifdef Oj
	freopen("3368.in", "r", stdin);
	// freopen("3368.out", "w",stdout);
#endif
	while(scanf("%d%d", &N, &Q) == 2 && N) {
		int lst = -100020, cur;
		pos.clear();
		for(int i=0; i<N; ++i) {
			scanf("%d", &cur);
			if(cur != lst) {
				pos.push_back(i);
				lst = cur;
			}
		}
		pos.push_back(N);
		solve();
	}
	return 0;
}
