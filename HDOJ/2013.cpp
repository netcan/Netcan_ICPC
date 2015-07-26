////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-10 15:07:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2013.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/10 14:53:24
 ************************************************************************/

#include<stdio.h>
int main() {
	int n,r;
	while(scanf("%d",&n)!=EOF)
	{
		r=1;
		for(int i=1;i<n;i++)
			r=(r+1)*2;
		printf("%d\n",r);
	}
	return 0;
}

