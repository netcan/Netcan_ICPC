/*************************************************************************
    > File Name: 1004.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/5/1 10:26:13
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

 
static bool prime[25];
static int ans[20];
static bool mark[20];
int n=0;
void DFS(int cur) {
//	printf("%d\n", cur);
	if(cur == n && prime[ans[0]+ans[n-1]]) {
		for(int i=0; i<n; ++i)
			printf("%d ", ans[i]);
		puts("");
		return;
	}
	else 
		for(int i=2; i<=n; ++i) {
			if(mark[i] && prime[i+ans[cur-1]]) {
				ans[cur] = i;
				mark[i] = false;
				DFS(cur+1);
				mark[i] = true;
			}
		}
}
int main() {
	for(int i=1; i<=25; ++i) {
		int m=sqrt(i);
		int j=2;
		for(j=2;j<=m;++j) 
			if(i%j==0)
				break;
		if(j>m)
			prime[i] = true;
		else
			prime[i] = false;
	}
	int Case=0;
	memset(mark, 1, sizeof(mark));
	ans[0] = 1;
//	for(int i=0; i<20; ++i)
//		ans[i] = i+1;
	while(scanf("%d", &n) == 1) {
		Case++;
		printf("Case %d:\n", Case);
		DFS(1);
	}
}

