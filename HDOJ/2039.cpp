////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-07 14:26:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2039.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/7 14:16:13
 ************************************************************************/

#include<stdio.h>
int main() {
	int M;
	scanf("%d",&M);
	while(M-->0)
	{
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a+b > c && b + c > a && a+c > b)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
