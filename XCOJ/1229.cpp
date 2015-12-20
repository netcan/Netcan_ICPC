/*************************************************************************
	> File Name: F.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-20 日 16:22:14 CST
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

int N, M;
struct  {
	double d[4];
	int label;
	int id;
} learn[305];

struct  {
	double d[4];
	int label;
} sample[305];

struct Dist{
	double d;
	int id, label;
	bool operator<(const Dist& b) const {
		if(fabs(d-b.d) < 1e-6)
			return id < b.id;
		return d < b.d;
	}
} dist[305];

bool cmp(const Dist &a, const Dist &b) {
	return a.id < b.id;
}

void solve() {
	memset(dist, 0, sizeof(dist));
	for(int i=0; i<N; ++i) {
		dist[i].d = 0;
		dist[i].label = 0;
	}
	map<int,int> vote;

	for(int i=0; i<M; ++i) {
		for(int j=0; j<N; ++j) { // 学习样本
			dist[j].d = sqrt((sample[i].d[0]-learn[j].d[0])*(sample[i].d[0]-learn[j].d[0]) +
						(sample[i].d[1]-learn[j].d[1])*	(sample[i].d[1]-learn[j].d[1]) +
						(sample[i].d[2]-learn[j].d[2])*	(sample[i].d[2]-learn[j].d[2]) +
						(sample[i].d[3]-learn[j].d[3])*	(sample[i].d[3]-learn[j].d[3]));
			dist[j].id = learn[j].id;
			dist[j].label = learn[j].label;
		}
		sort(dist, dist+N);
		sort(dist, dist+5, cmp);
		vote.clear();
		// for(int i=0; i<6; ++i) {
			// printf("dist:%f label:%d id:%d\n", dist[i].d, dist[i].label, dist[i].id);
		// }

		for(int i=0; i<5; ++i)
			++vote[dist[i].label];
		int ans;
		int times = 0;
		for(map<int, int>::iterator i=vote.begin(); i!=vote.end(); ++i) {
			if(i->second > times) {
				ans = i->first;
				times = i->second;
			}
		}
		cout << ans << endl;
	}

}

int main()
{
#ifdef Oj
	freopen("F.in", "r", stdin);
#endif
	while(cin >> N >> M) {
		for(int i=0; i<N; ++i) {
			for(int j=0; j<4; ++j) cin >> learn[i].d[j];
			learn[i].id = i;
			cin >> learn[i].label;
		}
		for(int i=0; i<M; ++i)
			for(int j=0; j<4; ++j) cin >> sample[i].d[j];
		solve();
	}
	return 0;
}
