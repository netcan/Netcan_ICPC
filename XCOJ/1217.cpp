/*************************************************************************
	> File Name: 打印沙漏.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sun 07 Jun 2015 03:57:25 PM CST
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
#ifdef Oj
	 freopen("打印沙漏.in", "r", stdin);
	 freopen("打印沙漏.out", "w", stdout);
#endif
	int N;
	char c;
	while(cin >> N >> c) {
		int k = (-4+sqrt(16-8*(1-N)))/4;
		int Maxc = 2*k+1;
		int counts = 2*k*(k+2)+1;
		// printf("k=%d counts=%d maxc=%d\n", k, counts, Maxc);
		int space = 0;
		for(int dc=Maxc;dc>=1; dc-=2) {
			// for(int i=0; i<space; ++i)
				// printf(" ");
			for(int i=0; i<dc; ++i)
				printf("%c", c);
			// for(int i=0; i<space; ++i)
				// printf(" ");
			puts("");
			++space;
		}
		// printf("space=%d\n", space);
		space-=2;

		for(int dc=3; dc<=Maxc; dc+=2) {
			// for(int i=0; i<space; ++i)
				// printf(" ");
			for(int i=0; i<dc; ++i)
				printf("%c", c);
			// for(int i=0; i<space; ++i)
				// printf(" ");
			puts("");
			--space;
		}
		cout << N - counts << endl;
	}



	return 0;
}
