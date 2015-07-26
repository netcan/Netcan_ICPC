////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-09 14:05:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1064.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/9 14:00:10
 ************************************************************************/

#include<stdio.h>
int main() {
	double m,r=0;
	for(int i=1;i<=12;i++)
	{
		scanf("%lf",&m);
			r+=m;
	}
	printf("$%.2f\n",r/12.0);


	return 0;
}

