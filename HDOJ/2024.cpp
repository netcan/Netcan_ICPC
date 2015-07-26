////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-16 17:56:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2024
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2024.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/16 17:27:43
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main() {
	int n;
	static char s[60];
	scanf("%d",&n);
	getchar();
	while(n--) {
//		printf("n=%d\n",n);
		int has_space=0;
		gets(s);
		if(!isalpha(s[0]) && s[0]!='_') {
//			puts("1");
			puts("no");
			continue;
		}
		int l=strlen(s);
		while(--l)
			if(s[l]==' ' || (!isalnum(s[l]) && s[l]!='_')) {
//				puts("2");
				puts("no");
				has_space=1;
				break;
			}
		if(!has_space)
			puts("yes");
			

	}

	return 0;
}
