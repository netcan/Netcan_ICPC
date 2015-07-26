////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 17:46:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2057
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2057.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 09 May 2015 04:51:47 PM CST
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

long long to_Dec(string &s) {
	int l = s.length();
	bool op;
	long long dec = 0;
	long long k = 1;
	if(s[0] == '+' || s[0] == '-')
		op = 1;
	else
		op = 0;
	for(int i=l-1; i>=op; --i) {
		if(s[i]>='A' && s[i] <= 'F')
			s[i] = s[i] - 'A' + 10;
		else
			s[i] = s[i] - '0';
	}
	for(int i=l-1; i>=op; --i) {
		dec += k*s[i];
		k*=16;
	}
	return s[0]=='-'?-dec:dec;
}

void to_Hex(long long s, char  *t) {
	for(int i=0; i<36; ++i)
		t[i] = -1;
	if(s == 0) {
		t[35] = '0';
		return;
	}

	if(s < 0) {
		t[0] = '-';
		s = -s;
	}
	for(int i=35; i>=1; --i) {
		if(s == 0)
			break;
		t[i] = s%16;
		s/=16;
	}
	 for(int i=35; i>=1; --i) {
		 if(t[i]==-1)
			 break;
		 if(t[i] >=0 && t[i] <=9)
			 t[i] += '0';
		 else if(t[i]>=10 && t[i] <=15)
			 t[i] = t[i] + 'A' - 10;
	 }



}

int main()
{
	long long n1, n2, n3;
	string s1, s2;
	char s3[36];
	while(cin >> s1 >> s2) {
		n1 = to_Dec(s1);
		n2 = to_Dec(s2);
		to_Hex(n1+n2, s3);
		// cout << n1 << " " << n2 << endl;
		to_Hex(n1+n2, s3);
		// for(int i=1; i<36; ++i) {
			// printf("%d", s3[i]);
		// }
		// cout << endl;


		if(s3[0] == '-')
			cout << '-';

		for(int i=1; i<36; ++i) {
			if(s3[i] == -1)
				continue;
			cout << s3[i];
		}
		cout << endl;


	}

	return 0;
}