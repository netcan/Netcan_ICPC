////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-15 15:12:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2017
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2017.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/15 15:06:39
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main() {
	int T;
	static char s[1000];
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s);
		int count = 0;
		int l=strlen(s);
		for(int i=0;i<l;i++) 
			if(isdigit(s[i]))	++count;
		printf("%d\n",count);
	}


	return 0;
}

