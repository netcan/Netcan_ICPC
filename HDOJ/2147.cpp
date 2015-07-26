////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-21 10:38:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2147
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2147.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-21 Tue 10:15:03 CST
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
	// freopen(".in", "r", stdin);
#endif
	int n, m;
	while(cin >> n >> m) {
		if(n == 0 && m ==0)
			break;
		if(m&1) {
			if(n&1)
				puts("What a pity!");
			else
				puts("Wonderful!");
		}
		else
			puts("Wonderful!");
	}

	return 0;
}