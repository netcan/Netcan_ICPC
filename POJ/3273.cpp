/*************************************************************************
	> File Name: 3273.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-21 一 16:32:27 CST
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

int N, M;
int money[100005];


bool C(int x) { // 当<=x刀时最少能分成多少份，用来判断是否满足条件
	int cnt = 0;
	int sum = 0;
	for(int i=0; i<N; ++i) {
		if(money[i] > x) return false;
		sum += money[i];
		if(sum > x) {
			sum = money[i];
			++cnt;
		}
	}
	if(sum <= x) ++cnt; // 最后一份
	return cnt <= M; // cnt表示<=x刀时至少能分成的份数，所以只要<=M即可（因为可以从cnt中再分，凑成M份）
}

void solve() {
	int lb = 0, ub = 1<<30;

	// C(600);
	while(ub - lb > 1) {
		int mid = (lb + ub) >> 1;
		// printf("mid: %d\n", mid);
		if(C(mid)) ub = mid; // 半闭半开区间(lb, ub]
		else lb = mid;
	}
	printf("%d\n", ub);
}

int main()
{
#ifdef Oj
	freopen("3273.in", "r", stdin);
#endif
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; ++i) 	scanf("%d",&money[i]);
	solve();
	return 0;
}
