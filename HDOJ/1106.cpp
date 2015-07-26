////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-24 08:57:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:416KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1106.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/24 8:09:42
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
using namespace std;

int main() {
	string s;
	vector<int> num;
	while(cin >> s) {
		int buf;
		for(int i=0;i<s.length();i++)
			if(s[i]=='5')	s[i]=' ';
		stringstream ss(s);
		while(ss >> buf)
			num.push_back(buf);
		sort(num.begin(),num.end());
		for(vector<int>::iterator it=num.begin();it!=num.end();it++)
			if(it==num.begin()) cout << *it;
			else	cout << ' ' << *it; 
		cout << endl;
		ss.str("");
		vector <int>().swap(num);
	}
	return 0;
}

