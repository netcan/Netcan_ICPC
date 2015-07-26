////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-04 15:40:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1232.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-04 Sat 15:12:18 CST
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

int Set[1000+10];
int find(int x) {
	int root = x;
	while(root != Set[root])
		root = Set[root];
	while(x!=root) {
		int  t = Set[x];
		Set[x] = Set[root];
		x = t;
	}
	return root;
}
void merge(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy)
		Set[fx] = fy;
}

int main()
{
#ifdef Oj
	freopen("1232.in", "r", stdin);
#endif
	int M, N;
	int x, y;
	while(scanf("%d", &N)==1 && N) {
		scanf("%d", &M);
		for(int i=1; i<=N; ++i)
			Set[i] = i;
		for (int i = 0; i < M; ++i) {
			scanf("%d%d", &x, &y);
			merge(x, y);
		}
		int need = 0;
		for (int i = 1; i <= N ; ++i) {
			// printf("Set[%d]=%d\n", i, Set[i]);
			if(Set[i] == i)
				++need;
		}
		printf("%d\n", need-1);
	}


	return 0;
}