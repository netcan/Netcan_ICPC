////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-19 23:08:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:296KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2084.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/19 22:43:19
 ************************************************************************/

#include<stdio.h>
inline int max(int x,int y)
{
	return x>y?x:y;
}
int main() {
	int C;
	static int shuta[110][110];
	scanf("%d",&C);
	while(C--) {
		int N=0;
		int t;
		scanf("%d",&N);
		for(int j=1;j<=N;j++)
			for(int i=1;i<=j;i++)
				scanf("%d",&shuta[j][i]);

		for(int j=N;j>1;j--)
			for(int i=1;i<j;i++)	
			{
				shuta[j-1][i]=shuta[j-1][i] + max(shuta[j][i],shuta[j][i+1]);
		//		printf("shuta[%d][%d]=%d\n",j-1,i,shuta[j-1][i]);
			}
		printf("%d\n",shuta[1][1]);


	}
	return 0;
}
