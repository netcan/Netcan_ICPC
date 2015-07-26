////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 22:20:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2034.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 21:57:54 CST
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
	int m, n;
	set<int> s1;
	set<int> s2;
	set<int> s3;
	while(cin >> n >> m && !(m==0 && n ==0)) {
		int num;
		for(int i=0; i<n; ++i) {
			cin >> num;
			s1.insert(num);
		}
		for(int i=0; i<m; ++i) {
			cin >> num;
			s2.insert(num);
		}
		set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
		bool flag = false;
		if(s3.begin() == s3.end()) {
			cout << "NULL" << endl;
			s1.clear();
			s2.clear();
			s3.clear();
			continue;
		}
		for(set<int>::iterator it = s3.begin(); it!=s3.end(); ++it)
			cout << *it << " ";
		cout << endl;
		s1.clear();
		s2.clear();
		s3.clear();
	}

	return 0;
}