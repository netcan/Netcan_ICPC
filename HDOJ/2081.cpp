////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-19 17:14:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2081.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/19 17:09:15
 ************************************************************************/

#include<stdio.h>
int main() {
	static char pn[15];
	int T;
	scanf("%d\n",&T);
	while(T--) {
		scanf("%s",pn+1);
		pn[6]='6';
		printf("%s\n",pn+6);
	}
	return 0;
}
