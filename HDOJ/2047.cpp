////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-28 23:35:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2047.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 28 May 2015 11:23:47 PM CST
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

int main()
{
#ifdef Oj
#endif
	long long f[40];
	f[1]=3;
	f[2]=8;
	for(int n=3; n<40; ++n)
		f[n] = (f[n-1]+f[n-2])*2;
	int n;
	while(cin >> n)
		cout << f[n] << endl;

	return 0;
}