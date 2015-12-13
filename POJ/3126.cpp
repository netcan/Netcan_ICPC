/*************************************************************************
	> File Name: 3126.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-13 日 15:38:25 CST
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
bool is_prime[10000];
bool visited[10000];
string a, b;

void sieve() { // 埃式筛法
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	int n=9999;
	for(int i=2; i<=n; ++i)
		if(is_prime[i])
			for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
	return;
}

struct number {
	string num;
	int step;
	number(string num, int step): num(num), step(step) {}
};


void solve() {
	int ans = 1<<29;
	memset(visited, false, sizeof(visited));
	queue<number> que;
	que.push(number(a, 0));
	// int debug = 0;

	while(!que.empty()) {
		number p = que.front(); que.pop();
		if(p.num == b) { // 到达目标。。
			ans = p.step;
			break;
		}

		for(int i=3; i>=0; --i) { // 从个位往千位枚举
			int jbegin = i==0?1:0; // 千位的时候，从1开始枚举
			string c = p.num;
			for(int j=jbegin; j<=9; ++j) {
				c[i] = j+'0';
				int next = atoi(c.c_str()); // 下一个数字
				if(!visited[next] && is_prime[next] && c!=p.num) {
					// printf("next: %d\n", next);
					visited[atoi(c.c_str())] = true;
					que.push(number(c, p.step+1));
				}
			}
		}
	}
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("3126.in", "r", stdin);
#endif
	sieve();
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		solve();
	}
	return 0;
}
