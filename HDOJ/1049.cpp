////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-13 11:33:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1049.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 13 May 2015 11:17:54 AM CST
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
	int n,u,d;
	while(cin >> n >> u >> d && n) {
		int i;
		for(i=0; i*(u-d)<n-u; ++i);
		cout << i*2 + 1 << endl;
	}

	return 0;
}