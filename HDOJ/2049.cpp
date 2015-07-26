////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-29 12:51:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2049.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 29 May 2015 12:03:32 AM CST
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
long long C(int n, int m) {
	return fac[n]/fac[m]/fac[n-m];
}

int main()
{
#ifdef Oj
//	freopen(".in", "r", stdin);
#endif
	long long D[21][21];
	D[1][1] = 0;
	D[2][2] = 1;
	for(int i=3; i<=20; ++i)
		D[i][i] = (i-1)*(D[i-1][i-1] + D[i-2][i-2]);
	for(int n=1; n<=20; ++n)
		for(int m=1; m<n; ++m) {
			D[n][n-m] = C(n, m)*D[n-m][n-m];
		}
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		cout << D[n][m] << endl;
	}
	return 0;
}