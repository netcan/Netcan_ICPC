////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-23 14:43:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2089
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:4164KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2089.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/19 22:25:58
 ************************************************************************/

#include<stdio.h>
int main() {
	int n,m;
	int num=0;
	static int data[1000005];
	for(int i=4;i<=1000000;i++)	{
		num=i;
		while(num!=0)	{
			if(num%10==4 || num%100==62){
				data[i]=1;
				break;
			}
			num/=10;
		}
	}
	while(scanf("%d%d",&n,&m)!=EOF && m+n) {
		int count=0;
		for(int i=n;i<=m;i++)
			if(data[i])	count++;
		printf("%d\n",m-n+1-count);
	}
	return 0;
}
