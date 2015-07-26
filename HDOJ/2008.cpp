////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-01 09:42:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2008.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/1 9:37:19
 ************************************************************************/

#include<stdio.h>
int main() {
	int n,z,f,l;
	double num;
	while(scanf("%d",&n)!=EOF)
	{
		z=0,f=0,l=0;
		if(n==0)
			break;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&num);
			if(num>0)
				z++;
			else if(num==0)
				l++;
			else 
				f++;
		}
		printf("%d %d %d\n",f,l,z);
	}
	return 0;
}
