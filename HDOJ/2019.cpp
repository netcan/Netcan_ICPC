////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-15 15:35:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2019.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/15 15:21:06
 ************************************************************************/

#include<stdio.h>
int main() {
	static int num[110];
	int m,n;
	while(scanf("%d%d",&n,&m)==2 && m+n) {
		int m_flag=1;
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		if(m<num[0])	{
			printf("%d",m);
			m_flag=!m_flag;
		}
		else printf("%d",num[0]);
		for(int i=1;i<n;i++){
			if(m>=num[i-1] && m<=num[i] && m_flag) {
				printf(" %d",m);
				m_flag=!m_flag;
			}
			printf(" %d",num[i]);
		}
		if(m_flag) {
			printf(" %d",m);
			m_flag=!m_flag;
		}
		printf("\n");
	}


	return 0;
}

