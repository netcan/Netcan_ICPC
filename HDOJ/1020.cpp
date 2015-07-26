////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-13 10:45:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1648KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1020.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 13 May 2015 10:31:43 AM CST
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
	int N;
	cin >> N;
	int count[10005];
	while(N--) {
		memset(count, 0, sizeof(count));
		string s;
		cin >> s;
		if(s.length()==1) {
			cout << s << endl;
			continue;
		}
		int count = 1;
		for(int i=1; i<=s.length(); ++i) {
			if(s[i] == s[i-1])
				++count;
			else {
				if(count == 1)
					printf("%c", s[i-1]);
				else {
					printf("%d%c", count, s[i-1]);
					count = 1;
				}
			}
		}
		cout << endl;
	}

	return 0;
}