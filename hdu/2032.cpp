////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-18 13:50:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2032.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/18 13:15:03
 ************************************************************************/

#include<stdio.h>
int main() {
	static int t[31][31];
	int n;
	while(scanf("%d",&n)==1) {
		for(int j=1;j<=n;j++)
			for(int i=1;i<=j;i++) {
				if(i==1 || i==j)	t[j][i]=1;
				else t[j][i]=t[j-1][i-1]+t[j-1][i];
				//printf("t[%d][%d]=%d\n",j,i,t[j][i]);
			}

		for(int j=1;j<=n;j++)	{
			for(int i=1;i<=j;i++) {
				if(i == 1)	printf("%d",t[j][i]);
				else		printf(" %d",t[j][i]);
			}
			puts("");
		}
		puts("");

	}

	return 0;
}
