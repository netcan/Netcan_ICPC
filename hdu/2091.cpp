////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-19 17:53:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2091
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2091.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/19 17:23:40
 ************************************************************************/

#include<stdio.h>
void series(char c,int n) 
{
	if(n!=0)	printf("%c",c);
	else return;
	series(c,n-1);
}
int main() {
	char c;
	int n;
	int bflag=0;
	while(scanf("%c",&c)==1 && c!='@') {
		scanf("%d",&n);
		getchar();
		if(bflag)
			puts("");
		else bflag=1;
		if(c=='@') break;
		for(int i=1;i<=n;i++) {
			series(' ',n-i);
			if(i==1)	printf("%c",c);
			else 
				if(i==n) 
					series(c,2*n-1);
				else {
				printf("%c",c);
				series(' ',2*i-3);
				printf("%c",c);
			}
			puts("");
		}
	}
	return 0;
}
