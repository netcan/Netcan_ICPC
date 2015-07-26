////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-21 20:52:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1548
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1548.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 21 May 2015 08:29:00 PM CST
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

short N, A, B;
short k[205];
struct layer {
	short l, step;
	layer(short l=1, short step=0): l(l), step(step) {}
};
bool visited[205];

int BFS() {
	queue<layer> que;
	que.push(layer(A, 0));
	while(que.size()) {
		layer p = que.front();
		que.pop();
		if(p.l == B)
			return p.step;
		for(char i=0; i<2; ++i) {
			int nl;
			if(i == 0)
				 nl = p.l + k[p.l];
			else
				 nl = p.l - k[p.l];
			if(nl >=1 && nl<=N && !visited[nl]) {
				visited[nl] = true;
				que.push(layer(nl, p.step+1));
			}
		}
	}
	return -1;
}

int main()
{
#ifdef Oj
	freopen("1548.data", "r", stdin);
#endif
	while(cin >> N && N) {
		cin >> A >> B;
		for(int i=1; i<=N; ++i)
			cin >> k[i];
		memset(visited, 0, sizeof(visited));
		cout << BFS() << endl;
	}
	return 0;
}