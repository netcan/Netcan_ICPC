////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-26 10:30:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1992KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1297.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 26 May 2015 09:55:59 AM CST
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
void add(int n) {
	int k = 0;
	int j;
	for(j=1; j<=100; ++j) {
		k+=f[n-1][j] + f[n-2][j] + f[n-4][j];
		if(k==0)
			break;
		f[n][j] = k%10000;
		k/=10000;
	}
}
int main()
{
#ifdef Oj
#endif
	f[1][1] = 1;
	f[2][1] = 2;
	f[3][1] = 4;
	f[4][1] = 7;

	for(int n=5; n<=1000; ++n)
		add(n);
	int n, i;
	while(cin >> n) {
		for(i=100; i>0; --i)
			if(f[n][i]!=0) break;
		printf("%d", f[n][i]);
		for(--i; i>0; --i)
			printf("%04d", f[n][i]);
		printf("\n");

	}




	return 0;
}