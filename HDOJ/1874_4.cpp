/*************************************************************************
	> File Name: 2544_4.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-14 Fri 14:50:58 CST
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
const int INF = 0x3f3f3f3f;
int V, E; // 顶点数V, 边数E
int d[102][102];

void floyd() {
	for(int k=0; k<V; ++k)
		for(int i=0; i<V; ++i)
			for(int j=0; j<V; ++j)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	return;
}

void solve() {
	while(cin >> V >> E) {
		if(V == 0 && E==0)
			break;
		memset(d, 0x3f, sizeof(d));
		int  A, B, C;
		for(int i=0; i<E; ++i) {
			cin >> A >> B >> C;
			if(d[A][B] == INF) d[A][B] = d[B][A] = C;
			else d[A][B] = d[B][A] = min(d[A][B], C);
		}
		int s, t;
		cin >> s >> t;
		for(int i=1; i<=V;++i)
			d[i][i] = 0;
		floyd();
		if(d[s][t] == INF)
			cout << -1 << endl;
		else
			cout << d[s][t] << endl;
	}

}

int main()
{
#ifdef Oj
	freopen("1874.in", "r", stdin);
#endif
	solve();
	return 0;
}
