////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-19 22:22:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2070
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2070.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/19 22:06:02
 ************************************************************************/

#include<stdio.h>
int main() {
	int n;
	__int64 num[100]={0,1};
	while(scanf("%d",&n)==1 && n!=-1) {
	for(int i=2;i<=n;i++)
		num[i]=num[i-1]+num[i-2];
		printf("%I64d\n",num[n]);

	}
	return 0;
}
