////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-04 12:05:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1050
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1050.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 04 Jun 2015 11:31:35 AM CST
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
	freopen("1050.in", "r", stdin);
#endif
	int T;
	cin >> T;
	int n;
	int P[401];
	while(T--) {
		cin >> n;
		int s, e;
		int maxt=0; // maxt为最大重叠房间区间数
		memset(P, 0, sizeof(P));
		for (int i = 0; i < n; ++i) {
			cin >> s >> e;
			s = (s-1)/2;
			e = (e-1)/2;
			if(s > e)
				swap(s, e);
			for (int i = s; i <= e; ++i) {
				++P[i];
				maxt = max(maxt, P[i]);
			}
		}
		cout << maxt*10 << endl;
	}

	return 0;
}