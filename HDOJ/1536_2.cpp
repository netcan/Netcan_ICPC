/*************************************************************************
	> File Name: 1536_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-28 Tue 13:44:38 CST
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

int S[105], k, m, l, h, sg[10005], s_nim;
bool vis[10005];
void get_sg(int n) {
	memset(sg, 0, sizeof(sg)); // 初始化sg
	for(int i=1; i<=n; ++i) { // 从sg[1]开始计算
		memset(vis, 0, sizeof(vis)); // 每次计算完一个值需要归零
		for(int j=0; S[j] <= i && j <k ; ++j)
			vis[sg[i-S[j]]] = true; // 标记各个后继节点的sg值
		for(int j=0; j<=n; ++j)
			if(!vis[j]) { // 找出sg补集的最小值
				sg[i] = j;
				break;
			}
	}
}

void solve() {
	while(cin >> k && k) {
		for(int i=0; i<k; ++i)
			cin >> S[i];
		sort(S, S+k); // 记得排序
		cin >> m;
		get_sg(10000); // 走法确定，sg也就确定了
		while(m--) {
			s_nim = 0;
			cin >> l;
			while(l--) {
				cin >> h;
				s_nim^=sg[h];
			}
			if(s_nim)
				cout << 'W';
			else
				cout << 'L';
		}
		cout << endl;
	}

}

int main()
{
#ifdef Oj
	freopen("1536.in", "r", stdin);
#endif
	solve();

	return 0;
}
