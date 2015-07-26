////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-17 22:31:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2030.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/17 22:19:34
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	static char s[1000];
	while(n--) {
		gets(s);
		int counts=0;
		int len=strlen(s);
		for(int i=0;i<len;i++) {
			if(s[i]<0)	{
				counts++;
				i++;
			}
		}
		printf("%d\n",counts);

	}
	return 0;
}
