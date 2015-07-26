////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-18 14:39:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2031.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/18 14:24:15
 ************************************************************************/

#include<stdio.h>
int main() {
	static char cov[1000];
	int N,R;
	while(scanf("%d%d",&N,&R)==2) {
		int i=1;
		cov[0]=0;
		if(N==0) {
			puts("0");
			continue;
		}
			
		if(N<0)	{
			cov[0]=1;
			N=-N;
		}
		while(N>0) {
			if(N%R < 10)
				cov[i++]=N%R+'0';
			else
				cov[i++]=N%R-10+'A';
			N/=R;
//			printf("N=%d cov[%d]=%c\n",N,i,cov[i]);
		}
		if(cov[0]==1)	printf("-");
		while(i-->1)
			printf("%c",cov[i]);
		puts("");
	}
	return 0;
}
