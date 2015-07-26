////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-15 15:52:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2021.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/15 15:40:07
 ************************************************************************/

#include<stdio.h>
int money(int m)
{
	int zs=0;
	zs=m/100;
	m%=100;
	if(m==0)
		return zs;
	zs+=m/50;
	m%=50;
	if(m==0)
		return zs;
	zs+=m/10;
	m%=10;
	if(m==0)
		return zs;
	zs+=m/5;
	m%=5;
	if(m==0)
		return zs;
	zs+=m/2;
	m%=2;
	if(m==0)
		return zs;
	zs+=m;
	return zs;

}
int main()
{
	int n;
	while(scanf("%d",&n)==1 && n)
	{
		int zs=0;
		int m;
		for(int i=0;i<n;i++) {
			scanf("%d",&m);
			zs+=money(m);
		}
		printf("%d\n",zs);
	}
	return 0;
}

