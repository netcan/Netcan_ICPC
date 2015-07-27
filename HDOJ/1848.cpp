/*************************************************************************
	> File Name: 1848.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-27 Mon 21:56:16 CST
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int m, n, p;
int f[18];
int g[1005];
int met(int p) {
	bool vis[1002]={false};
	for(int i=1; i<=16; ++i) {
		int t = p - f[i];
		if(t < 0)
			break;
		if(g[t] == -1)
			g[t] = met(t);
		vis[g[t]] = true;
	}
	for(int i=0;;++i)
		if(!vis[i])
			return i;
}

void solve() {
	f[0] = 1;
	f[1] = 1;
	for(int i=2; i<=16; ++i)
		f[i] = f[i-1] + f[i-2];
	while( cin >> m >> n >> p) {
		if( m==0 && n==0 && p == 0)
			break;
		memset(g, -1, sizeof(g));
		if((met(m)^met(n)^met(p)) == 0)
			cout << "Nacci" << endl;
		else
			cout << "Fibo" << endl;
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
