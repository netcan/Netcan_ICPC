////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-03 21:14:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:3540KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1171.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-03 Fri 20:08:52 CST
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
const int _max = 250000;
struct fac {
	int V, M;
} fac[51];

int main()
{
#ifdef Oj
	// freopen("1171.in", "r", stdin);
#endif
	static int c1[_max], c2[_max];
	int N;
	while(cin >> N && N>0) {

		for (int i = 1; i <= N; ++i)
			cin >> fac[i].V >> fac[i].M;
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		int count = fac[1].V*fac[1].M;
		for(int i=0; i<=count; i+=fac[1].V)
			c1[i] = 1;

		for(int i=2; i<=N; ++i) {
			count += fac[i].V*fac[i].M;
			for(int j=0; j<=count; ++j)
				for(int k=0;(j+k<=count) && ( k<=fac[i].V*fac[i].M); k+=fac[i].V)
					c2[k+j] += c1[j];
			for(int j=0; j<=count; ++j) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}

		// for(int i=0; i<=count; ++i)
			// printf("c1[%d]=%d, ", i, c1[i]);
		// puts("");

		for(int i=count/2; i<=count; ++i)
			if(c1[i]) {
				printf("%d %d\n", max(i, count-i),min(i,count-i));
				break;
			}
		// for(int i=count/2; i>=0; --i) {
			// if(c1[i]) {
				// printf("%d %d\n", count-i, i);
				// break;
			// }
		// }
	}


	return 0;
}