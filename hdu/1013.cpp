////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 10:51:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1584KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1013.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 10:25:35 CST
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
int f(int x) {
	int sum = 0;
	while(x) {
		sum+=(x%10);
		x/=10;
	}
	return sum;
}

int main()
{
	string s;

	while(cin >> s) {
		if(s == "0")
			break;
		int num = 0;
		for(int i=0; i<s.size(); ++i)
			num+=(s[i]-'0');
		while(num>=10)
			num = f(num);
		printf("%d\n", num);
	}

	return 0;
}