////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-01 10:43:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2011
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2011.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/1 10:34:45
 ************************************************************************/

#include<stdio.h>
int main() {
	int m,n;
	double r;
	while(scanf("%d",&m)!=EOF)
	{
		for(int i=0;i<m;i++)
		{
			r=0;
			scanf("%d",&n);
			for(int j=1;j<=n;j++)
			{
				if(j%2==1)
					r+=1.0/j;
				else
					r-=1.0/j;
			}
			printf("%.2f\n",r);
		}
	}

	return 0;
}
