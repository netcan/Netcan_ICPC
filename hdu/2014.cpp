////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-10 15:23:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2014.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/10 15:08:50
 ************************************************************************/

#include<stdio.h>
int main() {
	int n;
	static int s[101];
	while(scanf("%d",&n)!=EOF)
	{
		int max,min;
		int zf;
		zf=0;

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			if(i==1)
			{
				max=s[1];
				min=max;
			}
			if(max < s[i])
				max=s[i];
			if(min > s[i])
				min=s[i];
			zf+=s[i];
		}
//		printf("zf=%d\n",zf);
//		printf("max=%d min=%d\n",max,min);
		printf("%.2f\n",(zf-max-min)/(n-2.0));


	}
	return 0;
}

