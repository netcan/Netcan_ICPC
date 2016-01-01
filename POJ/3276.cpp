/*************************************************************************
	> File Name: 3276.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2016-01-01 五 14:30:29 CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
bool cow[5000+5]; // 'F'为1，’B'为0
bool f[5000+5]; // F[i]表示F[i, i+K-1]部分是否进行了反转

int calc(int K) {
	int res = 0;
	int sum = 0; // 表示第i头牛是否反转，反转了则为奇数，否则为偶数
	memset(f, false, sizeof(f));
	for(int i=0; i<=N-K; ++i) {
		if((sum + cow[i]) % 2 == 0) {
			++res;
			f[i] = true;
		}
		sum += f[i]; // 计算下一个sum
		if(i-K+1>=0) sum-=f[i-K+1];
	}
	for(int i=N-K+1; i<N; ++i) {
		if((sum + cow[i]) % 2 == 0) return -1;
		if(i-K+1>=0) sum-=f[i-K+1];
	}
	return res;
}

void solve() {
	int K=1, M = N;

	for(int k=1; k<=N; ++k) {
		int step = calc(k);
		if(step < M && step > 0) {
			M = step;
			K = k;
		}
	}
	printf("%d %d\n", K, M);
}

int main() {
#ifdef Oj
	freopen("3276.in", "r", stdin);
#endif
	cin >> N;
	char c;
	for (int i = 0; i < N; ++i) {
		cin >> c;
		cow[i] = c=='F';
	}
	solve();
	return 0;
}
