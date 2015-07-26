////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-15 00:10:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1239
////Problem Title: 
////Run result: Accept
////Run time:858MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1239.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 14 May 2015 11:20:12 PM CST
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

bool isprime[10005];
int main()
{
//	freopen("1239.data", "r", stdin);
	int m, a, b;
	memset(isprime, 1, sizeof(isprime));
	isprime[1] = 0;
	for(int i=2; i<=10000; ++i)
		if(isprime[i])
		for(int j=2; j*i<=10000; ++j)
			isprime[i*j] = false;
	// for(int i=1; i<=1000; ++i)
		// if(isprime[i])
			// cout << i << " ";

	while(cin >> m >> a >> b && a) {
		int maxw, maxh;
		int s;
		int maxs=0;
		double r;
		int N;
		if(m>10000)
			N = 10000;
		else
			N = m;
		for(int i=N; i>=1; i--) {
			if(!isprime[i])
				continue;
			for(int j=N; j>=1; --j) {
				if(!isprime[j])
					continue;
//				printf("(%d, %d)\n", i, j);
				if(i>j)
					break;
				s = i*j;
				if(s > m)
					continue;
				r = i*1.0/j*1.0;
				if(r > 1.0)
					break;
				if(r < a*1.0/b*1.0)
					continue;
				if(maxs<s) {
					maxs = s;
					maxw = i;
					maxh = j;
				}
			}
		}
		cout << maxw << " " << maxh << endl;
	}

	return 0;
}