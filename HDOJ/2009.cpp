////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-01 09:55:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2009.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/1 9:42:35
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
	double n,n2,r;
	int m;
	while(scanf("%lf%d",&n,&m)!=EOF)
	{
		r=0.0;
		r+=n;
		n2=n;
		for(int i=1;i<m;i++)
		{
			n2=sqrt(n2);
			r+=n2;
		}
		printf("%.2f\n",r);

	}
	return 0;
}
