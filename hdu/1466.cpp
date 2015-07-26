////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-28 12:09:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1466
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1466.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 28 May 2015 11:50:06 AM CST
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
//	freopen(".in", "r", stdin);
#endif
	static bool dp[21][191];
	for(int i=0; i<=20; ++i)  {
		int N = i*(i-1) / 2;
		dp[i][0] = true;
		for(int r=0; r<=i; ++r)
			for(int j=0; j<=N; ++j)
				if(dp[r][j])
					dp[i][(i-r)*r+j] = true;
	}
	int n;
	while(cin >> n) {
		int N=n*(n-1)/2;
		for(int i=0; i<=N; ++i)
			if(dp[n][i]) {
				if(i!=0) {
					cout << " ";
				}
				cout << i;
			}
		cout << endl;

	}

	return 0;
}