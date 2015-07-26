////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 16:50:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2004.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 16:42:18
 ************************************************************************/

#include<stdio.h>
int main() {
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n>=0 && n <=59)
			printf("E\n");
		else if(n>=60 && n <=69)
			printf("D\n");
		else if(n>=70 && n <=79)
			printf("C\n");
		else if(n>=80 && n <=89)
			printf("B\n");
		else if(n>=90 && n <=100)
			printf("A\n");
		else
			printf("Score is error!\n");
	}
	return 0;
}
