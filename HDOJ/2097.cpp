////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-23 17:12:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2097
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2097.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/23 17:04:42
 ************************************************************************/

#include<stdio.h>
int cov(int n,int b){
	int c=0;
	while(n!=0){
		c+=n%b;
		n/=b;
	}
	return c;
}
int main() {
	int n;
	while(scanf("%d",&n)==1 && n)
	if(n>999&&n<=9999)
		if(cov(n,10)==cov(n,12) && cov(n,10)==cov(n,16) && cov(n,12)==cov(n,16))	printf("%d is a Sky Number.\n",n);
		else printf("%d is not a Sky Number.\n",n);
	else printf("%d is not a Sky Number.\n",n);
	return 0;
}
