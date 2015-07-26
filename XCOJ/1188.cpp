/*************************************************************************
	> File Name: 1004_D.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 22 May 2015 09:33:44 PM CST
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

const long long fac[21]={1,1,2,6,24,120,720,5040,40320,362880,
						3628800,39916800,479001600,6227020800,
						87178291200,1307674368000,20922789888000,
						355687428096000,6402373705728000,121645100408832000,
						2432902008176640000};
bool num[21];
int data[21];
int n, m;
void f() {
	m--;
	memset(num, 0, sizeof(num));
	for(int i=0; i<n; ++i) {
		int t = m/fac[n-1-i];
//		printf("f[%d]=%lld, m=%d, t=%d, ", n-1-i, fac[n-1-i], m, t);
		int j;
		for(j=1; j<=n; ++j) {
			if(t == 0 && !num[j]) {
				num[j]  = true;
				break;
			}
			if(!num[j])
				t--;
		}
		data[i] = j;
//		printf("j=%d\n", j);
		m%=fac[n-1-i];
	}
}

int main()
{
	while(cin >> n >> m) {
		f();
		for(int i=0; i<n; ++i)
			cout << data[i] << " ";
		cout << endl;
	}

	return 0;
}

