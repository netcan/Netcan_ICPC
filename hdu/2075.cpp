////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-23 14:23:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2075
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2075.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/23 14:19:37
 ************************************************************************/

#include<stdio.h>
int main() {
	int a,b,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(a%b==0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
