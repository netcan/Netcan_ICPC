/*************************************************************************
	> File Name: 1343.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 25 May 2015 01:54:44 PM CST
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

long long gcd(long long a, long long b) {
	return b==0?a:gcd(b, a%b);
}
long long lcm(long  long a, long  long b) {
	return a/gcd(a,b)*b;
}

int main()
{
#ifdef Oj
#endif
	int T;
	cin >> T;
	while(T--) {
	long long n;
	cin>> n;
		long long t = 0;
		long long i, j, k;
		j = i = k = n;
		for(i=n; i>0; --i) {
				if(i*i*i < t)
					break;
			for(j=n; j>0; --j)  {
				if(i*j*j < t)
					break;
				for(k=n; k>0; --k) {
					if(i*j*k < t)
						break;
					long long LCM =  lcm(i, lcm(j, k));
					if(t < LCM)
						t = LCM;
				}
			}
		}
		cout << t << endl;
	}


	return 0;
}
