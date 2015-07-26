////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-28 00:11:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1290
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1290.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 28 May 2015 12:08:00 AM CST
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
	int f[1002];
	f[1] = 2;
	for(int n=2; n<=1000; ++n)
		f[n] = f[n-1] + n*(n-1)/2 + 1;
	int n;
	while(cin >> n)
		cout << f[n] << endl;

	return 0;
}