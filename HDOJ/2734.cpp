////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-09 14:20:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2734
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2734.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/9 14:11:27
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
	static char s[256];
	int l,qs;
	while(gets(s+1) && s[1]!= '#')
	{
		l=strlen(s+1);
		qs=0;
		for(int i=1;i<=l;i++)
		{
			if(s[i]==' ')
				continue;
			qs+=i*((int)s[i]-64);
		}
		printf("%d\n",qs);
	}
	return 0;
}

