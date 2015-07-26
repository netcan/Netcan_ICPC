////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 21:31:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1556KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1012.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 09:16:57 PM CST
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
	int n(0);
	double e(1);
	double t(1.0);
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	printf("%d %d\n", 0 ,1);
	printf("%d %d\n", 1 ,2);
	printf("%d %.1f\n", 2 ,2.5);
	for(int i=1; i<=9; ++i) {
		t *= 1.0/i;
		e+=t;
		if(i > 2) printf("%d %.9f\n", i ,e);
	}


	return 0;
}