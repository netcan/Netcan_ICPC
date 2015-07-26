////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-30 23:27:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:1664KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1085.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-06-30 Tue 22:41:48 CST
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
const int _max = 9000;

int main()
{
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	static int c1[_max+1], c2[_max+1];
	int num_1, num_2, num_5;
	while(cin >> num_1 >> num_2 >> num_5 && !(num_1==0 && num_2==0 && num_5==0)) {
		for(int i=0; i<=num_1; ++i) {
			c1[i] = 1;
			c2[i] = 0;
		}
		int N = num_1 + num_2*2 + num_5*5;
		for(int i=num_1+1; i<=N+1; ++i)
			c1[i] = c2[i] = 0;


		for(int i=2; i<=3; ++i) {
			for(int j=0; j<=N; ++j) {
				int l = 0;
				for(int k=0;(k+j <= N)&& (i==2?l++<=num_2:l++<=num_5); k+=(i==2?2:5)) {
					c2[j+k] += c1[j];
					// printf("j=%d k=%d i=%d, num_2=%d, num_5=%d, c1[%d]=%d\n", j, k, i,num_2, num_5, j, c1[j]);
				}
			}
			for(int j=0; j<=N; ++j)  {
				c1[j] = c2[j];
				// printf("c1[%d]=%d\n", j, c1[j]);
				c2[j] = 0;
			}

		}
		for(int i=0; i<=N+1; ++i) {
			if(c1[i] == 0) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}