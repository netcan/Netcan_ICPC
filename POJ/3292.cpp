/*************************************************************************
	> File Name: 3292.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-18 五 20:06:58 CST
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

const int MAX_H = 1000001;
int H_number[MAX_H+1];
int Count[MAX_H];
int H;

void init() {
	memset(H_number, 0, sizeof(H_number)); // H_number[x]==0表示x是H_Prime;
	for(int i = 5; i <= MAX_H; i+=4)
		for(int j = 5; j <= MAX_H; j+=4) {
			if(i*j > MAX_H) break;
			if(H_number[i] == 0 && H_number[j] == 0)
				H_number[i*j] = 1; // 表示i*jj为H_semi_Prime
			else
				H_number[i*j] = -1; // 表示i*j为H_Composite
		}

	Count[1] = 0;
	for(int i=5; i<=MAX_H; i+=4)
		if(H_number[i] == 1) Count[i] = Count[i-4]+1;
		else Count[i] = Count[i-4];
}

void solve() {
	printf("%d %d\n", H, Count[H]);
}

int main()
{
#ifdef Oj
	freopen("3292.in", "r", stdin);
#endif
	init();
	while(cin >> H && H) {
		solve();
	}
	return 0;
}
