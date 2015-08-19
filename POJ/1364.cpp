/*************************************************************************
	> File Name: 1364.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-19 三 14:35:05 CST
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

/*
题目大意:现在假设有一个这样的序列，S={a1，a2，a3，a4...ai...at}
其中ai=a*si,其实这句可以忽略不看
现在给出一个不等式，使得ai+a(i+1)+a(i+2)+...+a(i+n)<ki或者是ai+a(i+1)+a(i+2)+...+a(i+n)>ki
首先给出两个数分别代表S序列有多少个数，有多少个不等式
不等式可以这样描述
给出四个参数第一个数i可以代表序列的第几项，然后给出n，这样前面两个数就可以描述为ai+a(i+1)+...a(i+n)，即从i到n的连续和，再给出一个符号和一个ki
当符号为gt代表‘>’,符号为lt代表‘<'
那么样例可以表示
1 2 gt 0
a1+a2+a3>0
2 2 lt 2
a2+a3+a4<2
最后问你所有不等式是否都满足条件，若满足输出lamentable kingdom，不满足输出successful conspiracy，这里要注意了，不要搞反了
 */

struct edge{
	int u, v, cost;
} es[102];
int n, m;
int d[102];
bool Bellman_Ford(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j) {
			edge &e = es[j];
			d[e.v] = min(d[e.v], d[e.u] + e.cost);
		}
	for(int j=0; j<m; ++j) {
		edge &e = es[j];
		if(d[e.v] > d[e.u] + e.cost)
			return false;
	}
	return true;
}


void solve() {
	cin.sync_with_stdio(false);
	string op;
	int a,b,c;
	while(cin >> n && n) {
		cin >> m;
		for(int i=0; i<m; ++i) {
			cin >> a >> b >> op >> c;
			if(op == "gt") {
				es[i].u = a+b;
				es[i].v = a-1;
				es[i].cost = -(c+1);
			}
			else {
				es[i].u = a-1;
				es[i].v = a+b;
				es[i].cost = c-1;
			}
		}
		if(Bellman_Ford(0))
			cout << "lamentable kingdom" << endl;
		else
			cout << "successful conspiracy" << endl;

	}

}

int main()
{
#ifdef Oj
	freopen("1364.in", "r", stdin);
#endif
	solve();
	return 0;
}
