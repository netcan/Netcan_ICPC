/*************************************************************************
	> File Name: 1148.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 05 May 2015 23:40:16 CST
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
	int L, n;
	int l, r;
	static int h[100005];
	static int h2[100005];
	scanf("%d", &L);
	for(int i=1; i<=L; ++i)
		scanf("%d", &h[i]);
	scanf("%d", &n);
	for(int i=1; i<=L; ++i) {
		h2[i] = h[i] + h2[i-1];
//		printf("h2[%d]=%d\n", i, h2[i]);
	}




	while(n--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", h2[r]-h2[l-1]);
	}

	return 0;
}
