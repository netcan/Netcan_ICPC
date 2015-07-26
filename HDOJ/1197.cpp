////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-09 15:23:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1197
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1197.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/9 15:14:33
 ************************************************************************/

#include<stdio.h>
int sum(int a,int b)
{
	int sum=0;
	while(a)
	{
		sum+=a%b;
		a/=b;
	}
	return sum;
}
int main() {
	for(int i=2992;i<10000;i++)
		if(sum(i,10)==sum(i,12)&&sum(i,10)==sum(i,16))
			printf("%d\n",i);
	return 0;
}

