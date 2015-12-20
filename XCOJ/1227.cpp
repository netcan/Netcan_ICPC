/*************************************************************************
	> File Name: D.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-20 日 14:49:05 CST
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

int N, A, B;
int K[350];
struct ele {
	int to, step;
	ele(int to, int step):to(to), step(step) {}
	bool operator<(const ele &b) const {
		return step < b.step;
	}
};

bool mark[400];

void solve() {
	memset(mark, 0, sizeof(mark));
	queue<ele> que;
	que.push(ele(A, 0));
	mark[A] = true;

	int ans = -1;
	while(!que.empty()) {
		ele t = que.front(); que.pop();
		// printf("to: %d\n", t.to);
		if(t.to <= 0 || t.to>N) continue;

		if(t.to == B) {
			ans = t.step;
			break;
		}

		for(int i=0; i<2; ++i) {
			if(i==0)  {
				int to = t.to + K[t.to];
				if(to <= N && !mark[to]) {
					que.push(ele(to, t.step+1));
					mark[to] = true;
				}
			}
			else {
				int to = t.to - K[t.to];
				if(to > 0 && !mark[to]) {
					que.push(ele(to, t.step+1));
					mark[to] = true;
				}
			}

		}
	}
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("D.in", "r", stdin);
#endif
	while(cin >> N >> A >> B) {
		for(int i=1; i<=N; ++i) cin >> K[i];
		solve();
	}
	return 0;
}
