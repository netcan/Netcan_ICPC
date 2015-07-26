////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 15:54:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2037.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 09 May 2015 03:42:34 PM CST
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

struct T {
	int s, e;
	T(int &a, int &b): s(a),e(b) {}
	bool operator < (const T &b) {
		return this->e < b.e;
	}
};

int main()
{
//	freopen("2037.data", "r", stdin);
	int n;
	while(cin >> n && n) {
		vector<T> t;
		int s, e;
		for(int i=0; i<n; ++i) {
			cin >> s >> e;
			t.push_back(T(s, e));
		}
		sort(t.begin(), t.end());
		int cnt = 1;
		int vt = t[0].e;
		for(int i=1; i<n; ++i) {
			if(vt <= t[i].s) {
				++cnt;
				vt = t[i].e;
			}
		}
		cout << cnt << endl;

	}


	return 0;
}