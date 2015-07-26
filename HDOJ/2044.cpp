////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 16:37:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2044
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2044.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 09 May 2015 04:23:40 PM CST
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
	static long long s[55];
	s[1] = 1;
	s[2] = 2;
	for(int i=3; i<=51; ++i)
		s[i] = s[i-1] + s[i-2];

	int N;
	cin >> N;
	while(N--) {
		int a, b;
		cin >> a >> b;
		cout << s[b-a] << endl;
	}

	return 0;
}