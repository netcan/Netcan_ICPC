////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-12 21:38:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2015.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/10 6:50:45
 ************************************************************************/

#include<stdio.h>
int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		int s_flag=1;
		int s=0;
		int i=1;
		int N=(n/m)*m;
//		printf("N=%d\n",N);
	if(N!=0)
	{
		for(;i<=N;i++)
		{
			s+=2*i;
			if(i%m==0)
			{
				if(s_flag)
				{
				printf("%d",s/m);
				s_flag=!s_flag;
				}
				else
				printf(" %d",s/m);
				s=0;
			}
		}
		i--;
		s=0;
//		printf("i=%d\n",i);
		if(i!=n)
		{
			i++;

			for(;i<=n;i++)
			{
				s+=2*i;
			}
			printf(" %d",s/(n-N));
		}
		printf("\n");
	}
	else
	{
		s=0;
		for(i=1;i<=n;i++)
			s+=2*i;
		printf("%d\n",s/n);
	}


	}
	return 0;
}

