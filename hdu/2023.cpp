////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-16 16:09:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2023.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/16 15:39:07
 ************************************************************************/

#include<stdio.h>
int main() {
	int n,m;
	static int score[55][6];
	static double kmpjf[6];
	while(scanf("%d%d",&n,&m)==2)
	{
		int s=0;
		int counts=0;
		int counts_flag=1;
		for(int j=1;j<=n;j++)
			for(int i=1;i<=m;i++)
				scanf("%d",&score[j][i]);
		for(int j=1;j<=n;j++) {
			s=0;
			for(int i=1;i<=m;i++)
				s+=score[j][i];
			if(j==1)	printf("%.2f",float(s)/m);
			else	printf(" %.2f",float(s)/m);
		}
		puts("");

		for(int i=1;i<=m;i++) {
			s=0;
			for(int j=1;j<=n;j++)
				s+=score[j][i];
			kmpjf[i]=float(s)/n;
			if(i==1)	printf("%.2f",kmpjf[i]);
			else printf(" %.2f",kmpjf[i]);
		}
		puts("");
		for(int j=1;j<=n;j++) {
			counts_flag=1;
			for(int i=1;i<=m;i++)
				if(score[j][i]<kmpjf[i]) {
					counts_flag=0;
					break;
				}
			if(counts_flag) {
				++counts;
			}
		}
		printf("%d\n\n",counts);


			

	}
	return 0;
}
