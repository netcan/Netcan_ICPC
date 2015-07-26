////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-05 23:16:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1052.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 05 Jun 2015 07:50:23 PM CST
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
	 freopen("1052.in", "r", stdin);
#endif
	int n;
	vector<int> tian, king;
	while(cin >> n && n) {
		int x;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			tian.push_back(x);
		}
		for (int i = 0; i < n; ++i) {
			cin >> x;
			king.push_back(x);
		}
		sort(tian.begin(), tian.end());
		sort(king.begin(), king.end());
		int ti, tj, ki, kj;
		ti = ki = 0;
		tj = kj = n-1;
		int fee = 0;
		for (int i = n-1; i >=0; --i) {
			if(tian[tj] > king[kj]) {
				fee+=200;
				--tj, --kj;
			}
			else if(tian[tj] == king[kj]) {
				if(tian[ti] > king[ki]) {
					fee+=200;
					++ti, ++ki;
				}
				else if(tian[ti] <= king[ki]) {
					if(tian[ti] < king[kj]) {
						fee-=200;
						++ti, --kj;
					}
					else if(tian[ti] == king[kj]) {
						++ti, --kj;
					}
				}
			}
			else if(tian[tj] < king[kj]) {
				fee-=200;
				++ti, --kj;
			}
		}
		cout << fee << endl;


		tian.clear();
		king.clear();
	}

	return 0;
}