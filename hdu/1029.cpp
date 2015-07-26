////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-24 07:23:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1029
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:1516KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1029.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/24 6:56:23
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int main() {
	int N;
	static	int n[1000000];
	while(scanf("%d",&N)==1) {
		for(int i=0;i<N;i++) 
			scanf("%d",&n[i]);
		sort(n,n+N);
//		for(int i=0;i<N;i++) 
//			printf("%d",n[i]);
				printf("%d\n",n[(N+1)/2]);
	}
	return 0;
}
