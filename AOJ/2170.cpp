/*************************************************************************
	> File Name: 2170.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-11-10 二 20:43:18 CST
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
int par[100000+5];
bool marked[100000+5];
int N, Q;

void init() {
	for(int i=1; i<=N; ++i) par[i] = i;
}

void unite(int x, int y) {
	if(x!=y) par[x] = y;
}


void solve() {
	memset(marked, 0, sizeof(marked));
	marked[1] = true;
	char op;
	int x=0;
	long long ans = 0;

	for(int i=0; i<Q; ++i) {
		cin >> op >> x;
		if(op == 'M')
			marked[x] = true;
		else {
			if(marked[x]) ans+=x;
			else {
				while(!marked[par[x]])
					x = par[x];
				ans+=par[x];
			}
		}
	}

	cout << ans << endl;
}

int main()
{
#ifdef Oj
	// freopen("2170.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int father;
	while(cin >> N >> Q) {
		init();
		if(N == Q && Q==0) break;
		for(int i=2; i<=N; ++i) {
			cin >> father;
			unite(i, father);
		}
		solve();
	}
	return 0;
}
