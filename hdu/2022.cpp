////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-15 16:50:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:288KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2022.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/15 16:29:48
 ************************************************************************/

#include<stdio.h>
inline int abs(int n)
{
	return n>0?n:(-n);
}
int main() {
	int m,n;
	static int s[1001][1001];
	while(scanf("%d%d",&m,&n)==2) {
		int s_max=0;
		int s_dis=1;
		for(int j=1;j<=m;j++) {
			for(int i=1;i<=n;i++) {
				scanf("%d",&s[j][i]);
				if(s_max<abs(s[j][i-1])) s_max=abs(s[j][i-1]);
			}
			if(s_max<abs(s[j][n])) s_max=abs(s[j][n]);
		}
		for(int j=1;j<=m;j++) 
			for(int i=1;i<=n;i++){
//				printf("%d %d\n",s[j][i],abs(s[j][i]));
				if(abs(s[j][i])==s_max) {
					printf("%d %d %d\n",j,i,s[j][i]);
					s_dis=!s_dis;
					break;
				}
				if(!s_dis)
					break;
			}
//		printf("%d\n",s_max);

	}
	return 0;
}

