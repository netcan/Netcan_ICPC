////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-04 23:00:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1558
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1664KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1558.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-04 Sat 22:02:28 CST
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
const int _max = 1000+10;
struct point {
	double x, y;
};
struct line {
	point s, e;
};
double s(point &a, point &b, point &c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x*a.y;
}
bool connected(point &a, point &b, point &c, point &d) {
	if(s(a, b, c)*s(a,b,d)<=0 && s(d,c,a)*s(d,c,b)<=0) return true;
	return false;
}
line line[_max];
int Set[_max];

int find(int x) {
	if(x==Set[x]) return x;
	else return Set[x] = find(Set[x]);
}
void merge(int a, int b) {
	int fx = find(a);
	int fy = find(b);
	if(fx!=fy)
		Set[fx] = fy;

}
void Q(int n) {
	for(int i=1; i<n; ++i)
		if(connected(line[i].s, line[i].e, line[n].s, line[n].e))
			merge(i, n);
}

int main()
{
#ifdef Oj
	freopen("1558.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i=1; i<=N; ++i) {
			Set[i] = i;
		}
		int lines = 0;
		for(int i=1; i<=N; ++i) {
			char cmd;
			getchar();
			scanf("%c", &cmd);
			// for(int i=1; i<=N; ++i)
				// printf("Set[%d] = %d\n", i, Set[i]);

			if(cmd == 'P') {
				++lines;
				scanf("%lf%lf%lf%lf", &line[lines].s.x, &line[lines].s.y, &line[lines].e.x, &line[lines].e.y);
				Q(lines);
				// printf("%lf %lf %lf %lf\n", line[lines].s.x, line[lines].s.y, line[lines].e.x, line[lines].e.y);
			}
			else {
				int k;
				int ans = 0;
				scanf("%d", &k);
				for(int i=1; i<=lines; ++i)
					if(find(i)==find(k))
						++ans;
				cout << ans << endl;
			}
		}

		if(T) cout << endl;
	}
	return 0;
}