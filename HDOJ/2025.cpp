////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-17 07:36:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2025
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2025.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/17 7:30:21
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
	static char s[110];
	while(scanf("%s",s) == 1) {
		int len=strlen(s);
		char max=s[0];
		for(int i=0;i<len;i++)
			if(max<s[i]) max=s[i];
		for(int i=0;i<len;i++)
			if(s[i] == max)
				printf("%c(max)",s[i]);
			else 
				printf("%c",s[i]);
		puts("");

	}
	return 0;
}
