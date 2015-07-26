////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-24 13:07:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:404KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2072.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/24 12:50:04
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
#include<sstream>
using namespace std;

int main() {
	set<string> article;
	string word;
	while(getline(cin,word)&&word[0]!='#'){
		stringstream ss(word);
		string buf;
		while(ss >> buf)
			article.insert(buf);
		cout << article.size() << endl;
		ss.str("");
		article.clear();
	}
	return 0;
}
