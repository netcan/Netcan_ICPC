////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-26 00:15:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1465
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1465.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 25 May 2015 11:37:52 PM CST
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
long long C(int n,int m) {
	return fac[n]/fac[m]/fac[n-m];
}

int main()
{
#ifdef Oj
#endif
	long long f[25];
	f[1] = 0;
	for(int n=2; n<=20; ++n) {
		f[n] = fac[n] - 1;
		for(int i=n-2; i>=1; --i)
			f[n] -= C(n, i)*f[n-i];

	}

	int n;
	while(cin >> n)
		cout << f[n] << endl;

	return 0;
}