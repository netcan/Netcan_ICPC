////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-29 23:18:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1028.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-06-29 Mon 23:04:06 CST
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
const int _max = 125;

int main()
{
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	int c1[_max], c2[_max];
	int N;
	while(cin >> N && N) {
		for(int i=0; i<=N; ++i) {
			c1[i] = 1;
			c2[i] = 0;
		}
		for(int i=2; i<=N; ++i) {
			for(int j=0; j<=N; ++j)
				for(int k=0; k+j<=N; k+=i)
					c2[k+j] += c1[j];
				for(int j=0;j<=N; ++j) {
					c1[j] = c2[j];
					c2[j] = 0;
				}
		}
		cout << c1[N] << endl;
	}

	return 0;
}