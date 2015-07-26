////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 23:15:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2051
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2051.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 09 May 2015 11:07:34 PM CST
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
	static char bin[15];

	while(cin >> n) {
		memset(bin, -1, sizeof(bin));
		int i=14;
		while(n) {
			bin[i--] = n%2;
			n/=2;
		}
		for(int j=0; j<15; ++j)
			if(bin[j]!=-1)
				printf("%d", bin[j]);
		cout << endl;

	}

	return 0;
}