/*************************************************************************
	> File Name: 1003.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-12 六 19:35:11 CST
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
typedef long long ll;

// f(n, x)=x+n+1

ll N, X;
long long eular(long long n)
{
	long long ans = n;
	for(ll i = 2;i*i <= n;i++)	{ // 2333这里跪了
		if(n % i == 0)	{
			while(n % i == 0)
				n /= i;
			ans = ans/i*(i-1);
		}
		if(n < i+1) break;
	}
	if(n > 1)ans = ans/n*(n-1);
	return ans;
}

void solve() {
	// cout << eular(X+N+1) << endl;
	printf("%lld\n", eular(X+N+1));
}

int main()
{
#ifdef Oj
	freopen("1003.in", "r", stdin);
#endif
	while(scanf("%lld%lld", &N, &X) == 2) {
		solve();
	}
	return 0;
}
