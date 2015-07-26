/*************************************************************************
	> File Name: 1202.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 04 May 2015 22:38:17 CST
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
const double v = (sqrt(5)-1.0)/2.0;

int main()
{
	unsigned int n;
	while(scanf("%ud", &n)==1)
		printf("%u\n", unsigned(v*(n+1)));

	return 0;
}
