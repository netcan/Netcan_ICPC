/*************************************************************************
	> File Name: 1344.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 25 May 2015 03:06:07 PM CST
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

int main()
{
#ifdef Oj
//	freopen("1344.data", "r", stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		long long n, k;
		cin >> n >> k;
		long long g = n/2/k;
		long long ans = k*k*g;
		long long start = g*2*k+1;
		for(long long i=start; i<=n; ++i)
			if(i<start+k) ans -= i;
			else	ans+=i;
		cout << ans << endl;
	}


	return 0;
}
