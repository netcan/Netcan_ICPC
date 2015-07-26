////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-08 17:01:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1051
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1664KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1051.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 08 Jun 2015 04:27:41 PM CST
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
struct Wood {
	int l, w;
	bool mark;
} wood[5005];

bool cmp(const Wood &a, const Wood &b) {
	if(a.l == b.l)
		return a.w<b.w;
	return a.l < b.l;
}

int main()
{
#ifdef Oj
	freopen("1051.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> wood[i].l >> wood[i].w;
			wood[i].mark=false;
		}
		int setup = 0;
		int pl, pw;
		sort(wood, wood+n, cmp);
		for(int i=0; i<n; ++i) {
			if(!wood[i].mark) {
				++setup;
				pl = wood[i].l;
				pw = wood[i].w;
				wood[i].mark = true;
			}
			for(int j=i+1; j<n; ++j) {
				if(!wood[j].mark && wood[j].l >= pl && wood[j].w >= pw) {
					wood[j].mark = true;
					pl = wood[j].l;
					pw = wood[j].w;
				}
			}

		}
		cout << setup << endl;


	}

	return 0;
}