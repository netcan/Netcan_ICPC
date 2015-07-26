////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-28 23:54:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2048
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2048.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 28 May 2015 11:39:10 PM CST
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

const long long fac[21]={1,1,2,6,24,120,720,5040,40320,362880,
                        3628800,39916800,479001600,6227020800,
                        87178291200,1307674368000,20922789888000,
                        355687428096000,6402373705728000,121645100408832000,
                        2432902008176640000};
int main()
{
#ifdef Oj
#endif
	long long D[21];
	D[1] = 0;
	D[2] = 1;
	for(int n=3; n<=20; ++n)
		D[n] = (n-1)*(D[n-1] + D[n-2]);
	int C;
	cin >>C;
	while(C--) {
		int n;
		cin >> n;
		printf("%.2f%%\n", D[n]*1.0/fac[n]*100.0);
	}


	return 0;
}