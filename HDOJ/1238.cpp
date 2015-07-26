////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-14 16:41:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1238
////Problem Title: 
////Run result: Accept
////Run time:530MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1238.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015年05月14日 星期四 15时58分00秒
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

char substr1[105];
char substr2[105];
vector<string> s;
bool cmp(const string &s1, const string &s2) {
	return s1.length() < s2.length();
}
void cpystr(char *d,const char *s, int i, int j) {
	for(int k=i; k<=j; ++k)
		d[k-i] = s[k];
	d[j-i+1] = 0;
}
void rev(char *d, const char *s) {
	int l = strlen(s);
	for(int i=0; i<l; ++i)
		d[i] = s[l-i-1];
	d[l] = 0;
}

int main()
{
//	freopen("1238.data", "r", stdin);
	int T;
	cin >> T;
	while(T--) {
		s.clear();
		int counts;
		cin >> counts;
		for(int i=0; i<counts; ++i) {
			string str;
			cin >> str;
			s.push_back(str);
		}
		sort(s.begin(), s.end(), cmp);
		int maxl = 0;

		for(int i=0; i<s[0].length(); ++i)
			for(int j=i; j<s[0].length(); ++j) {
				cpystr(substr1, s[0].c_str(), i, j);
				rev(substr2, substr1);
				int cnt = 1;
				for(int k=1; k<counts; ++k) {
					if(strstr(s[k].c_str(), substr1)!=NULL || strstr(s[k].c_str(), substr2)!=NULL)
						cnt++;
				}
//				printf("cnt=%d str1=%s str2=%s\n", cnt, substr1, substr2);
				if(cnt == counts)
					maxl = max(maxl, j-i+1);
			}
		cout << maxl << endl;
	}



	return 0;
}