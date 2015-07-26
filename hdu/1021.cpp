////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 11:37:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:9416KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1021.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 11:28:19 AM CST
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

unsigned long long F[1000005];
int main()
{
	F[0] = 7;
	F[1] = 11;
	for(int i=2; i<1000005; ++i)
		F[i] = (F[i-1]%3 + F[i-2]%3)%3;
	// for(int i=2; i<1000005; ++i)
		// cout << F[i] << " ";
	// cout << endl;
	int n;
	while(cin >> n) {
		if(F[n]%3==0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

	return 0;
}