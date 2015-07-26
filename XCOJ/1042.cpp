/*************************************************************************
	> File Name: 1042.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 05 May 2015 23:06:00 CST
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
	long long int N, M, V, K;
//	freopen("1042.data", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld%lld", &N, &M, &V, &K);
		long long int counts = 0;
		while(M<N) {
			if(M<=V || K<=1 || (M-V)*K <= M) {
				counts = -1;
				break;
			}
			M = (M-V)*K;
			++counts;
		}
		printf("%lld\n", counts);

	}

	return 0;
}
