////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-10 18:07:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1604KB
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
	int n[1000], len;  // 最多存4*1000位长度
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
	BigInt a, b;
	int T;
	string sa, sb;
	scanf("%d", &T);
	int Case = 0;
	while(T--) {
		cin >> sa >> sb;
		a = sa.c_str();
		b = sb.c_str();
		printf("Case %d:\n%s + %s = ", ++Case, sa.c_str(), sb.c_str());
		(a+b).show();
		if(T) cout << endl;
	}

	return 0;
}