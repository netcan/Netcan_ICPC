/*************************************************************************
	> File Name: 1002.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-26 六 19:14:13 CST
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
int T;
int n, m, K, Q;
int sumX[100005];
int sumY[100005];

int main()
{
#ifdef Oj
	freopen("1002.in", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &n, &m, &K, &Q);
		int x0, y0;
		int x1,y1,x2,y2;
		memset(sumX, 0, sizeof(sumX));
		memset(sumY, 0, sizeof(sumY));
		for(int i=0; i<K; ++i) {
			scanf("%d%d", &x0, &y0);
			sumX[x0] = 1;
			sumY[y0] = 1;
		}
		for(int i=1; i<=max(n,m); ++i) {
			sumX[i] = sumX[i] + sumX[i-1];
			sumY[i] = sumY[i] + sumY[i-1];
		}

		for(int i=1; i<=Q; ++i) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if(sumX[x2]-sumX[x1-1] == (x2-x1+1) || sumY[y2] - sumY[y1-1] == (y2-y1+1))
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
