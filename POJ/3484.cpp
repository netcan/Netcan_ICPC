/*************************************************************************
	> File Name: 3484.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-28 一 16:36:00 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
typedef long long ll;
struct ref {
	ll A, B, C;
	ref(ll A, ll B, ll C) : A(A), B(B), C(C) {}
};
vector<ref> refs;

bool C(ll x) { // 判断答案是否<=x，即<=x的个数应该为奇数个。
	ll left = 0;
	for(int i=0; i<refs.size(); ++i) {
		// printf("x:%lld %d\n", x, (x-refs[i].A)/refs[i].C + 1);
		if(x<=refs[i].B) {
			if(x >= refs[i].A) left += (x-refs[i].A)/refs[i].C + 1;
		}
		else left += (refs[i].B - refs[i].A)/refs[i].C + 1;
	}
	// printf("x:%lld left:%lld\n", x, left);
	return left&1;
}


void solve() {
	ll lb = 0, ub = numeric_limits<ll>::max();
	// printf("lb:%lld ub:%lld\n", lb, ub);

	while(ub - lb > 1) {
		ll mid = (ub + lb) >> 1;
		if(C(mid)) ub = mid; // (lb, ub]
		else lb = mid;
	}
	int cnt = 0;
	for(int i=0; i<refs.size(); ++i)
		if(ub <= refs[i].B && ub >= refs[i].A)
			if((ub-refs[i].A) % refs[i].C == 0) ++cnt;
	ub==numeric_limits<ll>::max()?puts("no corruption"):printf("%lld %d\n", ub, cnt);
}

int main() {
#ifdef Oj
	freopen("3484.in", "r", stdin);
#endif
	ll A, B, C;
	char line[100];
	while(gets(line)) {
		if(line[0] == 0) {
			if(refs.size()) solve();
			refs.clear();
		}
		else {
			sscanf(line,"%lld%lld%lld",&A, &B, &C);
			refs.push_back(ref(A, B, C));
		}
	}
	if(refs.size()) solve();
	return 0;
}
