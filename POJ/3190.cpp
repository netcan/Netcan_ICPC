/*************************************************************************
	> File Name: 3190.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-08 二 20:25:03 CST
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

struct Cow {
	int start, end, id;
	bool operator<(const Cow &b) const {
		return start < b.start;
	}
} cow[50005];

struct Stall {
	int id, end;
	bool operator <(const Stall &b) const {
		return end > b.end;
	}
	Stall() {}
	Stall(int id, int end) : id(id), end(end) {}
};

int N;
int res[50005];

void solve() {
	sort(cow, cow+N);
	// for(int i=0; i<N; ++i)
		// printf("%d %d\n", cow[i].start, cow[i].end);
	priority_queue<Stall> que;
	que.push(Stall(1, cow[0].end));
	Stall s;
	res[cow[0].id] = 1;
	for(int i=1; i<N; ++i) {
		if(cow[i].start <=que.top().end)
			s.id = que.size()+1; // 在开一间牛栏
		else {
			s.id = que.top().id; que.pop(); // 放进已有牛栏
		}
		s.end = cow[i].end;
		res[cow[i].id] = s.id;
		que.push(s);
	}
	cout << que.size() << endl;
	for(int i=0; i<N; ++i)
		cout << res[i] << endl;
}

int main()
{
#ifdef Oj
	freopen("3190.in", "r", stdin);
#endif
	scanf("%d", &N);
	for(int i=0; i<N; ++i) {
		scanf("%d%d", &cow[i].start, &cow[i].end);
		cow[i].id = i;
	}
	solve();

	return 0;
}
