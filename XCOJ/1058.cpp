/*************************************************************************
	> File Name: 1058_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 07 May 2015 18:08:21 CST
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
	static int l[1000005];
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; ++i)
			scanf("%d", &l[i]);
		int sum = 0;
		for(int i=0; i<n-1; ++i)
			sum+=min(l[i], l[i+1]);
		printf("%d\n", sum);
	}
    return 0;
}


