/*************************************************************************
	> File Name: 1848_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-27 Mon 22:18:09 CST
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
int m, n, p;
int sg[1005];
bool vis[1005];
int f[18];
void get_sg(int n) { // 打表, 从sg[1]开始算
	memset(sg, 0, sizeof(sg));
	for(int i=1; i<=n; ++i) {
		memset(vis, 0, sizeof(vis));
		for(int j=1; f[j]<=i; ++j ) {
			vis[sg[i-f[j]]] = true; // 注意是标记函数值！met运算(sg值)是函数集的补集的最小值（非负）
		}
		for(int j=0;j<=n;++j)
			if(vis[j] == false) {
				sg[i] = j;
				break;
			}
	}
}

void solve() {
	f[0] = f[1] = 1;
	for(int i=2; i<=16; ++i)
		f[i] = f[i-1] + f[i-2];
	get_sg(1000);
	while(cin >> m >> n >> p) {
		if( m == 0 && n == 0 && p == 0)
			break;
		if((sg[m]^sg[n]^sg[p]) == 0)
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
