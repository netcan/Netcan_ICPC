/*************************************************************************
	> File Name: 3181.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-03 六 16:14:09 CST
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

const int MAX_N = 1005;
int N, K;
struct BigInt {
	const static int nlen = 4;	// 控制每个数组数字长度,默认为4,计算乘法的时候每个数组相乘也不会溢出int范
	const static int mod = 10000;	// 值为10^nlen
	short n[10], len;			// 最多存4*1000位长度,可调,short占的内存小,但是速度慢
	 BigInt() {
		memset(n, 0, sizeof(n));
		len = 1;
	} BigInt(int num) {
		len = 0;
		while (num > 0) {
			n[len++] = num % mod;
			num /= mod;
		}
	}
	BigInt(const char *s) {
		int l = strlen(s);
		len = l % nlen == 0 ? l / nlen : l / nlen + 1;
		int index = 0;
		for (int i = l - 1; i >= 0; i -= nlen) {
			int tmp = 0;
			int j = i - nlen + 1;
			if (j < 0)
				j = 0;
			for (int k = j; k <= i; ++k)
				tmp = tmp * 10 + s[k] - '0';
			n[index++] = tmp;
		}
	}
	BigInt operator+(const BigInt & b) const {	// 加法
		BigInt res;
		 res.len = max(len, b.len);
		for (int i = 0; i < res.len; ++i) {
			res.n[i] += (i < len ? n[i] : 0) + (i < b.len ? b.n[i] : 0);
			res.n[i + 1] += res.n[i] / mod;
			res.n[i] = res.n[i] % mod;
		} if (res.n[res.len] > 0)
			++res.len;
		return res;
	}
	BigInt operator*(const BigInt & b) const {	// 乘法
		BigInt res;
		for (int i = 0; i < len; ++i) {	// 类似母函数,第一个数组
			int up = 0;			// 进位
			for (int j = 0; j < b.len; ++j) {	// 第二个数组
				int tmp = n[i] * b.n[j] + up + res.n[i + j];	// 控制nlen=4是防止tmp溢出
				 res.n[i + j] = tmp % mod;
				 up = tmp / mod;
			} if (up != 0)
				 res.n[i + b.len] = up;
		}
		res.len = len + b.len;
		while (res.n[res.len - 1] == 0 && res.len > 1)
			--res.len;
		return res;
	}
	void show() const {
		printf("%d", n[len - 1]);	// 先输出最高位,后面可能需要前导0
		for (int i = len - 2; i >= 0; --i)
			printf("%04d", n[i]);	// 前导0,%04d和nlen一致
		printf("\n");
}};


BigInt c1[MAX_N], c2[MAX_N];

void solve()
{
	for (int i = 0; i <= N; ++i) {
		c1[i] = 1;
		c2[i] = 0;
	}
	for (int i = 2; i <= K; ++i) {
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k + j <= N; k += i) {
				c2[k + j] = c2[k+j] + c1[j];
			}
		}
		for (int j = 0; j <= N; ++j) {
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
	c1[N].show();
}

int main()
{
#ifdef Oj
	freopen("3181.in", "r", stdin);
#endif
	cin >> N >> K;
	solve();
	return 0;
}
