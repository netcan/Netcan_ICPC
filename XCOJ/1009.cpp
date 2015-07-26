/*************************************************************************
	> File Name: 1099.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 05 May 2015 21:29:24 CST
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

bool is_prime[10000005];
int ans = 0;
int a[30];
int n,t;

void DFS(int counts, int i, int sum) {
	if(counts == t && is_prime[sum]) {
		++ans;
		return;
	}
	for(int j=i; j<n; ++j) {
		DFS(counts+1, j+1, sum+a[j]);
	}
}

int main()
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[1] = false;
	for(int i=2; i<=10000000; ++i)
		if(is_prime[i])
			for(int j=2; i*j<=10000000; ++j)
				is_prime[i*j] = false;
	while(scanf("%d%d", &n, &t)==2) {
		for(int i=0; i<n; ++i)
			scanf("%d", &a[i]);
		ans = 0;
		DFS(0, 0, 0);
		printf("%d\n", ans);
	}


	return 0;
}
