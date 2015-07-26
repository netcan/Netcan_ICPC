////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-13 11:04:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1061.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 13 May 2015 10:49:24 AM CST
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
	int T;
	cin >> T;
	unsigned int N;
	while(T--) {
		cin >> N;
			int RN[5];
			RN[0] = 1;
			int n = N%10;
			for(int i = 1; i<=4; ++i) {
				RN[i] = (RN[i-1] * n) % 10;
			}
			if(N%4 == 0) cout << RN[4];
			else		 cout << RN[N%4];
			cout << endl;
	}

	return 0;
}