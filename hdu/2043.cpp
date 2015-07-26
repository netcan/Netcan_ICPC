////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 11:46:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2043.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: sat 09 May 2015 11:37:58 CsT
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
	string s;
	int T;
	cin >> T;
	static bool k[4];
	while(T--) {
		memset(k, 0, sizeof(k));
		cin >> s;
		if(s.length() <8 || s.length()>16) {
			cout << "NO" << endl;
			continue;
		}
		for(int i=s.length()-1; i>=0; --i) {
			if(k[0]+k[1]+k[2]+k[3] >= 3)
				break;
			if(s[i] >= 'A' && s[i] <= 'Z')
				k[0] = true;
			else if(s[i] >= 'a' && s[i] <= 'z')
				k[1] = true;
			else if(s[i] >= '0' && s[i] <= '9')
				k[2] = true;
			else k[3] = true;
		}
			if(k[0]+k[1]+k[2]+k[3] >= 3)
				cout << "YES" << endl;
			else
				cout << "NO"  << endl;
	}


	return 0;
}