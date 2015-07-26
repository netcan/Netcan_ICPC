////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-12 23:31:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1053
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1053.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-06-12 Fri 23:05:10 CST
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

struct node {
	int w;
	bool operator<(const node &b) const {
		return this->w > b.w;
	}
};

int main()
{
#ifdef Oj
	freopen("1053.in", "r", stdin);
#endif
	map<char, node> s;
	string str;
	while(cin >> str && str!="END") {
		for(int i=0; i<str.length(); ++i)
			++s[str[i]].w;
		priority_queue<node> que;
		for(map<char, node>::iterator i=s.begin(); i!=s.end(); ++i)
			que.push(i->second);
		int weight = 0;
		if(que.size() == 1)
			weight = que.top().w;
		while(que.size() != 1) {
			node a, b, c;
			a = que.top();
			que.pop();
			b = que.top();
			que.pop();
			c.w = a.w+b.w;
			weight += c.w;
			que.push(c);
		}
		printf("%ld %d %.1f\n", 8*str.length(), weight, 8.0*str.length()/weight);
		while(que.size())
			que.pop();
		s.clear();
	}


	return 0;
}