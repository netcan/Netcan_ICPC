/*************************************************************************
	> File Name: 1517.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-28 Tue 15:24:27 CST
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
long long int n;
map<long long, bool> vis;
map<long long, bool> mark;

bool dfs(long long x) {
	if(x >= n)
		return false;
	if(vis[x]) return mark[x];
	vis[x] = true;
	for(int i=2; i<=9; ++i)
		if(!dfs(x*i)) return mark[x] = true;
	return mark[x]=false;
}

void solve() {
	while(scanf("%lld", &n) == 1) {
		mark.clear();
		vis.clear();
		if(dfs(1)) printf("Stan wins.\n");
		else printf("Ollie wins.\n");
	}

}

int main()
{
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	solve();

	return 0;
}
