////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-12 21:58:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2016.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/12 21:40:40
 ************************************************************************/

#include<stdio.h>
int main() {
	int n;
	static int num[110];
	while(scanf("%d",&n)==1 && n)
	{
		int min,m_flag=0,t=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(i == 0) min=num[0];
			if(i > 0 && min > num[i-1])
			{
				min=num[i-1];
				m_flag=i-1;
			}
		}
		if(min > num[n-1]) 
		{
			min = num[n-1];
			m_flag=n-1;
		}
//		printf("min=%d m_flag=%d\n",min,m_flag);
		t=num[m_flag];
		num[m_flag]=num[0];
		num[0]=t;
		printf("%d",num[0]);
		for(int i=1;i<n;i++)
			printf(" %d",num[i]);
		printf("\n");


	}

				
				
			

	return 0;
}

