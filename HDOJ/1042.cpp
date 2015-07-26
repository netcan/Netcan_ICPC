////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-10 18:41:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:176392KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: bigint.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-10 Fri 17:17:06 CST
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
struct BigInt {
	const static int nlen = 4;
	const static int mod = 10000;
	short n[8925], len;  // 最多存4*1000位长度
	BigInt() {
		memset(n, 0, sizeof(n));
		len = 1;
	}
	BigInt(int num) {
		len = 0;
		while(num >0) {
			n[len++] = num%mod;
			num/=mod;
		}
	}
	BigInt(const char *s) {
		int l = strlen(s);
		len = l % nlen  == 0 ? l/nlen : l/nlen+1;
		int index = 0;
		for(int i=l-1; i>=0; i -= nlen) {
			int tmp = 0;
			int j = i-nlen+1;
			if(j<0) j = 0;
			for(int k=j; k<=i; ++k)
				tmp = tmp*10+s[k]-'0';
			n[index++] = tmp;
		}
	}
	BigInt operator+(const BigInt &b) const {
		BigInt res;
		res.len = max(len, b.len);
		for(int i=0; i<res.len; ++i) {
			res.n[i] += (i<len ? n[i]:0) + (i<b.len ? b.n[i]:0);
			res.n[i+1] += res.n[i]/mod;
			res.n[i] = res.n[i]%mod;
		}
		if(res.n[res.len] > 0) ++res.len;
		return res;
	}
	BigInt operator*(const BigInt &b) const {
		BigInt res;
		for(int i=0; i<len; ++i) {
			int up = 0;
			for(int j=0; j<b.len; ++j) {
				int tmp = n[i]*b.n[j] + up + res.n[i+j];
				res.n[i+j] = tmp%mod;
				up = tmp/mod;
			}
			if(up!=0)
				res.n[i+b.len] = up;
		}
		res.len = len+b.len;
		while(res.n[res.len-1] == 0 && res.len>1 ) --res.len;
		return res;
	}
	void show() const {
		printf("%d", n[len-1]);
		for(int i=len-2; i>=0; --i)
			printf("%04d", n[i]);
		printf("\n");
	}
};

int main()
{
#ifdef Oj
#endif
	static BigInt fac[10005];
	static bool used[10005];
	fac[0] = fac[1] = 1;
	used[0] = used[1] = true;
	int N;
	while(cin >> N) {
		if(used[N])
			fac[N].show();
		else {
			for(int i=2; i<=N; ++i) {
				if(used[i]) continue;
				else if(used[i-1]) {
					fac[i] = fac[i-1]*i;
					used[i] = true;
				}
				// printf("i=%d, N=%d\n", i, N);
			}
			fac[N].show();
		}
	}
	return 0;
}