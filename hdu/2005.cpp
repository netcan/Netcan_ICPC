////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 17:04:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2005.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 16:51:26
 ************************************************************************/

#include<stdio.h>
int main() {
	int y,m,d,D;
	static int month_r[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	static int month_p[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d",&y)!=EOF)
	{
		getchar();
		scanf("%d",&m);
		getchar();
		scanf("%d",&d);
		D=0;
		if((y%4 ==0 && y%100!=0) || y%400==0)
			for(int i=1;i<=m-1;i++)
				D+=month_r[i];
		else
			for(int i=1;i<=m-1;i++)
				D+=month_p[i];
		D+=d;
		printf("%d\n",D);


	}

	return 0;
}
