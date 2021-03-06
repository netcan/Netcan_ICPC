////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-28 08:47:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1984KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1715.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 28 May 2015 08:35:15 AM CST
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

int f[1005][100];
void sum(int n) {
	int k=0;
	for(int i=0; i<100; ++i) {
		k += f[n-1][i] + f[n-2][i];
		if(k==0)
			break;
		f[n][i] = k%10000;
		k/=10000;
	}
}

int main()
{
#ifdef Oj
#endif
	f[1][0] = 1;
	f[2][0] = 1;
	for(int n=3; n<=1000; ++n)
		sum(n);
	int N;
	while(cin >> N) {
		int n;
		for(int i=0; i<N; ++i) {
			cin >> n;
			int j;
			for(j=99; j>=0; --j)
				if(f[n][j] != 0)
					break;
			printf("%d", f[n][j--]);
			for(;j>=0; --j)
				printf("%04d", f[n][j]);
			puts("");

		}


	}

	return 0;
}