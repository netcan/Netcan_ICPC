////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-01 09:37:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2007.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/1 9:24:36
 ************************************************************************/

#include<stdio.h>
int main() {
	int m,n,t;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m>n)
		{
			t=m;
			m=n;
			n=t;
		}
		int r1,r2;
		r1=0;
		r2=0;
		for(int i=m;i<=n;i++)
		{
			if(i%2==0)
				r1+=i*i;
			else
				r2+=i*i*i;
		}
		printf("%d %d\n",r1,r2);
	}
	return 0;
}
