////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-04 00:07:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1709
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1709.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-03 Fri 23:32:32 CST
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
const int _max = 100*100;

int main()
{
#ifdef Oj
	freopen("1709.in", "r", stdin);
#endif
	int c1[_max+1], c2[_max+2];
	int A[101];
	int N;
	while(cin >> N) {
		for(int i=1; i<=N; ++i)
			cin >> A[i];
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		c1[0] = 1;
		c1[A[1]] = 1;

		int count = A[1];
		for(int i=2; i<=N; ++i) {
			count+=A[i];
			for(int j=0; j<=count; ++j)
				for(int k=0;(j+k<=count) && (k<=A[i]); k+=A[i]) {
					c2[j+k] += c1[j];
					c2[abs(j-k)] += c1[j];
				}
			for(int j=0; j<=count; ++j) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}

		int no = 0;
		for(int i=0; i<=count; ++i)
			if(c1[i] == 0)
				++no;
		cout << no << endl;
		if(no) {
			bool flag=true;
			for(int i=0; i<=count; ++i) {
				if(c1[i] == 0) {
					if(flag) printf("%d", i), flag=false;
					else printf(" %d", i);
				}
			}
			puts("");
		}

	}


	return 0;
}