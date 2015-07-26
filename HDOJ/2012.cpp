////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-10 08:07:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2012.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/10 7:35:36
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int sushu(int n)
{
	int n2=sqrt(n);
	for(int i=2;i<=n2;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main() {
	int x,y,n,s;
	while(scanf("%d%d",&x,&y)!=EOF )
	{
		if(x==0 && y==0)
			break;
		s=0;
		for(int i=x;i<=y;i++)
		{
			n=i*i+i+41;
			if(sushu(n))
				s++;
		}
			if(s==(y-x+1))
				printf("OK\n");
			else 
				printf("Sorry\n");

	}
	return 0;
}

