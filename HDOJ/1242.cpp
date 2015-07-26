////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-17 20:26:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1242
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1656KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1242_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sun 17 May 2015 20:20:30 PM CST
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

char Map[205][205];
int direct[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int N, M;
int ri, rj, ai, aj;
struct node{
	int i, j, step;
	friend bool operator<(const node &a, const node &b) {
		return a.step > b.step;
	}
};

int BFS(int ri, int rj) {
	priority_queue<node> Queue;
	node q, s;
	q.i = ri;
	q.j = rj;
	q.step = 0;
	Queue.push(q);
	while(!Queue.empty()) {
		q = Queue.top();
		Queue.pop();
		if(q.i == ai && q.j == aj)
			return q.step;
		for(int k=0; k<4; ++k) {
			s.i = q.i + direct[k][0];
			s.j = q.j + direct[k][1];
			if(Map[s.i][s.j] != '#' && s.i >=1 && s.i <=N && s.j >=1 && s.j <=M) {
				if(Map[s.i][s.j] == '.'){
					s.step = q.step + 1;
					Queue.push(s);
				}
				else if(Map[s.i][s.j] == 'x') {
					s.step = q.step + 2;
					Queue.push(s);
				}
				Map[s.i][s.j] = '#';
			}
		}
	}
	return -1;
}


int main()
{
#ifdef Oj
	freopen("1242.data", "r", stdin);
#endif
	while(cin >> N >> M) {
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=M; ++j) {
				cin >> Map[i][j];
				if(Map[i][j] == 'r') {
					ri = i;
					rj = j;
				}
				else if(Map[i][j] == 'a') {
					ai = i;
					aj = j;
				}
			}
		Map[ri][rj] = '#';
		Map[ai][aj] = '.';
		int step = BFS(ri, rj);
		if(step == -1)
			puts("Poor ANGEL has to stay in the prison all his life.");
		else
			cout << step << endl;

	}

	return 0;
}