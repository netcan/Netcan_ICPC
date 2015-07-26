/*************************************************************************
	> File Name: 1137.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 05 May 2015 11:47:57 CST
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
	int T;
	int a, b, c;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &a, &b, &c);
		int counts = 0;
		for(int x=1; x<=c; ++x) {
			int y = (c-a*x)*1.0/b;
			if(a*x+b*y==c && y>0) {
//				printf("(%d, %d)\n", x, y);
				++counts;
			}
		}
		printf("%d\n", counts);
	}

	return 0;
}
