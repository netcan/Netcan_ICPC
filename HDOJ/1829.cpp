////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-05 12:05:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1829
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1829.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-05 Sun 10:54:36 CST
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
int Set[2001];
int oppo[2001];
bool flag;

int find(int x) {
	return x==Set[x] ? x:Set[x] = find(Set[x]);
}
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(a==b) {
		flag = false;
	}
	if(oppo[a]) Set[oppo[a]] = b;
	if(oppo[b]) Set[oppo[b]] = a;
	oppo[a] = b;
	oppo[b] = a;
}

int main()
{
#ifdef Oj
	freopen("1829.in", "r", stdin);
#endif
	int T;
	cin >> T;
	int Case=0;
	while(T--) {
		int n, m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n; ++i)
			Set[i]=i, oppo[i]=0;
		flag = true;
		int a, b;
		for(int i=0; i<m; ++i) {
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
		printf("Scenario #%d:\n", ++Case);
		if(flag)
			puts("No suspicious bugs found!\n");
		else
			puts("Suspicious bugs found!\n");
	}

	return 0;
}