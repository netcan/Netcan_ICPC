/*************************************************************************
	> File Name: 1212.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-05 一 15:51:02 CST
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

int n, m;
int a, b;
bool isprime[10005];

void solve() {
	bool flag = true;

	while(a != m) {
		// printf("%d %d\n", a, b);
		if(flag) {
			++a;
			if(a > n) a = 1;
			++b;
			if(isprime[b]) flag = false;
		}
		else {
			--a;
			if(a <= 0) a =n;
			++b;
			if(isprime[b]) flag = true;
		}
	}

	if(isprime[b]) cout << "duang" << endl;
	else cout << b << endl;
}

int main()
{
#ifdef Oj
	freopen("1212.in", "r", stdin);
#endif
	memset(isprime, true ,sizeof(isprime));
	isprime[1] = false;
	for(int i=2; i<=10000; ++i)
		if(isprime[i])
			for(int j=2; j*i<=10000;++j)
				isprime[i*j] = false;

	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m >> a >> b;
		solve();
	}
	return 0;
}
