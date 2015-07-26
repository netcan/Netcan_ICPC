////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-18 15:41:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2042
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2042.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/18 15:37:42
 ************************************************************************/

#include<stdio.h>
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int a=0;
		int sheep=3;
		scanf("%d",&a);
		for(int i=0;i<a;i++)
			sheep=(sheep-1)*2;
		printf("%d\n",sheep);
	}
	return 0;
}
