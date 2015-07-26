////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 16:13:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2000.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 15:56:44
 ************************************************************************/

#include<stdio.h>
int main() {
	char a[4],c;
	a[3]=0;
	while(scanf("%s",a)!=EOF)
	{
		c=a[0];
		if(a[0]>a[1])
		{
			a[0]=a[1];
			a[1]=c;
		}
		c=a[0];
		if(a[0]>a[2])
		{
			a[0]=a[2];
			a[2]=c;
		}
		c=a[1];
		if(a[1]>a[2])
		{
			a[1]=a[2];
			a[2]=c;
		}
		printf("%c %c %c\n",a[0],a[1],a[2]);

	}
	return 0;
}
