////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-07 23:56:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1556KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1048.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 07 May 2015 23:37:15 CST
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
	char s[500];
//	freopen("1048.data", "r", stdin);
	while(gets(s)) {
		if(strcmp(s, "ENDOFINPUT") == 0)
			break;
		if(strcmp(s, "START") == 0 || strcmp(s, "END") == 0)
			continue;
		for(int i=0; i < strlen(s); ++i) {
			if(s[i] >= 'A' && s[i] <= 'Z') printf("%c", (s[i] - 'A' - 5 + 26)%26 + 'A');
			else printf("%c", s[i]);
		}
		puts("");
	}

	return 0;
}