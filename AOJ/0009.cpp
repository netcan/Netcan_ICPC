/*************************************************************************
	> File Name: 0009.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-13 日 14:47:34 CST
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
int N;
bool is_prime[1000000];

void sieve() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i=2; i<=1000000; ++i)
		if(is_prime[i])
			for(int j = 2*i; j<=1000000; j+=i) is_prime[j] = false;
}

void solve() {
	int ans = 0;
	for(int i=1; i<=N; ++i) if(is_prime[i]) ++ans;
	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("0009.in", "r", stdin);
#endif
	sieve();
	while(cin >> N) {
		solve();
	}
	return 0;
}
