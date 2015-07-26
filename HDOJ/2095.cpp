////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 17:51:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:655MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2095.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 17:03:13 CST
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
	int n;
	int g;
	map<int, int> gift;
	while(scanf("%d", &n) == 1 && n) {
		for(int i=0; i<n; ++i) {
			scanf("%d", &g);
			if(!gift.count(g))
				gift[g] = 1;
			else
				++gift[g];
		}
		for(map<int, int>::iterator it = gift.begin(); it!=gift.end(); ++it)
			if(it->second == 1) {
				printf("%d\n", it->first);
				gift.clear();
				break;
			}
	}

	return 0;
}