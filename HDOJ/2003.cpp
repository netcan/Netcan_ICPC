////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 16:42:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2003.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 16:39:53
 ************************************************************************/

#include<stdio.h>
int main() {
	double n;
	while(scanf("%lf",&n)!=EOF)
	{
		if(n<0)
			n=-n;
		printf("%.2lf\n",n);

	}
	return 0;
}
