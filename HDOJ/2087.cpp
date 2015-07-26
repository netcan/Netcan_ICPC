////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 21:18:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2087
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2087.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 20:49:33 CST
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
	string s1, s2;
	while(cin >> s1 && s1!="#"){
		cin >> s2;
		int i = 0;
		int j = 0;
		int cnt = 0;
		while(i!=s1.length()) {
			if(s1[i] != s2[j]) {
				i = i-j + 1;
				j = 0;
			}
			else {
				++i;
				++j;
			}
			if(j>=s2.length()) {
				++cnt;
				j = 0;
			}
		}
		cout << cnt << endl;


	}

	return 0;
}