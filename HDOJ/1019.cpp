////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 22:29:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1019.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 10:14:28 PM CST
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

int gcd(int a, int b) {
	return b==0?a:gcd(b, a%b);
}

int main()
{
	int T;
//	freopen("1019.data", "r", stdin);
	cin >> T;
	while(T--) {
		int m;
		int num;
		cin >> m;
		long long x = 1;
		for(int i=0; i<m; ++i) {
			cin >> num;
			x = x*num / gcd(x, num);
		}
		cout << x << endl;
	}

	return 0;
}