////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-04 19:57:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2052KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1272.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-04 Sat 19:40:28 CST
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
const int _max=100000;
static int room[_max+10];
int find(int root) {
	int x = root;
	while(root!=room[root])
		root = room[root];
	while(x!=room[root]) {
		int t = room[x];
		room[x] = root;
		x = t;
	}
	return root;
}
void merge(int a, int b) {
	int fx=find(a);
	int fy=find(b);
	if(fx!=fy)
		room[fx] = fy;
}


int main()
{
#ifdef Oj
	freopen("1272.in", "r", stdin);
#endif
	int a, b;

	bool visited[_max+10];
	while(1) {
		for (int i = 1; i <= _max; ++i)
			room[i] = i;
		memset(visited, 0, sizeof(visited));

		bool flag = true;
		while(scanf("%d%d", &a, &b) && a+b) {
			if(a==-1&&b==-1)
				return 0;
			visited[a] = true;
			visited[b] = true;
			if(find(a) == find(b))
				flag = false;
			else
				merge(a, b);
		}
		int count = 0;
		int use = 0;
		for(int i=1;i<=_max; ++i) {
			if(visited[i] && room[i] == i)
				++count;
			if(visited[i] == true)
				++use;
		}
		if(use == 0 || (flag && count == 1))
			puts("Yes");
		else
			puts("No");
	}

	return 0;
}