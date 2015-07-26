/*************************************************************************
	> File Name: 1023.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 05 May 2015 14:15:28 CST
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
	int N;
	int data[1005];
	int dp[1005];
	while(scanf("%d\n", &N) == 1) {
		for(int i=0; i<N; ++i)
			scanf("%d", data+i);
		int maxl = 0;
		for(int i=0; i<N; ++i) {
			dp[i] = 1;
			for(int j=0; j<i; ++j)
				if(data[i] > data[j]) dp[i] = max(dp[i], dp[j]+1);
			maxl = max(maxl, dp[i]);
		}
		printf("%d\n", maxl);
	}
	return 0;
}
