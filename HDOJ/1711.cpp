/*************************************************************************
	> File Name: 1711.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-17 四 19:39:56 CST
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

int N,M,T;
int a[1000005], b[10005], Next[10005];

void getNext() {
	Next[0] = -1;
	int i=0, j=-1;
	while(i!=M-1) {
		if(j == -1 || b[j] == b[i]) {
			++i;
			++j;
			Next[i] = b[i] != b[j]?j:Next[j];
		}
		else
			j = Next[j];
	}
}

void solve() {
	getNext();
	int i=0, j = 0;

	while(i!=N && j != M) {
		if(j==-1 || a[i] == b[j]) {
			++i;
			++j;
		}
		else j = Next[j];
	}

	if(j==M)
		printf("%d\n", i-j+1);
	else
		printf("-1\n");
}

int main()
{
#ifdef Oj
	freopen("1711.in", "r", stdin);
#endif
	cin >> T;
	while(T--) {
		scanf("%d%d", &N, &M);
		int x;
		for(int i=0; i<N; ++i)
			scanf("%d", &a[i]);
		for(int i=0; i<M; ++i)
			scanf("%d", &b[i]);

		// cout << a << endl;
		// cout << b << endl;
		solve();
	}
	return 0;
}
