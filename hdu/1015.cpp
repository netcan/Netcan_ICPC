////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-21 11:43:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1015.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 21 May 2015 10:33:50 AM CST
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

int t;
char s[15];
bool visited[15];
char m[6];
int len;
int p(int x, int y) {
	int a = 1;
	for(int i=0; i<y; ++i)
		a*=x;
	return y&1?a:-a;
}
bool DFS(int i, int sum) {
	if(i==6)
		return sum == t;
	for(int k=len-1; k>=0; --k) {
		if(!visited[k]) {
			visited[k] = true;
			m[i-1] = s[k] - 'A' + 1;
			if(DFS(i+1, sum+p(m[i-1], i))) return true;
			visited[k] = false;
		}
	}
	return false;
}



int main()
{
#ifdef Oj
	freopen("1015.data", "r", stdin);
#endif
	while(cin >> t >> s && t) {
		memset(visited, 0, sizeof(visited));
		len = strlen(s);
		sort(s, s+len);
		if(DFS(1, 0)) {
			for(int i=0; i<5; ++i)
				printf("%c", m[i]+'A' - 1);
			puts("");
		}
		else
			puts("no solution");
	}

	return 0;
}