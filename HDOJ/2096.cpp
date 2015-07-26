////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-23 16:57:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2096.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/23 16:52:32
 ************************************************************************/

#include<stdio.h>
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",(a%100+b%100)%100);
	}
	return 0;
}
