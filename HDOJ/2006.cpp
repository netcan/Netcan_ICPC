////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 22:58:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2006.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 20:04:35
 ************************************************************************/

#include<stdio.h>
int main() {
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int num,r;
		r=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num);
			if(num%2==1)
				r*=num;

		}
		printf("%d\n",r);


	}
	return 0;
}
