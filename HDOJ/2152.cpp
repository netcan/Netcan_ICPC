////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-04 11:20:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2152
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2152.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-04 Sat 10:57:49 CST
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
struct f {
	int min, max;
} f[101];

int main()
{
#ifdef Oj
	freopen("2152.in", "r", stdin);
#endif
	int n,m;
	int c1[101], c2[101];
	while(cin >> n >> m) {
		if(n==0){
			puts("0");
			continue;
		}

		for(int i=1; i<=n; ++i)
			cin >> f[i].min >> f[i].max;
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for(int i=f[1].min; i<=f[1].max; ++i)
			c1[i] = 1;

		for(int i=2; i<=n; ++i) {
			for(int j=0; j<=m; ++j) {
				for(int k=f[i].min;(j+k<=m)&& k<=f[i].max; ++k)
					c2[j+k] += c1[j];
			}
			for(int j=0; j<=m; ++j) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		// for(int i=0; i<=m; ++i)
			// printf("c[%d]=%d, ", i, c1[i]);
		// cout << endl;
		cout << c1[m] << endl;

	}

	return 0;
}