////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-04 11:14:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2037.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 04 Jun 2015 11:07:34 AM CST
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
struct Time {
	int Ts, Te;
	friend bool operator<(const Time&a, const Time&b) {
		return a.Te < b.Te;
	}
} Tm[101];

int main()
{
#ifdef Oj
	freopen("2037.in", "r", stdin);
#endif
	int n;
	while(cin >> n && n) {
		for (int i = 0; i < n; ++i)
			cin >> Tm[i].Ts >> Tm[i].Te;
		sort(Tm, Tm+n);
		int count = 1;
		int end = Tm[0].Te;
		for(int i=1; i<n; ++i) {
			if(end <= Tm[i].Ts) {
				end = Tm[i].Te;
				++count;
			}
		}
		cout << count << endl;
	}

	return 0;
}