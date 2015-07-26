////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-13 12:10:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1597
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1597.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 13 May 2015 11:46:18 AM CST
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
	int K;
	cin >> K;
	while(K--) {
		long long N;
		cin >> N;
//		for(int N=1; N <= 1000; ++N) {
		long long layer = (long long)ceil((sqrt(8*N+1)-1)/2.0);
		long long Sn = (layer-1)*layer / 2;
		long long loc = N - Sn;
//		printf("loc=%d, Sn=%lld\n", loc, Sn);
		if(loc % 9 == 0)
			printf("9\n");
		else
			printf("%lld\n",loc%9);
//		}

	}


	return 0;
}