////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 16:39:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2002.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 16:34:06
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
	double r;
	double pi=3.1415927;
	while(scanf("%lf",&r)!=EOF)
	{

		printf("%.3lf\n",4.0/3.0*pi*r*r*r);
	}
	return 0;
}
