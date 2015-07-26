////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 18:27:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2092
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2092.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 18:17:48 CST
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
	int m, n;
	int x1, x2;
	while(cin >> n >> m&&!(m==0&&n==0)) {
		int delta = n*n-4*m;
//		printf("%d\n", delta);
		if(delta < 0) {
			puts("No");
			continue;
		}
		if(delta == 0) {
			x1 = n/2;
			if(x1*x1-n*x1+m == 0) {
				puts("Yes");
				continue;
			}
		}
		if(delta > 0) {
			x1 = (n+sqrt(delta))/2;
			x2 = (n-sqrt(delta))/2;
			if(x1*x1-n*x1+m == 0 || x2*x2-n*x2+m == 0) {
				puts("Yes");
				continue;
			}
			else {
				puts("No");
				continue;
			}
		}

	}

	return 0;
}