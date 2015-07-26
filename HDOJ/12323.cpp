////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-06 11:59:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1584KB
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

const int MAX_N = 1000+10;

int par[MAX_N];
int height[MAX_N];
void init(int n) {
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		height[i] = 0;
	}
}

int find(int x) {
	return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x!=y) {
		par[x] = y;
		// if(height[x] < height[y])
			// par[x] = y;
		// else
			// par[y] = x;
		// if(height[x] == height[y]) ++height[x];
	}
}
bool same(int x,int y) {
	return find(x) == find(y);
}

int main()
{
#ifdef Oj
    // freopen("1232.in", "r", stdin);
#endif
    int M, N;
    int x, y;
    while(scanf("%d", &N)==1 && N) {
        scanf("%d", &M);
		init(N);
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &x, &y);
            unite(x, y);
        }
        int need = 0;
        for (int i = 1; i <= N ; ++i) {
            // printf("Set[%d]=%d\n", i, Set[i]);
            if(par[i] == i)
                ++need;
        }
        printf("%d\n", need-1);
    }


    return 0;
}