////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-17 07:47:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2026.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/17 7:37:00
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main() {
	static char s[110];
	s[0]=' ';
	while(gets(s+1)!=NULL) {
		int len=strlen(s+1);
		for(int i=1;i<=len;i++) 
			if(s[i-1] == ' ')		printf("%c",toupper(s[i])); 
			else			printf("%c",s[i]);
		puts("");
	}
	return 0;
}
