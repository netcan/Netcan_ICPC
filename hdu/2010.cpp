////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-01 10:34:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2010.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/1 9:57:21
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
	int m,n;
	int s;
	int r;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(n<100||m>999)
		{
			printf("no\n");
			continue;

		}
		s=0;
		for(int i=m;i<=n;i++)
		{
			if(i<10)	continue;
			if(i>999)	break;
			r=(i%10)*(i%10)*(i%10)+(i/10%10)*(i/10%10)*(i/10%10)+(i/100)*(i/100)*(i/100);
			if(i==r)
			{
				if(s!=0)
					printf(" ");
				printf("%d",i);
		
				s++;
			}
		}
		if(s==0)
			printf("no\n");
		else
			printf("\n");
	}
	return 0;
}
