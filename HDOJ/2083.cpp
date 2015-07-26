////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 21:26:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2083
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2083.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 21:23:25 CST
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
	int des[505];
	while(T--) {
		int n;
		int mind = 1<<30;
		int d = 0;
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> des[i];
		for(int i=0; i<n; ++i) {
			d = 0;
			for(int j=0; j<n; ++j) {
				d += abs(des[i]-des[j]);
			}
			mind = min(mind, d);
		}
		cout << mind << endl;
	}


	return 0;
}