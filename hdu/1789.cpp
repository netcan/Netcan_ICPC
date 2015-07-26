////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-09 10:15:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1789.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-06-08 Mon 23:03:07 CST
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

struct hw {
	int dl, rs;
	friend bool operator<(const hw &a, const hw &b) {
		if(a.rs == b.rs)
			return a.dl <  b.dl;
		return a.rs > b.rs;
	}
}hw[1001];

int main()
{
#ifdef Oj
	freopen("1789.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> hw[i].dl;
		for (int i = 0; i < n; ++i)
			cin >> hw[i].rs;
		sort(hw, hw+n);
		// for (int i = 0; i < n; ++i)
			// cout << hw[i].dl << " ";
		// cout << endl;
		// for (int i = 0; i < n; ++i)
			// cout << hw[i].rs << " ";
		// cout << endl;



		static bool tday[1000];
		int ans = 0;
		memset(tday, 0, sizeof(tday));
		for (int i = 0; i < n; ++i) {
			int day;
			for (day=hw[i].dl; day>0; --day)
				if(!tday[day])  {
					tday[day]= true;
					break;
				}
				// printf("day=%d, ", day);
				if(day == 0)
					ans+=hw[i].rs;
		}
		cout << ans << endl;
	}

	return 0;
}