////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-30 22:28:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1398.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-06-30 Tue 22:16:36 CST
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
const int _max = 300;

int main()
{
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	int cs[18];
	for(int i=1; i<=17; ++i)
		cs[i] = i*i;
	int c1[_max+1], c2[_max+1];
	int V;
	while(cin >> V&& V) {
		for(int i=0; i<=V; ++i) {
			c1[i] = 1;
			c2[i] = 0;
		}
		for(int i=2; i<=sqrt(V); ++i) {
			for(int j=0; j<=V; ++j)
				for(int k=0; k+j<=V; k+=cs[i]) {
					c2[k+j] += c1[j];
					// printf("k=%d, j=%d, cs[%d]=%d\n", k, j, i, cs[i]);
				}
			for(int j=0; j<=V; ++j) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[V] << endl;
	}


	return 0;
}