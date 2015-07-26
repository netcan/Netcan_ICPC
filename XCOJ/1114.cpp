/*************************************************************************
	> File Name: 1114.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 06 May 2015 10:07:13 CST
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
	static double f[1000000];
	const double C = 0.57721566490153286060651209;
	f[1] = 1.0;
	for(int i=2; i<1000000; ++i)
		f[i] = f[i-1] + 1.0/i;
	int n;
	while(scanf("%d", &n) == 1)
		printf("%.4f\n", n>=1000000?C+log(n+0.0):f[n]);
	return 0;
}
