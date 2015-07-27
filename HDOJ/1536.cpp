/*************************************************************************
	> File Name: 1536.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-27 Mon 20:20:29 CST
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

int S[101], g[10005]; // 题目中的步数集合S, 以及sg(t)函数值g(t)
int k, m, l, h, s_nim; // 集合大小k, 计算次数m, 堆数l, 每堆个数h, 异或和s_nim

int met(int p) { // 求sg(t)值函数met(t)
	bool mark[101] = {false}; // 标记各个sg(t)的值，为了方便求补集最小值(sg(t))
	for(int i=0; i<k; ++i) {
		int t = p - S[i];
		if(t < 0) // 小于0则退出循环，求出该层的sg(t)值
			break;
		if(g[t] == -1)
			g[t] = met(t); // 递归求sg(t)
		mark[g[t]] = true; // 标记该层的sg(t)值
	}
	for(int i=0;; ++i) // 求出该层的sg(t)值，即补集的最小值
		if(!mark[i])
			return i;
}

void solve() {
	while(cin >> k && k) {
		for(int i=0; i<k; ++i)
			cin >> S[i];
		sort(S, S+k); // 记得排序
		memset(g, -1, sizeof(g));
		cin >> m;
		while(m--) {
			s_nim = 0;
			cin >> l;
			while(l--) {
				cin >> h;
				g[h] = met(h);
				s_nim^=g[h]; // 求异或和s_nim
			}
			if(s_nim == 0)
				cout << 'L';
			else
				cout << 'W';
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
