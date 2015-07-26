/*************************************************************************
    > File Name: 1019.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/5/1 16:04:35
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	int N,Q;
	int p,t;
	static int v[1000000];
	while(scanf("%d%d", &N, &Q) == 2) {
		memset(v, 0, sizeof(v));
		for(int i=0; i<N; ++i) {
			scanf("%d%d", &p, &t);
			v[t] += p;
		}
		int a,b;
		for(int i=0; i<Q; ++i) {
			scanf("%d%d", &a, &b);
			int sum=0;
			for(int j=a; j<=b; ++j)
				sum+=v[j];
			printf("%d\n", sum);
		}

	}
}

