////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-17 08:36:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2029
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2029.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/17 8:25:09
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
	int n;
	scanf("%d",&n);
	static char s[1000];
	while(n--) {
//		printf("n=%d\n",n);
		scanf("%s",s);
		int len=strlen(s);
		int i=0;
		for(i=0;i<=len/2;i++) 
			if(s[i]!=s[len-i-1])
				break;
//		printf("i=%d,len=%d\n",i,len);
		if(--i!=len/2)
			puts("no");
		else
			puts("yes");
	}
	return 0;
}
