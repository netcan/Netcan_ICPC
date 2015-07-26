////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 11:53:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1017.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 11:40:50 CST
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
	int N;
	cin >> N;
	while(N--){
		int n, m;
		int cse = 0;
		while(scanf("%d%d", &n, &m)==2 && !(n==0 && m==0)) {
		int a,b,cnt=0;
		for(a=1; a<n; ++a)
			for(b=a+1; b<n; ++b) {
				if((a*a+b*b+m)%(a*b)==0)
					++cnt;
			}
		cout << "Case " << ++cse << ": " << cnt << endl;
		}
		if(N>0) cout << endl;


	}

	return 0;
}