////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 19:51:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1636KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1178.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 06:03:51 PM CST
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
	double N;
	while(cin >> N && N) {
		int e;
		double ans = (N*(N+1)*(N+2))/6;

		e = log(ans) / log(10);
//		printf("a=%lf e=%d\n", ans, e);

		if(e!=0) printf("%.2fE%d\n", (double)ans*1.0/(pow(10, e)), e);
		else printf("%.2fE%d\n", ans*1.0, e);



	}


	return 0;
}