////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 15:11:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1093
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1092.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 15:02:41
 ************************************************************************/

#include<stdio.h>
int main() {
	int T,n,a,b;
	scanf("%d",&T);
	while(T-->0)
	{
		b=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			b+=a;
		}
		printf("%d\n",b);

	}
	return 0;
}

